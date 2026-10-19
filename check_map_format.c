/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:55:34 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/18 12:57:16 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_format(char *name)
{
	int	x;

	x = 0;
	while (name[x] != '\0')
		x++;
	if (x < 4)
	{
		write(2, "Error\nMap Format Faild\n", 23);
		return (0);
	}
	if (!(name[x - 4] == '.' && name[x - 3] == 'b' && name[x -2] == 'e'
			&& name[x -1] == 'r'))
	{
		write(2, "Error\nMap Format Faild\n", 23);
		return (0);
	}
	return (1);
}
