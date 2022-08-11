/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:26:19 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/08/11 22:51:30 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "../core/includes/libft.h"

# define BFZ BUFFER_SIZE

typedef struct		s_gnl
{
	char			*buf;
	int				fd;
}					t_gnl;

int					get_next_line(int fd, char **line);
char				*rep_newl_zero(char *s);
#endif
