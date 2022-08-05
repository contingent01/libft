/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:54:25 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/07/29 15:55:28 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	sign_0x(char **bigStr, long n, t_tags *tags, int r)
{
	char	*s;

	s = NULL;
	if (tags->specifier == 'x' || tags->specifier == 'X'
		|| tags->specifier == 'p')
	{
		s = s_0x(tags);
		ft_strnallocat(bigStr, s, -1, r);
		free(s);
	}
	if (tags->specifier == 'i' || tags->specifier == 'd')
	{
		s = s_sign(n, tags->sign);
		ft_strnallocat(bigStr, s, -1, r);
		free(s);
	}
}

void	reinit_flags(t_tags *tags)
{
	tags->nil = 0;
	tags->len = 0;
	tags->specifier = '\0';
	tags->sign = '\0';
	tags->justify = '\0';
	tags->zerow = false;
	tags->width = -1;
	tags->precision = -1;
}

char	*extract_var(char *param, va_list *vl, t_tags *tags)
{
	if (tags->specifier == 'd')
		param = format_idu(va_arg(*vl, int), tags);
	else if (tags->specifier == 'i')
		param = format_idu(va_arg(*vl, int), tags);
	else if (tags->specifier == 'u')
		param = format_idu(va_arg(*vl, unsigned int), tags);
	else if (tags->specifier == 'p')
		param = format_p(va_arg(*vl, uintptr_t), tags);
	else if (tags->specifier == 'c')
		param = format_c((char) va_arg(*vl, int), tags);
	else if (tags->specifier == 's')
		param = format_s(va_arg(*vl, char *), tags);
	else if (tags->specifier == 'x')
		param = format_x(va_arg(*vl, unsigned int), tags);
	else if (tags->specifier == 'X')
		param = str_capitalize(format_x(va_arg(*vl, unsigned int), tags));
	else if (tags->specifier == '%')
		param = format_c('%', tags);
	return (param);
}

char	*parse_param(const char *format, int *i, va_list *vl, t_tags *tags)
{
	char	*param;

	param = NULL;
	if (extract_tags(format, &(*i), vl, tags))
		param = extract_var(param, vl, tags);
	else
		return (NULL);
	return (param);
}
