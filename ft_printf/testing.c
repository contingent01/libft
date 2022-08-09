/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:49:04 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/08/09 18:02:39 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


void	putnstr(char *s, size_t len);

int main(void)
{
	int ret = 0;
	int	fd;

	fd = open("outt.txt", O_WRONLY, 0644);
	ft_peprintf("minishell: cd: %s %d", "/home/mdkhissi", 5);
	//ft_printf(" %.3p %p ", (void*)5 , NULL);
	//printf("\n %.0p %p ", (void*)5 , NULL);
	//ft_fprintf(fd, "cd: %s", "/home/mdkhissi");

	return (0);
}

void	putnstr(char *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		write(1, &s[i], 1);
		i++;
	}
}