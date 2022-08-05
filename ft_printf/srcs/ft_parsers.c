/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:17:50 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/07/29 15:56:01 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	extract_flags(const char *format, int *i, t_tags *tags)
{
	while (ft_strchr(format[*i], g_flags) != -1)
	{
		if (format[*i] == '+')
			tags->sign = format[*i];
		else if (format[*i] == ' ' && !tags->sign)
			tags->sign = format[*i];
		else if (format[*i] == '-')
			tags->justify = format[*i];
		else if (format[*i] == '0' && !tags->justify)
			tags->justify = format[*i];
		else if (format[*i] == '#')
			tags->zerow = true;
		(*i)++;
	}
}

void	extract_width(const char *format, int *i, va_list *vl, t_tags *tags)
{
	int	j;
	int	k;

	j = *i;
	if (format[j] == '*')
	{
		tags->width = va_arg(*vl, int);
		if (tags->width < 0)
		{
			tags->width *= -1;
			tags->justify = '-';
		}
		j++;
	}
	k = j;
	while (ft_isdigit(format[j]))
		j++;
	if (j > k)
	{
		tags->width = ft_atoi(format + k);
	}
	*i = j;
}

void	extract_precisio(const char *format, int *i, va_list *vl, t_tags *tags)
{
	int	j;
	int	k;

	j = *i;
	if (format[j] == '.')
	{
		j++;
		if (format[j] == '*')
		{
			tags->precision = va_arg(*vl, int);
			j++;
		}
		else
		{
			k = j;
			while (ft_isdigit(format[j]))
				j++;
			tags->precision = ft_atoi(format + k);
		}
	}
	*i = j;
}

bool	extract_specifier(const char *format, int *i, t_tags *tags)
{
	if (ft_strchr(format[*i], g_specifiers) != -1)
	{
		tags->specifier = format[*i];
		(*i)++;
		return (true);
	}
	return (false);
}

bool	extract_tags(const char *format, int *i, va_list *vl, t_tags *tags)
{
	(*i)++;
	extract_flags(format, i, tags);
	extract_width(format, i, vl, tags);
	extract_precisio(format, i, vl, tags);
	if (extract_specifier(format, i, tags))
		return (true);
	return (false);
}
