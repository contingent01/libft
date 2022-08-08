/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:15:34 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/08/08 22:44:31 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_strallocat() is like ft_strjoin()
** just some modifications :
**
** It get the address of (dest) string,
** instead of using return (dest).
**
** If (*dest) or (src) are NULL,
** it will still continue.
**
** It will free (*dest) if it's not NULL.
**
** then it will affect it with the new
** allocated string.
*/

char	*ft_strnrappend(char *s1, const char *s2, size_t n, int r)
{
	char	*result;

	if (!r)
		result = ft_strnjoin(s1, s2, n);
	else
		result = ft_strnjoin(s2, s1, n);
	if (!result)
		return (NULL);
	return (result);
}

char	*ft_strrappend(char *s1, const char *s2, int r)
{
	char	*result;

	if (!r)
		result = ft_strjoin(s1, s2);
	else
		result = ft_strjoin(s2, s1);
	free(s1);
	if (!result)
		return (NULL);
	return (result);
}

char	*str_capitalize(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	}
	return (str);
}

