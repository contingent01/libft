/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdkhissi <mdkhissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:23:31 by mdkhissi          #+#    #+#             */
/*   Updated: 2022/07/29 16:09:03 by mdkhissi         ###   ########.fr       */
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
}				t_tags;

int		append_text(char **s, const char *format, int *i, int count);
void	print_s_fd(char **dest, char *s, int fd);
int		ft_printf(char **dest, int fd, const char *format, ...);

void	sign_0x(char **bigStr, long n, t_tags *tags, int r);
void	reinit_flags(t_tags *tags);
char	*extract_var(char *param, va_list *vl, t_tags *tags);
char	*parse_param(const char *format, int *i, va_list *vl, t_tags *tags);

size_t	ft_strlen(const char *s);
int		ft_toupper(int c);
bool	ft_isdigit(const char c);
int		ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

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

int		ft_atoi(const char *str);
char	*ft_itoa_ws(long n);
void	ft_itox_worker(uintptr_t nbr, char *s, int i, int *count);
char	*ft_itox(uintptr_t n);
void	calculate_i_div_count(long n, long *div, int *count);

char	*format_x(unsigned int n, t_tags *tags);
char	*format_c(char c, t_tags *tags);
char	*format_s(char *src, t_tags *tags);
char	*format_p(uintptr_t n, t_tags *tags);
char	*format_idu(long n, t_tags *tags);

void	ft_strncpy(char *dest, const char *src, size_t n);
void	ft_strnallocat(char **dest, const char *src, int n, int r);
void	*ft_memset(void *s, int c, size_t n);
int		ft_strchr(const char c, const char *str);
char	*str_capitalize(char *str);;
#endif
