/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:18:56 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/22 15:10:32 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	alp;
	int		x;

	alp = (char)c;
	x = 0;
	if (s == NULL)
		return (NULL);
	while (s[x] != '\0')
	{
		if (s[x] == alp)
		{
			return ((char *)(s + x));
		}
		x++;
	}
	if (alp == '\0')
	{
		return ((char *)(s + x));
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*co;
	size_t	x;

	if (s == NULL)
		return (NULL);
	x = 0;
	while (s[x] != '\0')
		x++;
	co = (char *)malloc((x + 1) * sizeof(char));
	if (co == NULL)
		return (NULL);
	x = 0;
	while (s[x] != '\0')
	{
		co[x] = s[x];
		x++;
	}
	co[x] = '\0';
	return (co);
}

size_t	ft_strlen(const char *s)
{
	size_t	x;

	if (s == NULL)
		return (0);
	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*newstr;
	size_t	x;
	size_t	y;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	newstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	x = 0;
	while (s1[x] != '\0')
	{
		newstr[x] = s1[x];
		x++;
	}
	y = 0;
	while (s2[y] != '\0')
		newstr[x++] = s2[y++];
	newstr[x] = '\0';
	free(s1);
	return (newstr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	x;
	size_t	length;

	if (s == NULL)
		return (NULL);
	length = ft_strlen(s);
	if (start >= length)
		return (ft_strdup(""));
	if (len > length - start)
		len = length - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	x = 0;
	while (s[x] != '\0' && x < len)
	{
		substr[x] = s[start + x];
		x++;
	}
	substr[x] = '\0';
	return (substr);
}
