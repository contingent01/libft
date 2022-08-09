/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:15:34 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/08/09 18:24:22 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*ft_strnrappend(char *s1, const char *s2, size_t n, int r)
{
	char	*result;

	if (!r)
		result = ft_strnjoin(s1, s2, n);
	else
		result = ft_strnjoin(s2, s1, n);
	if (!result)
		return (NULL);
	return (result);
}

char	*ft_strrappend(char *s1, const char *s2, int r)
{
	char	*result;

	if (!r)
		result = ft_strjoin(s1, s2);
	else
		result = ft_strjoin(s2, s1);
	free(s1);
	if (!result)
		return (NULL);
	return (result);
}

char	*append_value(char *s1, const char *s2, size_t s1len, size_t s2len)
{
	char	*result;

	result = malloc((s1len + s2len + 1) * sizeof(char));
	if (!result)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(result, s1, s1len);
	ft_memcpy(result + s1len, s2, s2len);
	result[s1len + s2len] = '\0';
	free(s1);
	return (result);
}

void	ft_putnstr_fd(char *s, size_t len, int fd)
{
	if (!s)
		return ;
	write(fd, s, len);
}
