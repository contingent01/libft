/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:26:19 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/08/10 13:03:08 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../../core/includes/libft.h"

# define BFZ 512

typedef struct		s_gnl
{
	char			*buf;
	int				fd;
}					t_gnl;

int					get_next_line(int fd, char **line);
int					ft_strallocat(char **dest, char *src);
char				*rep_newl_zero(char *s);
#endif
