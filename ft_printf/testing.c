/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:49:04 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/08/08 23:40:39 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
int main(void)
{
	int ret = 0;
	//ft_printf("ok %c=%x=%d=%s=%s\n",'o', 10, 4, "dkhissi", "mostafa");
	ret = ft_printf(" %c %c %c ", '0', 0, '1');
	printf("\nret = %d\n", ret);
	ret = printf(" %c %c %c ", '0', 0, '1');
	printf("\nret = %d\n", ret);
	return (0);
}