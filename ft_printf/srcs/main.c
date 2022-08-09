/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:08:24 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/08/09 18:25:39 by mdkhissi         ###   ########.fr       */
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
		*s = append_value(*s, format + from, count, *i - from);
	count += *i - from;
	return (count);
}

void	print_s_fd(char **dest, char *s, int fd, int len)
{
	if (dest)
		*dest = s;
	if (fd >= 0)
		ft_putnstr_fd(s, len, fd);
	if (!dest && fd == -1)
		ft_putnstr_fd(s, len, STDOUT_FILENO);
	if (!dest)
		free(s);
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
			tags.tmp = parse_param(format, &i, &vl, &tags);
			s = append_value(s, tags.tmp, count, tags.len);
			free(tags.tmp);
			count += tags.len;
		}
		else
			count = append_text(&s, format, &i, count);
	}
	print_s_fd(dest, s, fd, count);
	return (count);
}
