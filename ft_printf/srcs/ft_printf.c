/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:19:56 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/08/09 18:14:13 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = ft_vprintf(NULL, -1, format, args);
	return (ret);
}

int	ft_sprintf(char **dest, const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = ft_vprintf(dest, -1, format, args);
	return (ret);
}

int	ft_peprintf(const char *format, ...)
{
	va_list	args;
	int		ret;
	char	*s;

	va_start(args, format);
	ret = ft_vprintf(&s, -1, format, args);
	perror(s);
	free(s);
	return (ret);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = ft_vprintf(NULL, fd, format, args);
	return (ret);
}
