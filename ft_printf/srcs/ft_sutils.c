/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:22:47 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/07/29 15:56:14 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_precision(char **bigStr, t_tags *tags)
{
	char	*s;

	s = NULL;
	if (tags->precision > tags->len)
	{
		s = malloc(sizeof(char) * (tags->precision - tags->len + 1));
		if (!s)
			return ;
		ft_memset(s, '0', tags->precision - tags->len);
		s[tags->precision - tags->len] = '\0';
		ft_strnallocat(bigStr, s, -1, 1);
		free(s);
		tags->len += tags->precision - tags->len;
	}
	if (tags->precision > -1 && tags->justify == '0')
		tags->justify = '\0';
}

void	s_width(char **bigStr, long n, t_tags *tags)
{
	char	*s;
	int		len_s;

	s = NULL;
	if (tags->width > tags->len)
	{
		len_s = tags->width - tags->len;
		tags->len = tags->width;
		s = malloc(sizeof(char) * (len_s + 1));
		if (!s)
			return ;
		if (tags->justify == '0')
			ft_memset(s, '0', len_s + 1);
		else
			ft_memset(s, ' ', len_s + 1);
		s[len_s] = '\0';
		if (tags->justify != '0')
			sign_0x(bigStr, n, tags, 1);
		s_justify(bigStr, s, tags);
		if (tags->justify == '0')
			sign_0x(bigStr, n, tags, 1);
	}
	else
		sign_0x(bigStr, n, tags, 1);
	free(s);
}

void	s_justify(char **bigStr, char *s, t_tags *tags)
{
	if (tags->justify == '-')
		ft_strnallocat(bigStr, s, -1, 0);
	else if (tags->justify == '0')
		ft_strnallocat(bigStr, s, -1, 1);
	else
		ft_strnallocat(bigStr, s, -1, 1);
}

char	*s_sign(long n, char tagsign)
{
	char	*s;

	if (n < 0 || tagsign)
	{
		s = malloc(sizeof(char) * (1 + 1));
		if (!s)
			return (NULL);
		if (n < 0)
		{
			*s = '-';
			s[1] = 0;
		}
		else
		{
			if (tagsign == ' ')
				*s = ' ';
			else if (tagsign == '+')
				*s = '+';
			s[1] = '\0';
		}
		return (s);
	}
	return (NULL);
}

char	*s_0x(t_tags *tags)
{
	char	*s;

	if (tags->zerow || tags->specifier == 'p')
	{
		s = malloc(sizeof(char) * (2 + 1));
		*s = '0';
		s[1] = 'x';
		s[2] = '\0';
		return (s);
	}
	return (NULL);
}
