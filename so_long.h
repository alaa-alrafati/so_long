/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:43:03 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/22 14:39:19 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "mlx.h"

# define ESC    65307
# define UP     65362
# define DOWN   65364
# define RIGHT  65363
# define LEFT   65361

typedef struct s_image
{
	void	*floor;
	void	*wall;
	void	*player_right;
	void	*player_left;
	void	*player_up;
	void	*player_down;

	void	*player_right_d;
	void	*player_left_d;
	void	*player_up_d;
	void	*player_down_d;

	void	*exit;
	void	*coin;
}	t_image;

typedef struct s_game
{
	char	**map;
	void	*mlx;
	void	*mlx_window;

	int		player_x;
	int		player_y;
	int		collect_coins;
	int		total_coins;
	int		moves;

	int		player_dir;

	int		width_img;
	int		height_img;

	int		rows;
	int		cols;
	t_image	images;
}	t_game;

int		check_map_format(char *name);
char	**read_map(char *path);
int		map_check(char **map);
int		validate_path(char **map);
int		player_location(char **cpy_map, int *p_y, int *p_x);
int		count_map_items(char **map, char c);
void	free_map(char **map);
int		upload_image(t_game *game);
int		upload_image_2(t_game *game);
void	free_all(t_game *game);
void	free_image(t_game *game);
void	draw_map(t_game *game);
int		close_window(t_game *game);
int		resize_window(t_game *game);
int		handle_key(int keycode, t_game *game);
void	move_p(t_game *game, int new_y, int new_x);
void	update_player_location(t_game *game, int new_y, int new_x);

#endif
