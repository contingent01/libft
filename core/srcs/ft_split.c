/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:38:06 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/11/25 21:43:04 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Count and return the number of strings
** separated by $c in $s.
** Initiate $from with 0.
** That function have 3 loops :
** The First loop, end when it reach \0,
** two loops inside the first loop.
** The second loop continue moving if
** it don't find the separator and \0
** $upto store the index of the first separator
** found after normal characters.
** The third loop continue moving if
** it don't find a normal character and \0
** If $upto > $from that means we found
** a string that have at least one character
** that means we can increment $n
** $from store the index of the normal
** character after separators.
** return $n.
*/

static int	count_sarrsize(const char *s, char c)
{
	int	i;
	int	n;
	int	upto;
	int	from;

	i = 0;
	n = 0;
	from = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		upto = i;
		while (s[i] == c && s[i])
			i++;
		if (upto > from)
			n++;
		from = i;
	}
	return (n);
}

static void	split_worker(const char *s, int *i, int *upto, char c)
{
	while (s[*i] != c && s[*i])
		*i = *i + 1;
	*upto = *i;
	while (s[*i] == c && s[*i])
		*i = *i + 1;
}

/*
** The same as count_sarrsize()
** But instead of counting
** it copy to the array of string
** using ft_strallocpy();
** $k is used to index the array of strings
** return the array of strings
** If allocation fail, $n = -1
*/

static char	**splitstoarr(const char *s, char c, char **sarr)
{
	int	i;
	int	k;
	int	upto;
	int	from;

	i = 0;
	k = 0;
	from = 0;
	while (s[i])
	{
		split_worker(s, &i, &upto, c);
		if (upto > from)
		{
			sarr[k] = ft_strndup(s + from, upto - from);
			if (!sarr[k++])
				return (ft_free_sar(sarr));
		}
		from = i;
	}
	return (sarr);
}

/*
** Split $s into a array of strings separated
** by c
** First count the number of sub-strings
** then allocate the array of strings, + 1 to NULL terminate
** Call splitstoarr() to extract sub-strings from
** $s to $sarr
** If $n is affected by -1 after splitstoarr()
** free everything and return NULL.
** If not, NULL terminate the array by affecting the last case.
*/

char	**ft_split(const char *s, char c)
{
	int		sarrsize;
	char	**sarr;

	if (!s)
		return (NULL);
	sarrsize = count_sarrsize(s, c);
	sarr = (char **)malloc(sizeof(char *) * (sarrsize + 1));
	if (!sarr)
		return (NULL);
	sarr = splitstoarr(s, c, sarr);
	if (!sarr)
		return (NULL);
	sarr[sarrsize] = NULL;
	return (sarr);
}
