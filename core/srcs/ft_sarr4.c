/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarr4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 02:38:46 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/11/27 03:56:29 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsar(char *s, char **sar)
{
	size_t	i;

	if (!sar || !*sar || !s)
		return (NULL);
	i = 0;
	while (sar[i])
	{
		if (ft_strstr(s, sar[i]))
			return (sar[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strnsar(char *s, char **sar, size_t n)
{
	size_t	i;

	if (!sar || !*sar || !s)
		return (NULL);
	i = 0;
	while (sar[i])
	{
		if (ft_strnstr(s, sar[i], n))
			return (sar[i]);
		i++;
	}
	return (NULL);
}

ssize_t	ft_strisar(char *s, char **sar)
{
	size_t	i;

	if (!sar || !*sar || !s)
		return (-1);
	i = 0;
	while (sar[i])
	{
		if (ft_strstr(s, sar[i]))
			return (i);
		i++;
	}
	return (-1);
}

ssize_t	ft_strinsar(char *s, char **sar, size_t n)
{
	size_t	i;

	if (!sar || !*sar || !s)
		return (-1);
	i = 0;
	while (sar[i])
	{
		if (ft_strnstr(s, sar[i], n))
			return (i);
		i++;
	}
	return (-1);
}
