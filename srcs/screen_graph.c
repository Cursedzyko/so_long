/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:42:03 by zyunusov          #+#    #+#             */
/*   Updated: 2022/11/04 13:12:21 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map_y * 64)
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

void	ft_xy_oper(int *x, int *y, t_data *data)
{
	if (*x == data->map_x * 64)
	{
		*x = -64;
		*y += 64;
	}
	*x += 64;
}

void	ft_put_image_player(t_data *data, int x, int y)
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
