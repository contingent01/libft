/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:57:34 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/08/11 16:26:49 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "../ft_printf/includes/ft_printf.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	buf[100];
	char	*line;

	fd = open("out", O_RDONLY);
	line = NULL;
	while (get_next_line(fd, &line) >= 0)
	{
		if (!*line)
			break ;
		ft_printf("main line = %s\n", line);
		free(line);
		line = NULL;
	}
}
