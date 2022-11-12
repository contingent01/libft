/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:55:47 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/11/12 19:56:37 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

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

void	fddel(void *vgnl)
{
	t_gnl	*f;

	f = (t_gnl *)vgnl;
	free(f->buf);
	free(f);
}

t_list	*find_add_fd(t_list **fdlst, int fd, t_gnl **f, char **line)
{
	t_list	*i;

	if (!line)
		return (NULL);
	i = ft_lstfind(*fdlst, &fd, fdcmp);
	if (!i)
	{
		i = ft_lstnew((void *)fdnew(fd));
		if (!i)
			return (NULL);
		ft_lstadd_front(fdlst, i);
	}
	*f = i->content;
	*line = NULL;
	return (i);
}

int	gnl_append(ssize_t *ret, char **new, char *buf, char **line)
{
	*new = ft_strepchr(buf, '\n', '\0');
	*line = ft_strappend(*line, buf);
	if (!*line)
	{
		*ret = -1;
		return (0);
	}
	else
		*ret = 1;
	if (*new)
		return (0);
	return (1);
}
