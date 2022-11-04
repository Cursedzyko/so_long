/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:38:46 by zyunusov          #+#    #+#             */
/*   Updated: 2022/11/04 13:07:24 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_rectan(t_data *data)
{
	int	len_line1;
	int	len_line2;
	int	i;

	i = 0;
	len_line1 = ft_strlen(data->map2[0]);
	data->map_x = len_line1;
	while (data->map2[i])
	{
		len_line2 = ft_strlen(data->map2[i]);
		if (len_line2 != len_line1)
			ft_error("Error!\nThe map must be rectangular.\n", data);
		i++;
	}	
}

void	ft_check_wall(t_data *data)
{
	int	coun;
	int	len;

	len = 0;
	coun = 0;
	while (data->map2[coun])
	{
		len++;
		coun++;
	}
	data->map_y = len;
	coun = 0;
	while (data->map2[0][coun] && data->map2[len - 1][coun])
	{
		if (data->map2[0][coun] != '1' || data->map2[len - 1][coun] != '1')
			ft_error("Error!\nThe walls need to be closed\n", data);
		coun++;
	}
	ft_check_other_walls(data);
}

void	ft_check_other_walls(t_data *data)
{
	int	coun;
	int	len;

	coun = 0;
	len = data->map_x;
	while (coun < data->map_y)
	{
		if (data->map2[coun][0] != '1' || data->map2[coun][len - 1] != '1')
			ft_error("Error!\nThe walls need to be closed\n", data);
		coun++;
	}
	data->tmp_food_count = data->food_count;
}
