/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:36:40 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/08/07 23:19:30 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	slen;

	if (!dest || !src)
		return (0);
	slen = ft_strlen(src);
	if (slen + 1 < size)
	{
		ft_memcpy(dest, src, slen);
		dest[slen] = '\0';
	}
	else if (size != 0)
	{
		ft_memcpy(dest, src, size - 1);
		dest[size - 1] = '\0';
	}
	return (slen);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	s1_end;

	if (!dest || !src)
		return (0);
	i = 0;
	while (dest[i] && i < size)
		i++;
	s1_end = i;
	if (size == 0)
		return (s1_end + ft_strlen(src));
	while (src[i - s1_end] && i < size - 1)
	{
		dest[i] = src[i - s1_end];
		i++;
	}
	if (s1_end < size)
		dest[i] = '\0';
	return (s1_end + ft_strlen(src));
}

size_t	ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	if (!dest)
		return (0);
	i = 0;
	while (src && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

size_t	ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	if (!dest)
		return (0);
	i = 0;
	while (src && src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

size_t	ft_strcat(char *dest, const char *src)
{
	size_t	i;

	if (!dest)
		return (0);
	i = ft_strlen(dest);
	while (src && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

size_t	ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	if (!dest)
		return (0);
	i = ft_strlen(dest);
	j = 0;
	while (src && src[j] && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (j);
}
