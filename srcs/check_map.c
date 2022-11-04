/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:34:37 by zyunusov          #+#    #+#             */
/*   Updated: 2022/11/04 13:05:40 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_ber(char *map, t_data *data)
{
	int	len;

	len = ft_strlen(map);
	if (ft_strncmp(map + len - 4, ".ber", 4))
		ft_error("Error!\nFile must be '.ber' extension!\n", data);
}

void	ft_get_map(t_data *data, char *map)
{
	int		fd;
	char	*buff;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("Error!\nFile don't found!\n", data);
	buff = get_next_line(fd);
	if (!buff)
		ft_error("Error!\nFile is empty!\n", data);
	while (buff)
	{
		data->map1 = ft_strjoin(data->map1, buff);
		free(buff);
		buff = get_next_line(fd);
	}
	free(buff);
	data->map2 = ft_split(data->map1, '\n');
	data->tmp_map2 = ft_split(data->map1, '\n');
}

void	exit_count(t_data *data, int i, int j)
{
	data->exit_count++;
	data->ex_y = i;
	data->ex_x = j;
}

void	ft_check_map(t_data *data)
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
				exit_count(data, i, j);
			else if (data->map2[i][j] == 'P')
			{
				data->player_count++;
				data->ply_x = j;
				data->ply_y = i;
			}
			else if (data->map2[i][j] != '0' && data->map2[i][j] != '1')
				ft_error("Error!\nMap must include 1P or 1C or 1E.\n", data);
			j++;
		}
		i++;
	}
	ft_check_num_fe(data);
}

void	ft_check_num_fe(t_data *data)
{
	if (data->food_count < 1 || data->exit_count != 1
		|| data->player_count != 1)
		ft_error("Error!\nMap must include 1P or 1C or 1E.\n", data);
}
