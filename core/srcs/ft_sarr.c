/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:31:53 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/08/07 17:34:21 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_sar(char **sarr)
{
	int	i;

	i = 0;
	while (sarr && sarr[i])
	{
		free(sarr[i]);
		i++;
	}
	free(sarr);
	return (NULL);
}