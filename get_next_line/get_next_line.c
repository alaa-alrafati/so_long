/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:09:44 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/22 15:11:05 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_and_return_null(char *buff, char *save)
{
	free(buff);
	free(save);
	return (NULL);
}

static	char	*read_to_buffer_to_save(int fd, char *save)
{
	char	*buff;
	ssize_t	nbytes;
	char	*tempsave;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff == NULL)
	{
		free(save);
		return (NULL);
	}
	nbytes = 1;
	while (!ft_strchr(save, '\n') && nbytes > 0)
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes < 0)
			return (free_and_return_null(buff, save));
		buff[nbytes] = '\0';
		tempsave = ft_strjoin(save, buff);
		if (tempsave == NULL)
			return (free_and_return_null(buff, save));
		save = tempsave;
	}
	free(buff);
	return (save);
}

static char	*cut_line(char *save)
{
	char	*line;
	size_t	i;

	if (save == NULL || save[0] == '\0')
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		i++;
	}
	if (save[i] == '\n')
		i++;
	line = ft_substr(save, 0, i);
	return (line);
}

static char	*refresh_save(char *save)
{
	char	*newsave;
	size_t	i;

	if (save == NULL)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	if (save[i] == '\n')
		i++;
	newsave = ft_strdup(save + i);
	free(save);
	return (newsave);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_to_buffer_to_save(fd, save);
	if (save == NULL)
		return (NULL);
	line = cut_line(save);
	if (line == NULL)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	save = refresh_save(save);
	return (line);
}
