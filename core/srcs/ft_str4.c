/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:38:45 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/08/08 22:03:42 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	realen;
	char	*xtr;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		realen = 0;
	else if (len > slen - start)
		realen = slen - start;
	else
		realen = len;
	xtr = malloc(sizeof(char) * (realen + 1));
	if (!xtr)
		return (NULL);
	if (realen)
		ft_memcpy(xtr, s + start, realen);
	xtr[realen] = '\0';
	return (xtr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*result;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!lens1 && !lens2)
		return (ft_strdup(""));
	if (!lens1)
		return (ft_strdup((char *)s2));
	if (!lens2)
		return (ft_strdup((char *)s1));
	result = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!result)
		return (NULL);
	result = ft_memcpy(result, s1, lens1);
	ft_memcpy(result + lens1, s2, lens2);
	result[lens1 + lens2] = '\0';
	return (result);
}

char	*ft_strnjoin(const char *s1, const char *s2, size_t n)
{
	size_t	s1len;
	size_t	s2len;
	char	*result;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	s2len = n * (s2len > n) + s2len * (s2len <= n);
	result = malloc((s1len + s2len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strcpy(result, s1);
	ft_strncat(result, s2, s2len);
	return (result);
}

char	*ft_strnappend(char *s1, const char *s2, size_t n)
{
	char	*result;

	result = ft_strnjoin(s1, s2, n);
	free(s1);
	if (!result)
		return (NULL);
	return (result);
}

char	*ft_strappend(char *s1, const char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	if (!result)
		return (NULL);
	return (result);
}