/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 00:29:45 by rgreater          #+#    #+#             */
/*   Updated: 2021/01/09 21:01:31 by rgreater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static void	fill_ptr(char *str, int *i)
{
	str[*i] = '0';
	str[*i + 1] = 'x';
	*i += 2;
}

static char	*format_number(char *res, char *str, t_flags flag, int ptr)
{
	int		sign;
	int		width;
	int		i;

	sign = (*str == '-') ? 1 : 0;
	str += sign;
	width = get_width(flag, ft_strlen(str), sign);
	i = 0;
	if (flag.padding == -1 || (flag.padding == 0 && flag.precision >= 0))
		while (i + sign + ptr * 2 < width)
			res[i++] = ' ';
	if (sign)
		res[i++] = '-';
	if (ptr)
		fill_ptr(res, &i);
	while ((flag.padding == 0) && (flag.precision < 0) && (i < width))
		res[i++] = '0';
	while (flag.precision-- > (ft_strlen(str)))
		res[i++] = '0';
	while (*str)
		res[i++] = *str++;
	while ((flag.padding == 1) && (width-- > sign + ptr * 2))
		res[i++] = ' ';
	res[i] = 0;
	return (res);
}

char		*format_numstr(char **str, t_flags flag, int ptr)
{
	char	*res;
	int		len;

	if (!*str)
		return (0);
	len = get_max(get_max(flag.width, flag.precision), ft_strlen(*str));
	if (!(res = malloc(sizeof(char) * (len + ptr * 2 + 1))))
		return (0);
	if (flag.precision == 0 && *str[0] == '0')
		*str[0] = 0;
	res = format_number(res, *str, flag, ptr);
	free(*str);
	return (res);
}

char		*format_string(char *str, t_flags flag)
{
	int			width;
	int			len;
	int			i;
	char		*res;

	if (!str)
		str = "(null)";
	len = ((flag.precision > -1) && (flag.precision < ft_strlen(str))) ?
										flag.precision : ft_strlen(str);
	width = (flag.width > len) ? (flag.width - len) : 0;
	if (!(res = malloc(sizeof(char) * (width + len + 1))))
		return (0);
	i = 0;
	while ((flag.padding == -1) && (i < width))
		res[i++] = ' ';
	while ((flag.padding == 0) && (i < width))
		res[i++] = '0';
	while (*str && len-- > 0)
		res[i++] = *str++;
	while ((flag.padding == 1) && (width-- > 0))
		res[i++] = ' ';
	res[i] = 0;
	return (res);
}

char		*format_char(char c, t_flags flag, int *res_len)
{
	int			width;
	int			i;
	char		*res;

	width = (flag.width > 1) ? (flag.width - 1) : 0;
	if (!(res = malloc(sizeof(char) * (width + 1 + 1))))
		return (0);
	i = 0;
	while ((flag.padding == -1) && (i < width))
		res[i++] = ' ';
	while ((flag.padding == 0) && (i < width))
		res[i++] = '0';
	res[i++] = c;
	while ((flag.padding == 1) && (width-- > 0))
		res[i++] = ' ';
	res[i] = 0;
	*res_len = i;
	return (res);
}
