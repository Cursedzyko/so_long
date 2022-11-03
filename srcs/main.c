/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:47:32 by zyunusov          #+#    #+#             */
/*   Updated: 2022/11/03 21:00:56 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_error(char *msg, t_data *data)
{
    ft_printf("%s", msg);
    ft_free_all(data);
    exit(EXIT_FAILURE);
}

int	ft_close_window(t_data *data)
{
	ft_free_all(data);
	exit(EXIT_SUCCESS);
	return (0);
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
		data->mlx = mlx_init();
		ft_in_image(data);
		mlx_hook(data->window, 2, 1L << 0, ft_key_event, data);
		mlx_hook(data->window, 17, 1L << 2, ft_close_window, data);
		mlx_loop(data->mlx);
    }
    else
    {
        data = ft_calloc(sizeof(t_data), 1);
        ft_error("Error!\nNo map as an argument!\nTry ./so_long <name of map>.ber\n", data);
    }
}

void    ft_check_ber(char *map, t_data *data)
{
    int len;

    len = ft_strlen(map);
    if(ft_strncmp(map + len - 4, ".ber", 4))
        ft_error("Error!\nFile must be '.ber' extension!\n", data);
}

void    ft_get_map(t_data *data, char *map)
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
			{
				data->exit_count++;
				data->ex_y = i;
				data->ex_x = j;
			}	
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

void    ft_check_num_fe(t_data *data)
{
    if (data->food_count < 1 || data->exit_count != 1 || data->player_count != 1)
        ft_error("Error!\nMap must include 1P or 1C or 1E.\n", data);
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
			ft_error("Error!\nThe map must be rectangular.\n", data);
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
	data->map_y = len;
	coun = 0;
	while(data->map2[0][coun] && data->map2[len - 1][coun])
	{
		if (data->map2[0][coun] != '1' || data->map2[len - 1][coun] != '1') // all chars
			ft_error("Error!\nThe walls need to be closed\n", data);
		coun++;
	}
	ft_check_other_walls(data);
}

void	ft_check_other_walls(t_data *data)
{
	int coun;
	int len;
	
	coun = 0;
	len = data->map_x;
	while(coun < data->map_y)
	{
		if (data->map2[coun][0] != '1' || data->map2[coun][len - 1] != '1') // last and first char
			ft_error("Error!\nThe walls need to be closed\n", data);
		coun++;
	}
	data->tmp_food_count = data->food_count;
}

void	ft_check_validmap(t_data *data, int x, int y)
{
	char *p;

	p = &data->tmp_map2[y][x];
	if (*p == 'E')
		data->valid_ex = 1;
	if ( *p != '1')
	{
		if (*p == 'C')
			data->tmp_food_count--;
		*p = '.';
		if (data->tmp_map2[y][x + 1] != '1' &&
			data->tmp_map2[y][x + 1] != '.')
				ft_check_validmap(data, x + 1, y);
		if (data->tmp_map2[y][x - 1] != '1' &&
			data->tmp_map2[y][x - 1] != '.')
				ft_check_validmap(data, x - 1, y);
		if (data->tmp_map2[y - 1][x] != '1' &&
			data->tmp_map2[y - 1][x] != '.')
				ft_check_validmap(data, x, y - 1);
		if (data->tmp_map2[y + 1][x] != '1' &&
			data->tmp_map2[y + 1][x] != '.')
				ft_check_validmap(data, x, y + 1);
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
		ft_error("Error!\nThere isn't valid way to go exit!!!\n", data);
}

void	ft_in_image(t_data *data)
{
	data->player_f = mlx_xpm_file_to_image(data->mlx, PL_FE,
			&data->imgx, &data->imgy);
	data->player_b = mlx_xpm_file_to_image(data->mlx, PL_BE,
			&data->imgx, &data->imgy);
	data->player_l = mlx_xpm_file_to_image(data->mlx, PL_LE,
			&data->imgx, &data->imgy);
	data->player_r = mlx_xpm_file_to_image(data->mlx, PL_RE,
			&data->imgx, &data->imgy);
	data->bgrnd = mlx_xpm_file_to_image(data->mlx, BACKG,
			&data->imgx, &data->imgy);
	data->food = mlx_xpm_file_to_image(data->mlx, FOODS,
			&data->imgx, &data->imgy);
	data->exit = mlx_xpm_file_to_image(data->mlx, EXIT,
			&data->imgx, &data->imgy);
	data->wall = mlx_xpm_file_to_image(data->mlx, WAL,
			&data->imgx, &data->imgy);		
	data->window = mlx_new_window(data->mlx, data->map_x * 64, \
		data->map_y * 64, "so_long");
	data->curr_pos = 'F';
	ft_put_image(data);
}

void	ft_put_image(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(y < data->map_y * 64)
	{
		if (data->map2[y / 64][x / 64] != '1'
			&& data->map2[y / 64][x / 64] != '0')
			mlx_put_image_to_window(data->mlx, data->window, data->bgrnd, x, y);
		if (data->map2[y / 64][x / 64] == '1')
			mlx_put_image_to_window(data->mlx, data->window, data->wall, x, y);
		else if (data->map2[y / 64][x / 64] == '0')
			mlx_put_image_to_window(data->mlx, data->window, data->bgrnd, x, y);
		else if (data->map2[y / 64][x / 64] == 'E')
			mlx_put_image_to_window(data->mlx, data->window, data->exit, x, y);
		else if (data->map2[y / 64][x / 64] == 'C')
			mlx_put_image_to_window(data->mlx, data->window, data->food, x, y);
		else if (data->map2[y / 64][x / 64] == 'P')
			ft_put_image_player(data, x, y);
		ft_xy_oper(&x, &y, data);
	}
	ft_score(data);
}

void ft_xy_oper(int *x, int *y, t_data *data)
{
	if (*x == data->map_x * 64)
		{
			*x = -64;
			*y += 64;
		}
		*x += 64;
}

void ft_put_image_player(t_data *data, int x, int y)
{
	if (data->curr_pos == 'F')
		mlx_put_image_to_window(data->mlx, data->window, data->player_f, x, y);
	else if (data->curr_pos == 'R')
		mlx_put_image_to_window(data->mlx, data->window, data->player_r, x, y);
	else if (data->curr_pos == 'L')
		mlx_put_image_to_window(data->mlx, data->window, data->player_l, x, y);
	else if (data->curr_pos == 'B')
		mlx_put_image_to_window(data->mlx, data->window, data->player_b, x, y);
}

void	ft_score(t_data *data)
{
	data->move_count_screen = ft_itoa(data->move_count);
	mlx_string_put(data->mlx, data->window, 30, 30, 0xFFFFFF, \
	"Move: ");
	mlx_string_put(data->mlx, data->window, 65, 30, 0xFFFFFF, \
		data->move_count_screen);
	free(data->move_count_screen);
}


int ft_key_event(int key, t_data *data)
{
	if (key == 53)
	{
		ft_free_all(data);
		exit(EXIT_SUCCESS);
	}
	ft_check_up(key, data);
	ft_check_down(key, data);
	ft_check_left(key, data);
	ft_check_right(key, data);
	return (0);
}

void	ft_check_up(int key, t_data *data)
{
	if (key == 13)
	{
		if ((ft_check_mov(data, data->ply_x, data->ply_y - 1)) == 1)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_y -= 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->map2[data->ex_y][data->ex_x] = 'E';
			data->curr_pos = 'B';
			ft_render_after_move(data);
		}
		else if ((ft_check_mov(data, data->ply_x, data->ply_y - 1)) == 2)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_y -= 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->curr_pos = 'F';
			ft_render_after_move(data);
		}
		
	}
}

void	ft_check_down(int key, t_data *data)
{
	if (key == 1)
	{
		if ((ft_check_mov(data, data->ply_x, data->ply_y + 1)) == 1)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_y += 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->map2[data->ex_y][data->ex_x] = 'E';
			data->curr_pos = 'F';
			ft_render_after_move(data);
		}
		else if ((ft_check_mov(data, data->ply_x, data->ply_y + 1)) == 2)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_y += 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->curr_pos = 'F';
			ft_render_after_move(data);
		}
	}
}

void	ft_check_left(int key, t_data *data)
{
	if (key == 0)
	{
		if ((ft_check_mov(data, data->ply_x - 1, data->ply_y)) == 1)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_x -= 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->map2[data->ex_y][data->ex_x] = 'E';
			data->curr_pos = 'L';
			ft_render_after_move(data);
		}
		else if ((ft_check_mov(data, data->ply_x - 1, data->ply_y)) == 2)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_x -= 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->curr_pos = 'L';
			ft_render_after_move(data);
		}
	}
}


void	ft_check_right(int key, t_data *data)
{
	if (key == 2)
	{
		if ((ft_check_mov(data, data->ply_x + 1, data->ply_y)) == 1)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_x += 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->map2[data->ex_y][data->ex_x] = 'E';
			data->curr_pos = 'R';
			ft_render_after_move(data);
		}
		else if ((ft_check_mov(data, data->ply_x + 1, data->ply_y)) == 2)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_x += 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->curr_pos = 'R';
			ft_render_after_move(data);
		}
	}
}

int ft_check_mov(t_data *data, int x, int y)
{
	if (data->map2[y][x] != '1')
	{
		if (data->map2[y][x] == 'C')
			data->food_count--;
		else if (data->food_count == 0 && data->map2[y][x] == 'E')
		{
			ft_printf("Move: %d\nCongratulations!\n", ++(data->move_count));
			ft_free_all(data);
			exit(EXIT_SUCCESS);
		}
		else if (data->map2[y][x] == 'E' && data->food_count != 0)
			return (2);
		ft_printf("Move: %d\n", ++(data->move_count));
		return (1);
	}
	return (0);
}

void	ft_render_after_move(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	ft_put_image(data);
}