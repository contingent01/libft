/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:38:58 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/08/05 18:54:24 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		last;

	if (!s)
		return (NULL);
	i = 0;
	last = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			last = i;
		i++;
	}
	if (last >= 0)
		return ((char *)&s[last]);
	else if ((char)c == '\0')
		return ((char *)&s[i]);
	else
		return (NULL);
}
