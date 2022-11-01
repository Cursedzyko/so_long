/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:49:04 by zyunusov          #+#    #+#             */
/*   Updated: 2022/10/31 13:02:39 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
#include "mlx/mlx.h"


# define BACKG "./textures/background.xpm"

typedef struct s_data
{
    void    *mlx;
    void    *background;
    void    *window;
    int		imgy;
    int		imgx;
    char *map1;
    char **map2;
    char **tmp_map2;
    int food_count;
    int exit_count;
    int player_count;
    int ply_x;
    int ply_y;
    int map_x;
    int map_y;
    int tmp_food_count;
    int valid_ex;
} t_data;

void    ft_free_all(t_data *data);
void    ft_check_ber(char *map, t_data *data);
void    ft_get_map(t_data *data, char *map);
void    ft_check_map(t_data *data);
void    ft_check_num_fe(t_data *data);
void	ft_check_rectan(t_data *data);
void	ft_check_wall(t_data *data);
void	ft_check_other_walls(t_data *data);
void	ft_check_validmap(t_data *data, int x, int y);
void	ft_check_path(t_data *data);
void	ft_in_image(t_data *data);

#endif