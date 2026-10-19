/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:46:40 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/24 11:28:07 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	upload_image(t_game *game)
{
	game->images.floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &game->width_img, &game->height_img);
	game->images.wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &game->width_img, &game->height_img);
	game->images.exit = mlx_xpm_file_to_image(game->mlx,
			"textures/door.xpm", &game->width_img, &game->height_img);
	game->images.coin = mlx_xpm_file_to_image(game->mlx,
			"textures/coin.xpm", &game->width_img, &game->height_img);
	game->images.player_right = mlx_xpm_file_to_image(game->mlx,
			"textures/p_right.xpm", &game->width_img, &game->height_img);
	game->images.player_left = mlx_xpm_file_to_image(game->mlx,
			"textures/p_left.xpm", &game->width_img, &game->height_img);
	game->images.player_up = mlx_xpm_file_to_image(game->mlx,
			"textures/p_up.xpm", &game->width_img, &game->height_img);
	game->images.player_down = mlx_xpm_file_to_image(game->mlx,
			"textures/p_down.xpm", &game->width_img, &game->height_img);
	if (game->images.floor == NULL || game->images.wall == NULL
		|| game->images.exit == NULL || game->images.coin == NULL
		|| game->images.player_right == NULL || game->images.player_left == NULL
		|| game->images.player_up == NULL || game->images.player_down == NULL)
	{
		return (0);
	}
	return (1);
}

int	upload_image_2(t_game *game)
{
	game->images.player_right_d = mlx_xpm_file_to_image(game->mlx,
			"textures/p_right_d.xpm", &game->width_img, &game->height_img);
	game->images.player_left_d = mlx_xpm_file_to_image(game->mlx,
			"textures/p_left_d.xpm", &game->width_img, &game->height_img);
	game->images.player_up_d = mlx_xpm_file_to_image(game->mlx,
			"textures/p_up_d.xpm", &game->width_img, &game->height_img);
	game->images.player_down_d = mlx_xpm_file_to_image(game->mlx,
			"textures/p_down_d.xpm", &game->width_img, &game->height_img);
	if (game->images.player_right_d == NULL
		|| game->images.player_left_d == NULL
		|| game->images.player_up_d == NULL
		|| game->images.player_down_d == NULL)
	{
		return (0);
	}
	return (1);
}

void	free_image(t_game *game)
{
	if (game->images.floor)
		mlx_destroy_image(game->mlx, game->images.floor);
	if (game->images.wall)
		mlx_destroy_image(game->mlx, game->images.wall);
	if (game->images.exit)
		mlx_destroy_image(game->mlx, game->images.exit);
	if (game->images.coin)
		mlx_destroy_image(game->mlx, game->images.coin);
	if (game->images.player_right)
		mlx_destroy_image(game->mlx, game->images.player_right);
	if (game->images.player_left)
		mlx_destroy_image(game->mlx, game->images.player_left);
	if (game->images.player_up)
		mlx_destroy_image(game->mlx, game->images.player_up);
	if (game->images.player_down)
		mlx_destroy_image(game->mlx, game->images.player_down);
	if (game->images.player_right_d)
		mlx_destroy_image(game->mlx, game->images.player_right_d);
	if (game->images.player_left_d)
		mlx_destroy_image(game->mlx, game->images.player_left_d);
	if (game->images.player_up_d)
		mlx_destroy_image(game->mlx, game->images.player_up_d);
	if (game->images.player_down_d)
		mlx_destroy_image(game->mlx, game->images.player_down_d);
}

void	free_all(t_game *game)
{
	if (game == NULL)
		return ;
	if (game->mlx)
		free_image(game);
	if (game->mlx_window)
		mlx_destroy_window(game->mlx, game->mlx_window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game->map);
}
