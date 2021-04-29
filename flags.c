/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:38:23 by rgreater          #+#    #+#             */
/*   Updated: 2021/01/09 20:17:10 by rgreater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

/*
** flag->padding contains the first flag (i.e. '0' or '-')
** |-1| stands for no flag
** | 0| stands for '0'
** | 1| stands for '-'
*/

void		flag_init(t_flags *flag)
{
	flag->padding = -1;
	flag->width = -1;
	flag->precision = -1;
}

static int	parse_minus_zero(t_flags *flag, const char **format)
{
	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
			flag->padding = 1;
		else if (flag->padding != 1)
			flag->padding = 0;
		(*format)++;
	}
	if (!**format)
		return (-1);
	return (0);
}

static int	parse_width(t_flags *flag, const char **format, va_list *ap)
{
	if (**format == '*')
	{
		flag->width = va_arg(*ap, int);
		if (flag->width < 0)
		{
			flag->width = -flag->width;
			flag->padding = 1;
		}
		(*format)++;
	}
	if ((**format >= '0') && (**format <= '9'))
	{
		flag->width = 0;
		while ((**format >= '0') && (**format <= '9'))
		{
			flag->width = flag->width * 10 + **format - 48;
			(*format)++;
		}
	}
	if (**format == '*')
		parse_width(flag, format, ap);
	if (!**format)
		return (-1);
	return (0);
}

static int	parse_precision(t_flags *flag, const char **format, va_list *ap)
{
	flag->precision = 0;
	(*format)++;
	if (**format == '*')
	{
		flag->precision = va_arg(*ap, int);
		(*format)++;
	}
	if ((**format >= '0') && (**format <= '9'))
	{
		flag->precision = 0;
		while ((**format >= '0') && (**format <= '9'))
		{
			flag->precision = flag->precision * 10 + **format - 48;
			(*format)++;
		}
	}
	if (**format == '*')
	{
		va_arg(*ap, int);
		(*format)++;
	}
	if (!**format)
		return (-1);
	return (0);
}

int			parse_flags(t_flags *flag, const char **format, va_list *ap)
{
	if (!**format)
		return (-1);
	flag_init(flag);
	if (parse_minus_zero(flag, format) == -1)
		return (-1);
	if (parse_width(flag, format, ap) == -1)
		return (-1);
	if (**format == '.')
		if (parse_precision(flag, format, ap) == -1)
			return (-1);
	return (0);
}
