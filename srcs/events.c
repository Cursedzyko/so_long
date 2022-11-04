/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:43:24 by zyunusov          #+#    #+#             */
/*   Updated: 2022/11/04 13:10:48 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_key_event(int key, t_data *data)
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
