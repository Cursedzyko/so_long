/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:49:04 by zyunusov          #+#    #+#             */
/*   Updated: 2022/11/02 15:41:28 by zyunusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"


# define BACKG "./textures/background.xpm"
# define PL_FE "./textures/player_f.xpm"
# define PL_BE "./textures/player_b.xpm"
# define PL_LE "./textures/player_l.xpm"
# define PL_RE "./textures/player_r.xpm"
# define EXIT "./textures/door.xpm"
# define WAL "./textures/wall_4.xpm"
# define FOODS "./textures/food_1.xpm"


typedef struct s_data
{
    void    *mlx;
    void    *bgrnd;
    void    *window;
    void	*player_f;
	void	*player_b;
	void	*player_r;
	void	*player_l;
    void    *food;
    void    *exit;
    void    *wall;
    char *move_count_screen;
    int move_count;
    char	curr_pos;
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
void    ft_put_image(t_data *data);
void ft_put_image_player(t_data *data, int x, int y);
void ft_xy_oper(int *x, int *y, t_data *data);
void	ft_score(t_data *data);
int ft_key_event(int key, t_data *data);
void	ft_check_up(int key, t_data *data);
int ft_check_mov(t_data *data, int x, int y);
void	ft_render_after_move(t_data *data);
void	ft_check_right(int key, t_data *data);
void	ft_check_left(int key, t_data *data);
void	ft_check_down(int key, t_data *data);
#endif