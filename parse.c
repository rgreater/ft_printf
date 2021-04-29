/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 23:47:06 by rgreater          #+#    #+#             */
/*   Updated: 2021/01/09 20:18:23 by rgreater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static char	*parse_numbers(t_flags *flag, const char c, va_list *ap)
{
	char	*s;
	int		ptr;

	ptr = (c == 'p') ? 1 : 0;
	if (c == 'u')
		s = ft_itoa_unsigned(va_arg(*ap, unsigned int));
	else if (c == 'x')
		s = ft_itoa_hex(va_arg(*ap, unsigned int), 0);
	else if (c == 'X')
		s = ft_itoa_hex(va_arg(*ap, unsigned int), 1);
	else if (c == 'p')
		s = ft_itoa_hex(va_arg(*ap, uintptr_t), 0);
	else
		s = ft_itoa(va_arg(*ap, int));
	return (format_numstr(&s, *flag, ptr));
}

int			parse_spec(t_flags *flag, const char c, va_list *ap, int *res_len)
{
	char	*s;
	int		len;

	if (c == '%')
		s = format_char('%', *flag, &len);
	else if (c == 'c')
		s = format_char(va_arg(*ap, int), *flag, &len);
	else if (c == 's')
		s = format_string(va_arg(*ap, char *), *flag);
	else if (c == 'd' || c == 'i' || c == 'u' ||
				c == 'x' || c == 'X' || c == 'p')
		s = parse_numbers(flag, c, ap);
	else
		return (0);
	if (!s)
		return (0);
	if (c != 'c')
		len = ft_strlen(s);
	*res_len += ft_putstr(s, len);
	free(s);
	return (0);
}
