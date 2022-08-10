/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:54:28 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/08/11 00:24:53 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	fdcmp(void *vgnl1, void *vfd2)
{
	t_gnl	*gnl1;
	int		*fd2;	

	gnl1 = (t_gnl *) vgnl1;
	fd2 = (int *)vfd2;
	if (gnl1->fd == *fd2)
		return (0);
	return (1);
}

t_gnl	*fdnew(int newfd)
{
	t_gnl	*new;

	new = malloc(sizeof(t_gnl));
	if (!new)
		return (NULL);
	new->buf = malloc(sizeof(char) * (BFZ + 1));
	new->buf[0] = '\0';
	new->fd = newfd;
	return (new);
}

/*
** Bonus version of get_next_line() :
** it manage multiple (fd) by using linked list.
**
** I use static (listf) pointer,
** this help to keep the list alive,
** so as to keep data left in buffer.
**
** First, if the (fd) value is used before,
** we use it, else we create new element.
**
** After that I use the same logic as
** basic GNL, just I changed the functions,
** of libft to save some lines of code.
** What is added and added in the case of read(),
** return 0 or -1, or some error with malloc(),
** or there is no character left, to use for next
** call, that means if (new) is NULL :
**
** Delete the current element that have
** that wrong fd.
*/

int		get_next_line(int fd, char **line)
{
	static t_list	*listf = NULL;
	ssize_t			ret;
	char			*new;
	t_list			*i;
	t_gnl			*f = NULL;

	if (!line)
		return (-1);
	i = ft_lstfind(listf, &fd, fdcmp);
	if (!i)
	{
		i = ft_lstnew(fdnew(fd));
		if (!i)
			return (-1);
		ft_lstadd_back(&listf, i);
	}
	f = i->content;
	*line = NULL;
	while (1)
	{
		new = rep_newl_zero(f->buf);
		*line = ft_strappend(*line, f->buf);
		ret = 1 * (line > 0) - 1 * (!line);
		if (new || ret == -1)
			break ;
		ret = read(fd, f->buf, BFZ);
		printf("ret = %zu\n", ret);
		if (ret <= 0)
			break ;
		f->buf[ret] = '\0';
		//printf("buf |%s|\n", f->buf);
	}
	
	if (ret == -1)
		*line = ft_free(*line);
	if (ret <= 0 || !new)
		ft_lstdel(&listf, i, NULL);
	if (ret > 0 && new)
		ft_strcpy(f->buf, new + 1);
	return (ret > 0 ? 1 : ret);
}

/*
** This function search for '\n',
** and replace it by '\0'.
*/

char	*rep_newl_zero(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] != '\0')
	{
		s[i] = '\0';
		return ((char *)&s[i]);
	}
	return (NULL);
}
