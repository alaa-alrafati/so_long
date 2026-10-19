/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:45:46 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/18 14:31:51 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_rectangle(char **map)
{
	int	x;
	int	j;
	int	len;

	j = 1;
	x = 0;
	len = 0;
	if (map == NULL || map[0] == NULL)
		return (0);
	while (map[0][x] != '\0')
		x++;
	len = x;
	while (map[j] != NULL)
	{
		x = 0;
		while (map[j][x] != '\0')
			x++;
		if (x != len)
			return (0);
		j++;
	}
	return (1);
}

static int	validate_walls(char **map)
{
	int	x_j;
	int	col;
	int	row;

	row = 0;
	while (map[row] != NULL)
		row++;
	col = 0;
	while (map[0][col] != '\0')
		col++;
	x_j = 0;
	while (x_j < col)
	{
		if (map[0][x_j] != '1' || map[row - 1][x_j] != '1')
			return (0);
		x_j++;
	}
	x_j = 1;
	while (x_j < row - 1)
	{
		if (map[x_j][0] != '1' || map[x_j][col - 1] != '1')
			return (0);
		x_j++;
	}
	return (1);
}

static int	validate_chars(char **map)
{
	int	x;
	int	j;

	if (map == NULL || map[0] == NULL)
		return (0);
	j = 0;
	while (map[j] != NULL)
	{
		x = 0;
		while (map[j][x] != '\0')
		{
			if (map[j][x] != 'P' && map[j][x] != 'E' && map[j][x] != 'C'
					&& map[j][x] != '0' && map[j][x] != '1')
				return (0);
			x++;
		}
		j++;
	}
	return (1);
}

int	count_map_items(char **map, char c)
{
	int	x;
	int	j;
	int	count;

	count = 0;
	j = 0;
	while (map[j] != NULL)
	{
		x = 0;
		while (map[j][x] != '\0')
		{
			if (map[j][x] == c)
				count++;
			x++;
		}
		j++;
	}
	return (count);
}

int	map_check(char **map)
{
	int	player;
	int	exit;
	int	collectibles;

	if (!validate_rectangle(map) || !validate_walls(map)
		|| !validate_chars(map))
		return (0);
	if (!validate_path(map))
		return (0);
	player = count_map_items(map, 'P');
	exit = count_map_items(map, 'E');
	collectibles = count_map_items(map, 'C');
	if (player != 1 || exit != 1 || collectibles < 1)
		return (0);
	return (1);
}
