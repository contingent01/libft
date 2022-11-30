/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:00:21 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/11/27 00:08:55 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

// 	return (1 * (ret > 0) + ret * (ret <= 0));

int	get_next_line(int fd, char **line)
{
	static t_list	*fdlst = NULL;
	t_list			*i;
	t_gnl			*f;
	ssize_t			ret;
	char			*new;

	i = find_add_fd(&fdlst, fd, &f, line);
	if (!i)
		return (-1);
	while (1)
	{
		if (!gnl_append(&ret, &new, f->buf, line))
			break ;
		ret = read(fd, f->buf, BFZ);
		if (ret <= 0)
			break ;
		f->buf[ret] = '\0';
	}
	if (ret == -1)
		*line = ft_free(*line);
	if (ret <= 0 || !new)
		ft_lstdel(&fdlst, i, fddel);
	if (ret > 0)
		ft_strcpy(f->buf, new + 1);
	return (1 * (ret > 0) + ret * (ret <= 0));
}

int	gnl_filled(int fd, char **line)
{
	ssize_t	ret;

	if (!line)
		return (-1);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, line);
		if (*line && **line != '\0')
			break ;
		*line = ft_free(*line);
	}
	return (ret);
}
