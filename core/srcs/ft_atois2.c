/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atois2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:37:53 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/11/15 18:43:27 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_satoi(const char *str, int s)
{
	int		i;
	long	x;
	int		sign;

	i = 0;
	x = 0;
	sign = 1;
	if (s && (str[i] == '+' || str[i] == '-'))
		if (str[i++] == '-')
			sign *= -1;
	while (ft_isdigit(str[i]) && str[i])
	{
		x = x * 10 + str[i] - '0';
		if (x * sign > INT_MAX || x * sign < INT_MIN)
		{
			x = x_sign(x, sign);
			break ;
		}
		i++;
	}
	return ((int)(x * sign));
}
