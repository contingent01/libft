/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:15:34 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/07/29 15:55:45 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	if (!dest || !src)
		return ;
	if (n == 0)
		dest[0] = '\0';
	i = -1;
	if ((int) n == -1)
	{
		while (src[++i])
			dest[i] = src[i];
		dest[i] = '\0';
	}
	else
	{
		while (src[++i] && i < n)
			dest[i] = src[i];
		dest[n] = '\0';
	}
}

/*
** ft_strallocat() is like ft_strjoin()
** just some modifications :
**
** It get the address of (dest) string,
** instead of using return (dest).
**
** If (*dest) or (src) are NULL,
** it will still continue.
**
** It will free (*dest) if it's not NULL.
**
** then it will affect it with the new
** allocated string.
*/

void	ft_strnallocat(char **dest, const char *src, int n, int r)
{
	size_t	lendest;
	size_t	lensrc;
	char	*result;

	if (!dest || (!*dest && !src) || n == 0)
		return ;
	lendest = ft_strlen(*dest);
	lensrc = ft_strlen(src);
	if (n < (int)lensrc && n > 0)
		lensrc = n;
	result = malloc(sizeof(char) * (lendest + lensrc + 1));
	if (!result)
		return ;
	if (!r)
	{
		ft_strncpy(result, *dest, lendest);
		ft_strncpy(result + lendest, src, lensrc);
	}
	else
	{
		ft_strncpy(result, src, lensrc);
		ft_strncpy(result + lensrc, *dest, lendest);
	}
	free(*dest);
	*dest = result;
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n-- > 0)
		*ptr++ = c;
	return (s);
}

int	ft_strchr(const char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*str_capitalize(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	}
	return (str);
}
