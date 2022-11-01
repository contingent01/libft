/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:26:19 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/10/23 19:59:39 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../../core/includes/libft.h"

# define BFZ BUFFER_SIZE

typedef struct		s_gnl
{
	char			*buf;
	int				fd;
}					t_gnl;

int		fdcmp(void *vgnl1, void *vfd2);
t_gnl*	fdnew(int newfd);
void	fddel(void* vgnl);
t_list*	find_add_fd(t_list** fdlst, int fd);
void	printfd(void *content);
char*	get_next_line(int fd);

#endif
