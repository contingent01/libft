/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:18:35 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/11/27 04:14:15 by mdkhissi         ###   ########.fr       */
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

char	*ft_strepchr(char *s, char c, char r)
{
	char	*c_to_rep;

	c_to_rep = ft_strchr(s, c);
	if (!c_to_rep)
		return (NULL);
	*c_to_rep = r;
	return (c_to_rep);
}

char	*ft_strrepchr(char *s, char c, char r)
{
	char	*c_to_rep;

	c_to_rep = ft_strrchr(s, c);
	if (!c_to_rep)
		return (NULL);
	*c_to_rep = r;
	return (c_to_rep);
}

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	f;

	if (!s1 || !s2)
		return (NULL);
	if (!(*s2))
		return ((char *)&s1[ft_strlen(s1)]);
	if (!(*s1) && !(*s2))
		return ((char *)&s1[0]);
	i = 0;
	j = 0;
	while (s1[i])
	{
		f = i;
		k = i;
		j = 0;
		while (s1[k] && s2[j] && s1[k] == s2[j])
			k = k + 1 + 0 * j++;
		if (s2[j] == '\0')
			return ((char *)&s1[f]);
		i++;
	}
	return (NULL);
}
