/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:29:25 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/10/09 19:20:04 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** assign c to every byte of *s up to n
*/

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	if (!s)
		return (NULL);
	ptr = s;
	while (n-- > 0)
		*ptr++ = c;
	return (s);
}

/*
** Moving index in a loop up to n,
** stopping when finding c character
** verify after that if index stopped
** before reaching n, if it stopped return
** the address of the character in the string
** using the index variable. If not return NULL.
*/

void	*ft_memchr(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	if (!s)
		return (NULL);
	str = s;
	i = 0;
	while (i < n && str[i] != (unsigned char)c)
		i++;
	if (i < n)
		return (&str[i]);
	else
		return (NULL);
}

/*
** We use strings to manipulate memory,
** we read character by character,
** if we find difference between them,
** we return the difference. if not we'll return 0;
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*one;
	unsigned char	*two;

	if (!s1)
		return (-1);
	else if (!s2)
		return (1);
	else if (!s1 && !s2)
		return (0);
	one = (unsigned char *)s1;
	two = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (one[i] != two[i])
			return (one[i] - two[i]);
		i++;
	}
	return (0);
}

void	*ft_free(void *ptr)
{
	free(ptr);
	return (NULL);
}

void	*ft_free_ptrs4(void *p1, void *p2, void *p3, void *p4)
{
	void	**pp1;
	void	**pp2;
	void	**pp3;
	void	**pp4;

	pp1 = (void **)p1;
	pp2 = (void **)p2;
	pp3 = (void **)p3;
	pp4 = (void **)p4;
	if (pp1 && *pp1)
		*pp1 = ft_free(*pp1);
	if (pp2 && *pp2)
		*pp2 = ft_free(*pp2);
	if (pp3 && *pp3)
		*pp3 = ft_free(*pp3);
	if (pp4 && *pp4)
		*pp4 = ft_free(*pp4);
	return (NULL);
}
