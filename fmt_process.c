/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 20:12:30 by rgreater          #+#    #+#             */
/*   Updated: 2021/01/09 20:15:45 by rgreater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static int	str_print(char *str, int *i)
{
	int len;

	len = ft_putstr(str, *i);
	*i = 0;
	return (len);
}

static int	str_add(char *str, int *i, const char c)
{
	int len;

	len = 0;
	if (*i == BUF_SIZE)
		len = str_print(str, i);
	str[*i] = c;
	*i += 1;
	return (len);
}

int			fmt_process(va_list *ap, const char *format)
{
	char	str[BUF_SIZE];
	int		i;
	int		len;
	t_flags	flag;

	i = 0;
	len = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			len += str_print(str, &i);
			format++;
			if (parse_flags(&flag, &format, ap) == -1)
				return (-1);
			if (parse_spec(&flag, *format, ap, &len) == -1)
				return (-1);
			flag_init(&flag);
		}
		else
			len += str_add(str, &i, *format);
		format++;
	}
	len += str_print(str, &i);
	return (len);
}
