/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:38:11 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/07/29 18:49:19 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Moving index from 0 up to $c,
** if it reach '\0' and $c is not '\0'
** return NULL
** Anything else return the address of
** the character pointed by the index.
*/

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return ((char *)s);
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == '\0' && c != '\0')
		return (NULL);
	else
		return ((char *)&s[i]);
}
