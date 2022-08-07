/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:38:45 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/08/07 17:13:25 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	realen;
	char	*xtr;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		realen = 0;
	else if (len > slen - start)
		realen = slen - start;
	else
		realen = len;
	xtr = malloc(sizeof(char) * (realen + 1));
	if (!xtr)
		return (NULL);
	if (realen)
		ft_memcpy(xtr, s + start, realen);
	xtr[realen] = '\0';
	return (xtr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	result = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!result)
		return (NULL);
	result = ft_memcpy(result, s1, lens1);
	ft_memcpy(result + lens1, s2, lens2);
	result[lens1 + lens2] = '\0';
	return (result);
}

/*char	*ft_strnjoin(const char *s1, const char *s2)
{

}*/