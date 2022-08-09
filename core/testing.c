/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 23:12:25 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/08/09 18:51:45 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

int main(void)
{
	char *s;
	int	*t;

	s = ft_strjoin("Hi", ", I am me\n");
	t = malloc(4 * sizeof(int));
	t[0] = 3;
	t[1] = 2;
	t[2] = 10;
	t[3] = 100;
	ft_free_ptrs4(&s, &t, NULL, NULL);
	//printf("%s\n", ft_strnjoin("ok", " hello", 3));
	printf("\n s = %s \n t = %p \n", s, t);
	return (0);
}