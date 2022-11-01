/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:57:34 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/10/24 16:26:33 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lft.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("out", O_RDONLY);
	ft_printf("BFZ = %d\n", BUFFER_SIZE);
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
	 	ft_printf("main line = %s", line);
	 	free(line);
	}

	fd = open("out2", O_RDONLY);
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
	 	ft_printf("main line = %s", line);
	 	free(line);
	}

	//char	*result;
	//result = ft_strtrim("abcd", "ad");
	//printf("result = %s\n", result);
	
	return (0);
}
