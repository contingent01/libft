/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:39:03 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/11/25 21:43:04 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// /*
// ** Trim set of characters from the beginning
// ** and the end of a string, and return the new string.
// ** Use $i index to walk from start to end
// ** while it find the $set characters to trim.
// ** Calculate length of $src :
// ** if it's equal to 0, $k is affected by $i
// ** and $i is incremented to get $i > $k,
// ** else, affect $k by $slen - 1, to point on the
// ** last character
// ** if $i > $k then $len = 0
// ** else if $i == $k, that means we got one character
// ** in $src,
// ** else if $i < $k :
// ** using $k, it will move from right to left while
// ** it find the trimmable characters,
// ** $len = $k - $i + 1, to get the length of the string
// ** in the middle.
// ** Allocate $result of size $len
// ** copy $len characters from $i (from $i to $k)
// ** return $result
// */

char	*ft_strtrim(const char *src, const char *set)
{
	char	*dest;
	size_t	i;
	size_t	j;
	size_t	dlen;

	if (!src)
		return (NULL);
	if (!set || !*set || !*src)
		return (ft_strdup(src));
	i = 0;
	while (ft_strchr(set, src[i]) && src[i])
		i++;
	j = ft_strlen(src) - 1;
	while (ft_strchr(set, src[j]) && j > 0)
		j--;
	if (i <= j)
		dlen = j - i + 1;
	else
		dlen = 0;
	dest = malloc(sizeof(char) * (dlen + 1));
	if (!dest)
		return (NULL);
	ft_strncpy(dest, src + i, dlen);
	return (dest);
}

void	ft_strepallch(char *s, char c, char r)
{
	char	*i;

	i = ft_strepchr(s, c, r);
	while (i != NULL)
	{
		i = ft_strepchr(s, c, r);
	}
}

void	ft_putendl(char *s)
{
	ft_putendl_fd(s, STDOUT_FILENO);
}
