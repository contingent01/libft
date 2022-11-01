/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:54:28 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/10/24 22:14:13 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
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
	if (!new->buf)
		return (NULL);
	new->buf[0] = '\0';
	new->buf[BFZ] = '\0';
	new->fd = newfd;
	return (new);
}

void	fddel(void* vgnl)
{
	t_gnl*	f;

	f = (t_gnl *)vgnl;
	free(f->buf);
	free(f);
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

t_list*	find_add_fd(t_list** fdlst, int fd)
{
	t_list*	i;

	i = ft_lstfind(*fdlst, &fd, fdcmp);
	if (!i)
	{
		i = ft_lstnew((void *)fdnew(fd));
		if (!i)
			return (NULL);
		ft_lstadd_front(fdlst, i);
	}
	return (i);
}

void	printfd(void* content)
{
	t_gnl*	g;

	g = (t_gnl*) content;
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("fd = ", 1);
	ft_putnbr_fd(g->fd, 1);
	ft_putchar_fd('\t', 1);
	ft_putstr_fd("buf = ", 1);
	ft_putstr_fd(g->buf, 1);
	ft_putchar_fd('\n', 1);
}

ssize_t	cat_buf_to_line(char** line, char* buf)
{
	char*	new;

	new = ft_strchr(buf, '\n');
	if (new)
		*line = ft_strnappend(*line, buf, new - buf + 1);
	else
		*line = ft_strappend(*line, buf);
	if (!*line)
		return (-1);
	if (!new)
		return (-1);
	if (*line)
		return (1);
	if (new)
	{
		ft_strcpy(buf, new + 1);
		return (1);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_list*	fdlst = NULL;
	t_list*			i;
	t_gnl*			f;
	ssize_t			ret;
	char*			line;

	//ft_lstiter(fdlst, printfd);
	i = find_add_fd(&fdlst, fd);
	f = i->content;
	line = NULL;
	while (1)
	{
		ret = cat_buf_to_line(&line, f->buf);
		if (ret == -1)
			break ;
		ret = read(fd, f->buf, BFZ);
		if (ret <= 0)
			break ;
		f->buf[ret] = '\0';
	}
	//printf("\n\t\tline = %s\n", line);
	if (ret <= 0)
		ft_lstdel(&fdlst, i, fddel);
	if (ret == -1)
		return (ft_free(line));
	if (!*line && ret == 0)
		return (ft_free(line));
	return (line);
}
