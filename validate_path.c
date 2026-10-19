/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:48:06 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/22 14:59:25 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	free_return_false(char **cpy_map)
{
	if (cpy_map != NULL)
		free_map(cpy_map);
	return (0);
}

static char	**copy_map(char **map)
{
	char	**cpy_map;
	int		y;

	y = 0;
	while (map[y] != NULL)
		y++;
	cpy_map = malloc((y + 1) * sizeof(char *));
	if (cpy_map == NULL)
		return (NULL);
	y = 0;
	while (map[y] != NULL)
	{
		cpy_map[y] = ft_strdup(map[y]);
		if (cpy_map == NULL)
			return (NULL);
		y++;
	}
	cpy_map[y] = NULL;
	return (cpy_map);
}

int	player_location(char **cpy_map, int *p_y, int *p_x)
{
	int	x;
	int	y;

	y = 0;
	while (cpy_map[y] != NULL)
	{
		x = 0;
		while (cpy_map[y][x] != '\0')
		{
			if (cpy_map[y][x] == 'P')
			{
				*p_y = y;
				*p_x = x;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static void	flood_fill(char **cpy_map, int y, int x)
{
	if (y < 0 || x < 0 || cpy_map[y] == NULL || cpy_map[y][x] == '\0')
		return ;
	if (cpy_map[y][x] == '1' || cpy_map[y][x] == 'X')
		return ;
	cpy_map[y][x] = 'X';
	flood_fill(cpy_map, y - 1, x);
	flood_fill(cpy_map, y + 1, x);
	flood_fill(cpy_map, y, x + 1);
	flood_fill(cpy_map, y, x - 1);
}

int	validate_path(char **map)
{
	char	**cpy_map;
	int		col;
	int		row;
	int		p_y;
	int		p_x;

	cpy_map = copy_map(map);
	if (cpy_map == NULL || !player_location(cpy_map, &p_y, &p_x))
		return (free_return_false(cpy_map));
	flood_fill(cpy_map, p_y, p_x);
	row = 0;
	while (cpy_map[row] != NULL)
	{
		col = 0;
		while (cpy_map[row][col] != '\0')
		{
			if (cpy_map[row][col] == 'C' || cpy_map[row][col] == 'E')
				return (free_return_false(cpy_map));
			col++;
		}
		row++;
	}
	free_map(cpy_map);
	return (1);
}
