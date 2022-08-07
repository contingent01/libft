/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:27:25 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/08/07 16:28:46 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** assign 0 to n bytes of s using ft_memset
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
** allocate num * size using malloc
** then using ft_bzero to intiate all
** bytes to 0
*/

void	*ft_calloc(size_t num, size_t size)
{
	void	*m;

	if (num >= size && num * size < num)
		return (NULL);
	if (size > num && num * size < size)
		return (NULL);
	m = malloc(num * size);
	if (!m)
		return (NULL);
	ft_bzero(m, num * size);
	return (m);
}

/*
** Copying n bytes from src to dest stopping
** when the character c is found.
** returning the next character after c
** if c is not found in the n bytes, returning NULL.
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	if (!dest && !src)
		return (NULL);
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char)c)
			return (&d[++i]);
		i++;
	}
	return (NULL);
}

/*
** We use strings to manipulate memory byte by byte,
** we copy character by character src to dest.
** we return dest
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	if (!dest || !src)
		return (NULL);
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*
** If $s is in the left of $d,
** there could be an overlapping,
** so the function copy from the last,
** character to the first,
** if $d is in the left, using ft_memcpy()
** if they are equal, do nothing,
** and return $dest.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (!dest || !src)
		return (NULL);
	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	if (s < d)
		while (n-- > 0)
			d[n] = s[n];
	else if (s > d)
		ft_memcpy(dest, src, n);
	return (dest);
}
