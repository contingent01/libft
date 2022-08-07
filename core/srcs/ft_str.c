/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:35:18 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/08/07 17:30:34 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	l;

	l = 0;
	while (s && s[l] != '\0')
		l++;
	return (l);
}

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (!s1)
		return (-1);
	else if (!s2)
		return (1);
	else if (!s1 && !s2)
		return (0);
	i = 0;
	while (s1 && s2 && i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_strcmp(char const *s1, char const *s2)
{
	size_t	i;

	if (!s1)
		return (-1);
	else if (!s2)
		return (1);
	else if (!s1 && !s2)
		return (0);
	i = 0;
	while (s1 && s2 && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *src)
{
	char	*dup;
	size_t	lensrc;

	if (!src)
		return (NULL);
	lensrc = ft_strlen(src);
	dup = malloc(sizeof(char) * (lensrc + 1));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, src, lensrc);
	dup[lensrc] = '\0';
	return (dup);
}

char	*ft_strndup(const char *src, size_t n)
{
	char	*dup;
	size_t	lensrc;
	size_t	lendest;

	if (!src)
		return (NULL);
	lensrc = ft_strlen(src);
	lendest = n * (lensrc > n) + lensrc * (lensrc <= n);
	dup = malloc(sizeof(char) * (lendest + 1));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, src, lendest);
	dup[lendest] = '\0';
	return (dup);
}
