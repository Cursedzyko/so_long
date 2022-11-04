/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:47:32 by zyunusov          #+#    #+#             */
/*   Updated: 2022/11/04 20:54:39 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_error(char *msg, t_data *data)
{
	ft_printf("%s", msg);
	ft_free_all(data);
	exit(EXIT_FAILURE);
}

int	ft_close_window(t_data *data)
{
	ft_free_mlx(data);
	ft_free_all(data);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_free_all(t_data *data)
{
	int	i;

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

void	ft_free_mlx(t_data *data)
{
	mlx_destroy_image(data->mlx, data->bgrnd);
	mlx_destroy_image(data->mlx, data->food);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->player_l);
	mlx_destroy_image(data->mlx, data->player_r);
	mlx_destroy_image(data->mlx, data->player_b);
	mlx_destroy_image(data->mlx, data->player_f);
	mlx_destroy_window(data->mlx, data->window);
	free(data->bgrnd);
	free(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	*data;

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
		ft_printf("Error!\nNo map as an argument!\n");
		ft_error("Try ./so_long <name of map>.ber\n", data);
	}
}
