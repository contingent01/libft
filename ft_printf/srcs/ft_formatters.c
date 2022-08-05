/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:17:19 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/07/29 15:55:50 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_x(unsigned int n, t_tags *tags)
{
	char	*s;

	if (tags->precision == 0 && n == 0)
		s = NULL;
	else
		s = ft_itox(n);
	tags->len = ft_strlen(s);
	if (n == 0)
		tags->zerow = '\0';
	s_precision(&s, tags);
	if (tags->zerow)
		tags->len += 2;
	s_width(&s, n, tags);
	return (s);
}

char	*format_c(char c, t_tags *tags)
{
	char	*s;

	s = NULL;
	tags->len = 1;
	if (c == '\0')
	{
		tags->nil = 1;
		c = 'c';
	}
	ft_strnallocat(&s, &c, 1, 0);
	s_width(&s, 1, tags);
	if (tags->nil)
		s[ft_strchr('c', s)] = '\0';
	return (s);
}

char	*format_s(char *src, t_tags *tags)
{
	char	*s;
	char	*tmp;

	s = NULL;
	tmp = NULL;
	if (src == NULL)
		ft_strnallocat(&tmp, "(null)", -1, 0);
	else
		ft_strnallocat(&tmp, src, -1, 0);
	tags->len = ft_strlen(tmp);
	if (tags->precision < tags->len && tags->precision > -1)
	{
		ft_strnallocat(&s, tmp, tags->precision, 0);
		tags->len += tags->precision - tags->len;
	}
	else
		ft_strnallocat(&s, tmp, -1, 0);
	s_width(&s, 1, tags);
	free(tmp);
	return (s);
}

char	*format_p(uintptr_t n, t_tags *tags)
{
	char	*s;

	if (tags->precision == 0 && n == 0)
		s = NULL;
	else
		s = ft_itox(n);
	tags->len = ft_strlen(s);
	s_precision(&s, tags);
	tags->len += 2;
	s_width(&s, 1, tags);
	return (s);
}

char	*format_idu(long n, t_tags *tags)
{
	char	*s;

	if (tags->precision == 0 && n == 0)
		s = NULL;
	else
		s = ft_itoa_ws(n);
	tags->len = ft_strlen(s);
	s_precision(&s, tags);
	if (tags->specifier != 'u' && (n < 0 || tags->sign))
		(tags->len)++;
	s_width(&s, n, tags);
	return (s);
}
