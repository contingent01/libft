/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:31:53 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/11/19 19:42:09 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_sar(char **sarr)
{
	int	i;

	if (!sarr)
		return (NULL);
	i = 0;
	while (sarr[i])
	{
		free(sarr[i]);
		i++;
	}
	free(sarr);
	return (NULL);
}

void	*ft_free_sars4(char ***sarr1, char ***sarr2,
			char ***sarr3, char ***sarr4)
{
	if (sarr1 && *sarr1)
		*sarr1 = ft_free_sar(*sarr1);
	if (sarr2 && *sarr2)
		*sarr2 = ft_free_sar(*sarr2);
	if (sarr3 && *sarr3)
		*sarr3 = ft_free_sar(*sarr3);
	if (sarr4 && *sarr4)
		*sarr4 = ft_free_sar(*sarr4);
	return (NULL);
}

void	ft_iter_sar(char **sarr, void (*f)(char *))
{
	int	i;

	if (!sarr || !f)
		return ;
	i = 0;
	while (sarr[i])
	{
		f(sarr[i]);
		i++;
	}
}

int	ft_sarr_len(char **sarr)
{
	int	i;

	if (!sarr)
		return (0);
	i = 0;
	while (sarr[i])
		i++;
	return (i);
}
