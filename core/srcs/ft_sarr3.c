/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarr3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:49:31 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/11/27 02:27:36 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sarndup(char **src, size_t n)
{
	char	**dup;
	size_t	lensrc;
	size_t	lendest;

	if (!src)
		return (NULL);
	lensrc = ft_sarlen((char **) src);
	lendest = n * (lensrc > n) + lensrc * (lensrc <= n);
	dup = malloc(sizeof(char *) * (lendest + 1));
	if (!dup)
		return (NULL);
	ft_sarncpy(dup, src, lendest);
	return (dup);
}

char	**ft_sarjoin(char **sar1, char **sar2)
{
	size_t	lensar1;
	size_t	lensar2;
	char	**result;

	lensar1 = ft_sarlen(sar1);
	lensar2 = ft_sarlen(sar2);
	if (!lensar1 && !lensar2)
		return (ft_sardup(empty_sar()));
	if (!lensar1)
		return (ft_sardup(sar2));
	if (!lensar2)
		return (ft_sardup(sar1));
	result = malloc(sizeof(char *) * (lensar1 + lensar2 + 1));
	if (!result)
		return (NULL);
	ft_sarncpy(result, sar1, lensar1);
	ft_sarncpy(result + lensar1, sar2, lensar2);
	return (result);
}

char	**ft_sarnjoin(char **sar1, char **sar2, size_t n)
{
	size_t	lensar1;
	size_t	lensar2;
	char	**result;

	lensar1 = ft_sarlen(sar1);
	lensar2 = ft_sarlen(sar2);
	lensar2 = n * (lensar2 > n) + lensar2 * (lensar2 <= n);
	result = malloc((lensar1 + lensar2 + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	ft_sarcpy(result, sar1);
	ft_sarncat(result, sar2, lensar2);
	return (result);
}

char	*ft_sarstr(char **sar, const char *s)
{
	size_t	i;

	if (!sar || !*sar || !s)
		return (NULL);
	i = 0;
	while (sar[i])
	{
		if (!ft_strcmp(sar[i], s))
			return (sar[i]);
		i++;
	}
	return (NULL);
}

char	*ft_sarnstr(char **sar, const char *s, size_t n)
{
	size_t	i;

	if (!sar || !*sar || !s)
		return (NULL);
	i = 0;
	while (i < n && sar[i])
	{
		if (!ft_strcmp(sar[i], s))
			return (sar[i]);
		i++;
	}
	return (NULL);
}
