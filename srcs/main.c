/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:47:32 by zyunusov          #+#    #+#             */
/*   Updated: 2022/10/31 01:56:23 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_error(char *msg, t_data *data)
{
    ft_putstr_fd(msg, 2);
    ft_free_all(data);
    exit(EXIT_FAILURE);
}

void    ft_free_all(t_data *data)
{
    int i;

    i = 0;
    if (data->map1)
		free(data->map1);
	if (data->map2)
	{
		while (data->map2[i])
		{
			free(data->map2[i]);
			i++;
		}
		free(data->map2);
	}
}


int main(int argc, char **argv)
{
    t_data *data;

    if (argc == 2)
    {
        data = ft_calloc(sizeof(t_data), 1);
        ft_check_ber(argv[1], data);
        ft_get_map(data, argv[1]);
        ft_check_map(data);
		ft_check_rectan(data);
		ft_check_wall(data);
		ft_check_validmap(data, data->ply_x, data->ply_y);
		ft_check_path(data);
    }
    else
    {
        data = ft_calloc(sizeof(t_data), 1);
        ft_error("No map as an argument!\nTry ./so_long <name of map>.ber\n", data);
    }
}

void    ft_check_ber(char *map, t_data *data)
{
    int len;

    len = ft_strlen(map);
    if(ft_strncmp(map + len - 4, ".ber", 4))
        ft_error("File must be '.ber' extension!\n", data);
}

void    ft_get_map(t_data *data, char *map)
{
	int		fd;
	char	*buff;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("File don't found!", data);
	buff = get_next_line(fd);
	if (!buff)
		ft_error("File is empty!", data);
	while (buff)
	{
		printf("buff = %s", buff);
		data->map1 = ft_strjoin(data->map1, buff);
		printf("map1 = %s", data->map1);
		free(buff);

		buff = get_next_line(fd);
	}
	free(buff);
	data->map2 = ft_split(data->map1, '\n');
	data->tmp_map2 = ft_split(data->map1, '\n');
}

void ft_check_map(t_data *data)
{
	static int	i = 0;
	static int	j = 0;

	while (data->map2[i])
	{
		j = 0;
		while (data->map2[i][j])
		{
			if (data->map2[i][j] == 'C')
				data->food_count++;
			else if (data->map2[i][j] == 'E')
				data->exit_count++;
			else if (data->map2[i][j] == 'P')
			{
				data->player_count++;
				data->ply_x = j;
				data->ply_y = i;
			}
			else if (data->map2[i][j] != '0' && data->map2[i][j] != '1')
				ft_error("Error! Map must include 1P or 1C or 1E.", data);
			j++;
		}
		i++;
	}
	ft_check_num_fe(data);
}

void    ft_check_num_fe(t_data *data)
{
    if (data->food_count < 1 || data->exit_count != 1 || data->player_count != 1)
        ft_error("Error! Map must include 1P or 1C or 1E.", data);
}

void	ft_check_rectan(t_data *data)
{
	int len_line1;
	int len_line2;
	int i;
	
	i = 0;
	len_line1 = ft_strlen(data->map2[0]);
	data->map_x = len_line1;
	while(data->map2[i])
	{
		len_line2 = ft_strlen(data->map2[i]);
		if (len_line2 != len_line1)
			ft_error("Error! The map must be rectangular.", data);
		i++;
	}	
}

void	ft_check_wall(t_data *data)
{
	int coun;
	int len;

	len = 0;
	coun = 0;
	while (data->map2[coun])
	{
		len++;
		coun++;
	}
	printf("coun = %d\n", coun);
	printf("len = %d\n", len);
	data->map_y = len;
	coun = 0;
	while(data->map2[0][coun] && data->map2[len - 1][coun])
	{
		if (data->map2[0][coun] != '1' || data->map2[len - 1][coun] != '1') // all chars
			ft_error("Error! The walls need to be closed", data);
		coun++;
	}
	ft_check_other_walls(data);
}

void	ft_check_other_walls(t_data *data)
{
	int coun;
	int len;
	
	coun = 0;
	printf("map_x = %d\n", data->map_x);
	printf("map_x = %d\n", data->map_y);
	len = data->map_x;
	while(coun < data->map_y)
	{
		if (data->map2[coun][0] != '1' || data->map2[coun][len - 1] != '1') // last and first char
			ft_error("Error! The walls need to be closed", data);
		coun++;
	}
	data->tmp_food_count = data->food_count;
}

void	ft_check_validmap(t_data *data, int x, int y)
{
	char *p;

	printf("%c\n", data->tmp_map2[y][x]);
	p = &data->tmp_map2[y][x];
	if (*p == 'E')
		data->valid_ex = 1;
	if (*p != 'E' && *p != '1')
	{
		printf("food = %d", data->tmp_food_count);
		if (*p == 'C')
			data->tmp_food_count--;
		*p = '.';
		printf("%c\n", data->tmp_map2[y][x]);
		printf("=================\n");
		if (data->tmp_map2[y][x + 1] != '1' &&
			data->tmp_map2[y][x + 1] != '.')
			{
				printf("X + 1\n");
				ft_check_validmap(data, x + 1, y);
			}
		if (data->tmp_map2[y][x - 1] != '1' &&
			data->tmp_map2[y][x - 1] != '.')
			{
				printf("X - 1\n");
				ft_check_validmap(data, x - 1, y);
			}
		if (data->tmp_map2[y - 1][x] != '1' &&
			data->tmp_map2[y - 1][x] != '.')
			{
				printf("Y - 1\n");
				ft_check_validmap(data, x, y - 1);
			}
		if (data->tmp_map2[y + 1][x] != '1' &&
			data->tmp_map2[y + 1][x] != '.')
			{
				printf("Y + 1\n");
				ft_check_validmap(data, x, y + 1);
			}
	}
}

void	ft_check_path(t_data *data)
{
	int i;

	i = 0;
	while (data->tmp_map2[i])
	{
		free(data->tmp_map2[i]);
		i++;
	}
	free(data->tmp_map2);
	if (data->tmp_food_count != 0 || data->valid_ex != 1)
		ft_error("Error! There isn't valid way to go exit!!!", data);
}