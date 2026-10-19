/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:45:14 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/22 14:55:58 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	x;

	x = 0;
	while (map[x] != NULL)
	{
		free(map[x]);
		x++;
	}
	free(map);
}

static void	*error_return_null(char *msg)
{
	int	x;

	x = 0;
	while (msg[x] != '\0')
		x++;
	if (msg != NULL)
	{
		write(2, msg, x);
	}
	return (NULL);
}

static int	height_of_path(char *path)
{
	char	*line;
	int		fd;
	int		count;

	count = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static void	read_all_lines(int fd, char **map)
{
	char	*line;
	int		x;
	int		len;

	x = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = 0;
		while (line[len] != '\0')
			len++;
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		map[x] = line;
		x++;
		line = get_next_line(fd);
	}
	map[x] = NULL;
}

char	**read_map(char *path)
{
	char	**map;
	int		fd;
	int		height;

	height = height_of_path(path);
	if (height == 0)
		return (error_return_null("Error\nEmpty Map\n"));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (error_return_null("Error\nOpen Failed\n"));
	map = (char **)malloc((height + 1) * sizeof(char *));
	if (map == NULL)
		return (NULL);
	read_all_lines(fd, map);
	close(fd);
	if (!map_check(map))
	{
		write(2, "Error\nMap Failed\n", 17);
		free_map(map);
		return (NULL);
	}
	return (map);
}
