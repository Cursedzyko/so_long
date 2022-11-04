/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path_dfs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:40:30 by zyunusov          #+#    #+#             */
/*   Updated: 2022/11/04 13:09:42 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_validmap(t_data *data, int x, int y)
{
	char	*p;

	p = &data->tmp_map2[y][x];
	if (*p == 'E')
		data->valid_ex = 1;
	if (*p != '1')
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
	int	i;

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
