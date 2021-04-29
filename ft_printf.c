/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:53:00 by rgreater          #+#    #+#             */
/*   Updated: 2021/01/09 20:17:38 by rgreater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		res;

	if (!format)
		return (0);
	va_start(ap, format);
	res = fmt_process(&ap, format);
	va_end(ap);
	if (res < 0)
		return (0);
	return (res);
}
