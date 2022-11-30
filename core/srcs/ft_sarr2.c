/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarr2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:56:05 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/11/25 23:59:49 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_sarcpy(char **dest, char **src)
{
	size_t	i;

	if (!dest)
		return (0);
	if (!src)
	{
		dest[0] = NULL;
		return (0);
	}
	i = 0;
	while (src[i])
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
	dest[i] = NULL;
	return (i);
}

size_t	ft_sarncpy(char **dest, char **src, size_t n)
{
	size_t	i;

	if (!dest)
		return (0);
	if (!src)
	{
		dest[0] = NULL;
		return (0);
	}
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
	dest[i] = NULL;
	return (i);
}

size_t	ft_sarcat(char **dest, char **src)
{
	size_t	i;

	if (!dest)
		return (0);
	i = ft_sarlen(dest);
	if (src)
	{
		while (src[i])
		{
			dest[i] = ft_strdup(src[i]);
			i++;
		}
	}
	dest[i] = NULL;
	return (i);
}

size_t	ft_sarncat(char **dest, char **src, size_t n)
{
	size_t	i;
	size_t	j;

	if (!dest)
		return (0);
	i = ft_sarlen(dest);
	j = 0;
	if (src)
	{
		while (src[j] && j < n)
		{
			dest[i] = ft_strdup(src[j]);
			i++;
			j++;
		}
	}
	dest[i] = NULL;
	return (j);
}

char	**ft_sardup(char **src)
{
	char	**dup;
	size_t	lensrc;

	if (!src)
		return (NULL);
	lensrc = ft_sarlen(src);
	dup = malloc(sizeof(char *) * (lensrc + 1));
	if (!dup)
		return (NULL);
	ft_sarcpy(dup, src);
	return (dup);
}
