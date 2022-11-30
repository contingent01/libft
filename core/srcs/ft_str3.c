/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:54:23 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/11/25 21:43:04 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Moving index from 0 up to $c,
** if it reach '\0' and $c is not '\0'
** return NULL
** Anything else return the address of
** the character pointed by the index.
*/

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == '\0' && (char)c != '\0')
		return (NULL);
	else
		return ((char *)&s[i]);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		last;

	if (!s)
		return (NULL);
	i = 0;
	last = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			last = i;
		i++;
	}
	if (last >= 0)
		return ((char *)&s[last]);
	else if ((char)c == '\0')
		return ((char *)&s[i]);
	else
		return (NULL);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
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
	while (i < n && s1[i])
	{
		f = i;
		k = i;
		j = 0;
		while (s1[k] && s2[j] && s1[k] == s2[j] && k < n)
			k = k + 1 + 0 * j++;
		if (s2[j] == '\0')
			return ((char *)&s1[f]);
		i++;
	}
	return (NULL);
}

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	if (!f)
		return (ft_strdup(s));
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
