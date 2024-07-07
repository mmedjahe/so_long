/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedjahe <mmedjahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:37:17 by mmedjahe          #+#    #+#             */
/*   Updated: 2024/07/07 21:44:11 by mmedjahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/gnl/get_next_line.h"
# include "libft/libft.h"
# include "libft/printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

# define WALL '1'
# define FLOOR '0'
# define COLLECTIBLES 'C'
# define PLAYER 'P'
# define MAP_EXIT 'E'

# define PIXEL 32

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define ESC2 33

typedef struct s_img
{
	void	*img_ptr;
	void	*player_img;
	void	*collectibles_img;
	void	*exit_img;
	void	*floor_img;
	void	*wall_img;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_img;

typedef struct s_map
{
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		flood_exit;
	int		flood_collect;
	int		collectibles;
	int		exit;
	int		spawn;
	char	**map;
	int		pixel;
	int		collectibles_left;
	int		steps;
	t_img	img;

}			t_map;

void		map_free(t_map *game);
void		is_ber(t_map *game, char *str);
void		error_exit(t_map *game, const char *str);
void		is_map_empty(t_map *game);
void		valid_msg(const char *str);
void		is_rectangle(t_map *game);
void		full_wall(t_map *game);
void		are_char_valid(t_map *game);
void		count_info(t_map *game);
void		check_info(t_map *game, int collectibles, int spawn, int exit);
void		init_map(t_map *game, char *file);
int			check_map_height(char **map);
int			check_file(t_map *game, int fd);
void		verif_all(t_map *game, char *arg);

#endif