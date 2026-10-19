/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:44:40 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/22 16:29:18 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_creat_game_window(t_game *game)
{
	game->rows = 0;
	while (game->map[game->rows] != NULL)
		game->rows++;
	game->cols = 0;
	while (game->map[0][game->cols] != '\0')
		game->cols++;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		write(2, "Error\nFailed to Initialize mlx\n", 31);
		free_map(game->map);
		exit(1);
	}
	game->mlx_window = mlx_new_window(game->mlx, game->cols * 64,
			game->rows * 64, "The Wizard");
	if (game->mlx_window == NULL)
	{
		write(2, "Error\nFailed to create window\n", 30);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free_map(game->map);
		exit(1);
	}
}

static void	all_mlx(t_game *game)
{
	int	load_img;
	int	load_img2;

	init_creat_game_window(game);
	load_img = upload_image(game);
	load_img2 = upload_image_2(game);
	if (!load_img || !load_img2)
	{
		write(2, "Error\nUpload images failed\n", 27);
		free_all(game);
		exit(1);
	}
	game->player_dir = RIGHT;
	draw_map(game);
	mlx_hook(game->mlx_window, 17, 0, close_window, game);
	mlx_key_hook(game->mlx_window, handle_key, game);
	mlx_expose_hook(game->mlx_window, resize_window, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(2, "Error\nProgram expects one argument\n", 35);
		exit(1);
	}
	if (!check_map_format(argv[1]))
		exit(1);
	game.map = read_map(argv[1]);
	if (game.map == NULL)
		exit(1);
	if (!player_location(game.map, &game.player_y, &game.player_x))
	{
		write(2, "Error\nNo player in map\n", 23);
		free_map(game.map);
		exit(1);
	}
	game.map[game.player_y][game.player_x] = '0';
	game.total_coins = count_map_items(game.map, 'C');
	game.collect_coins = 0;
	game.moves = 0;
	all_mlx(&game);
	mlx_loop(game.mlx);
	return (0);
}
