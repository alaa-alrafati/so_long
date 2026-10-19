/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:47:17 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/20 11:46:12 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	draw_tile(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_window, image, x * 64, y * 64);
}

static	void	draw_player(t_game *game, int x, int y)
{
	if (game->player_dir == UP)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->images.player_up, x * 64, y * 64);
	else if (game->player_dir == DOWN)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->images.player_down, x * 64, y * 64);
	else if (game->player_dir == RIGHT)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->images.player_right, x * 64, y * 64);
	else if (game->player_dir == LEFT)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->images.player_left, x * 64, y * 64);
}

static void	draw_player_with_exit(t_game *game, int x, int y)
{
	if (game->player_dir == UP)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->images.player_up_d, x * 64, y * 64);
	else if (game->player_dir == DOWN)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->images.player_down_d, x * 64, y * 64);
	else if (game->player_dir == RIGHT)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->images.player_right_d, x * 64, y * 64);
	else if (game->player_dir == LEFT)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->images.player_left_d, x * 64, y * 64);
}

static void	draw_character(t_game *game, char c, int x, int y)
{
	if (c == '0')
		draw_tile(game, game->images.floor, x, y);
	else if (c == '1')
		draw_tile(game, game->images.wall, x, y);
	else if (c == 'E')
	{
		draw_tile(game, game->images.floor, x, y);
		draw_tile(game, game->images.exit, x, y);
	}
	else if (c == 'C')
	{
		draw_tile(game, game->images.floor, x, y);
		draw_tile(game, game->images.coin, x, y);
	}
}

void	draw_map(t_game *game)
{
	char	c;
	int		x;
	int		y;

	y = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			c = game->map[y][x];
			if (c == '0' || c == '1' || c == 'E' || c == 'C')
				draw_character(game, c, x, y);
			if (x == game->player_x && y == game->player_y)
			{
				if (game->map[y][x] == 'E')
					draw_player_with_exit(game, x, y);
				else
					draw_player(game, x, y);
			}
			x++;
		}
		y++;
	}
}
