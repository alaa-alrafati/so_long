/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_and_close_hook.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:55:05 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/20 11:23:04 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	free_all(game);
	exit(0);
}

int	resize_window(t_game *game)
{
	draw_map(game);
	return (0);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_window(game);
	else if (keycode == UP)
	{
		game->player_dir = UP;
		move_p(game, game->player_y - 1, game->player_x);
	}
	else if (keycode == DOWN)
	{
		game->player_dir = DOWN;
		move_p(game, game->player_y + 1, game->player_x);
	}
	else if (keycode == RIGHT)
	{
		game->player_dir = RIGHT;
		move_p(game, game->player_y, game->player_x + 1);
	}
	else if (keycode == LEFT)
	{
		game->player_dir = LEFT;
		move_p(game, game->player_y, game->player_x - 1);
	}
	return (0);
}

void	move_p(t_game *game, int new_y, int new_x)
{
	char	next_tile;

	next_tile = game->map[new_y][new_x];
	if (next_tile == '1')
		return ;
	if (next_tile == 'C')
	{
		game->collect_coins++;
		game->map[new_y][new_x] = '0';
	}
	if (next_tile == 'E')
	{
		if (game->collect_coins == game->total_coins)
		{
			write(1, "CONGRATS,YOU WIN\n", 17);
			close_window(game);
		}
	}
	update_player_location(game, new_y, new_x);
}

void	update_player_location(t_game *game, int new_y, int new_x)
{
	game->player_y = new_y;
	game->player_x = new_x;
	game->moves++;
	ft_printf("%d\n", game->moves);
	draw_map(game);
}
