/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:47:13 by rgreater          #+#    #+#             */
/*   Updated: 2021/01/09 20:42:30 by rgreater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	get_max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

int	get_width(t_flags flag, int len, int sign)
{
	int width;

	width = 0;
	if (flag.width > len)
	{
		if (flag.precision > len - sign)
			width = flag.width - flag.precision;
		else
			width = flag.width - len;
	}
	return (width);
}
