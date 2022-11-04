/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mov_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:47:51 by zyunusov          #+#    #+#             */
/*   Updated: 2022/11/04 13:08:30 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_mov(t_data *data, int x, int y)
{
	if (data->map2[y][x] != '1')
	{
		if (data->map2[y][x] == 'C')
			data->food_count--;
		else if (data->food_count == 0 && data->map2[y][x] == 'E')
		{
			ft_printf("Move: %d\nCongratulations!\n", ++(data->move_count));
			ft_free_mlx(data);
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
