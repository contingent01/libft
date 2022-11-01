/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:23:31 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/10/23 19:24:10 by mdkhissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdint.h>
# include "../../core/includes/libft.h"

# define N_LEN 2
# define MAX 30

static const char	g_specifiers[] = "cspdiuxX%";
static const char	g_flags[] = "+ -0#";

typedef struct s_tags
{
	int			len;
	int			nil;
	char		specifier;
	char		sign;
	char		justify;
	bool		zerow;
	int			width;
	int			precision;
	char		*tmp;
}				t_tags;

int		append_text(char **s, const char *format, int *i, int count);
void	print_s_fd(char **dest, char *s, int fd, int len);
int		ft_vprintf(char **dest, int fd, const char *format, va_list args);
int		ft_printf(const char *format, ...);

void	sign_0x(char **bigStr, long n, t_tags *tags, int r);
void	reinit_flags(t_tags *tags);
char	*extract_var(char *param, va_list *vl, t_tags *tags);
char	*parse_param(const char *format, int *i, va_list *vl, t_tags *tags);

void	s_precision(char **bigStr, t_tags *tags);
void	s_width(char **bigStr, long n, t_tags *tags);
void	s_justify(char **bigStr, char *s, t_tags *tags);
char	*s_sign(long n, char tagsign);
char	*s_0x(t_tags *tags);

void	extract_flags(const char *format, int *i, t_tags *tags);
void	extract_width(const char *format, int *i, va_list *vl, t_tags *tags);
void	extract_precisio(const char *format, int *i, va_list *vl, t_tags *tags);
bool	extract_specifier(const char *format, int *i, t_tags *tags);
bool	extract_tags(const char *format, int *i, va_list *vl, t_tags *tags);

char	*ft_itoa_ws(long n);
void	ft_itox_worker(uintptr_t nbr, char *s, int i, int *count);
char	*ft_itox(uintptr_t n);
void	calculate_i_div_count(long n, long *div, int *count);

char	*format_x(unsigned int n, t_tags *tags);
char	*format_c(char c, t_tags *tags);
char	*format_s(char *src, t_tags *tags);
char	*format_p(uintptr_t n, t_tags *tags);
char	*format_idu(long n, t_tags *tags);

char	*str_capitalize(char *str);;
char	*ft_strnrappend(char *s1, const char *s2, size_t n, int r);
char	*ft_strrappend(char *s1, const char *s2, int r);

char	*append_value(char *s1, const char *s2, size_t s1len, size_t s2len);
void	ft_putnstr_fd(char *s, size_t len, int fd);

int		ft_sprintf(char **dest, const char *format, ...);
int		ft_peprintf(const char *format, ...);
int		ft_fprintf(int fd, const char *format, ...);

#endif
