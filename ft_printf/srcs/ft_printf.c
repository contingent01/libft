/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:19:56 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/08/07 14:47:40 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	append_text(char **s, const char *format, int *i, int count)
{
	int	from;

	from = (*i)++;
	while (format[*i] && format[*i] != '%')
		(*i)++;
	if (*i - from > 0)
		ft_strnallocat(s, format + from, *i - from, 0);
	count += *i - from;
	return (count);
}

void	print_s_fd(char **dest, char *s, int fd)
{
	if (dest)
		*dest = s;
	if (fd >= 0)
		ft_putstr_fd(s, fd);
	if (!dest && fd == -1)
		ft_putstr_fd(s, STDOUT_FILENO);
}

int	ft_vprintf(char **dest, int fd, const char *format, va_list args)
{
	va_list	vl;
	t_tags	tags;
	int		i;
	int		count;
	char	*s;

	s = NULL;
	count = 0;
	i = 0;
	va_copy(vl, args);
	while (format[i])
	{
		if (format[i] == '%')
		{
			reinit_flags(&tags);
			ft_strnallocat(&s,
				parse_param(format, &i, &vl, &tags), tags.len, 0);
			count += tags.len;
		}
		else
			count = append_text(&s, format, &i, count);
	}
	print_s_fd(dest, s, fd);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	ft_vprintf(NULL, -1, format, args);
	return (1);
}