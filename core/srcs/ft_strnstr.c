/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:38:54 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/08/05 21:32:29 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	f;

	if (!s1 || !s2)
		return (NULL);
	if (!(*s2))
		return ((char *)&s1[ft_strlen(s1)]);
	if (!(*s1) && !(*s2))
		return ((char *)&s1[0]);
	i = 0;
	j = 0;
	while (i < n && s1[i])
	{
		f = i;
		k = i;
		j = 0;
		while (s1[k] && s2[j] && s1[k] == s2[j] && k < n)
		{
			k++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)&s1[f]);
		i++;
	}
	return (NULL);
}
