/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoston.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:17:39 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/07/29 15:55:56 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		x;
	int		sign;
	int		tmp;

	i = 0;
	x = 0;
	sign = 1;
	if (str[i] == '-')
		sign *= i++ - 1;
	while (ft_isdigit(str[i]) && str[i])
	{
		tmp = x;
		x = x * 10 + str[i] - '0';
		if (((x - (str[i] - '0')) / 10) * sign != tmp * sign)
		{
			if (sign < 0)
				x = 0;
			else
				x = -1;
			break ;
		}
		i++;
	}
	return (x * sign);
}

char	*ft_itoa_ws(long n)
{
	int		i;
	char	*s;
	long	div;
	int		count;

	calculate_i_div_count(n, &div, &count);
	s = malloc(sizeof(char) * (count + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (div != 0)
	{
		s[i] = n / div;
		if (s[i] < 0)
			s[i] *= -1;
		s[i++] += '0';
		n = n % div;
		div /= 10;
	}
	s[i] = '\0';
	return (s);
}

void	ft_itox_worker(uintptr_t nbr, char *s, int i, int *count)
{
	static const char	base[] = "0123456789abcdef";
	uintptr_t			div;

	if (nbr >= 16)
	{
		div = nbr / 16;
		ft_itox_worker(div, s, i - 1, count);
	}
	s[i] = base[nbr % 16];
	(*count)++;
}

char	*ft_itox(uintptr_t n)
{
	char	tmp[MAX];
	char	*s;
	int		i;
	int		count;

	i = 0;
	while (i < MAX - 1)
		tmp[i++] = ' ';
	tmp[MAX - 1] = '\0';
	count = 0;
	ft_itox_worker(n, tmp, MAX - 2, &count);
	s = malloc((count + 1) * sizeof(char));
	ft_strncpy(s, tmp + MAX - 1 - count, -1);
	return (s);
}

void	calculate_i_div_count(long n, long *div, int *count)
{
	long long int	x;

	*div = 1;
	x = n;
	*count = 1;
	x = x / 10;
	while (x != 0 && (*count)++ >= 0)
	{
		*div *= 10;
		x = x / 10;
	}
}
