/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:49:30 by rgreater          #+#    #+#             */
/*   Updated: 2021/01/09 20:42:50 by rgreater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H
# ifndef BUF_SIZE
#  define BUF_SIZE 256
# endif
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_flags
{
	int			padding;
	int			width;
	int			precision;
}				t_flags;

int				fmt_process(va_list *ap, const char *format);
int				parse_flags(t_flags *flag, const char **format, va_list *ap);
int				parse_spec(t_flags *flag, const char c, va_list *ap,
															int *res_len);
int				add_str(char **s1, char *s2, t_flags *flag);
int				add_numstr(char **s1, char *s2, t_flags *flag);
int				get_max(int n1, int n2);
int				ft_strlen(const char *s);
int				get_width(t_flags flag, int len, int sign);
int				ft_putstr(char *str, int len);
char			*ft_itoa(long int n);
char			*ft_itoa_unsigned(unsigned long n);
char			*ft_itoa_hex(unsigned long n, int c_case);
char			*format_numstr(char **str, t_flags flag, int ptr);
char			*format_string(char *str, t_flags flag);
char			*format_char(char c, t_flags flag, int *res_len);
void			flag_init(t_flags *flag);

#endif
