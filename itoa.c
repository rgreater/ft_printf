/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 17:48:29 by rgreater          #+#    #+#             */
/*   Updated: 2021/01/09 20:08:27 by rgreater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static int	ft_getlen(size_t n, int div)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= div;
		len++;
	}
	return (len);
}

char		*ft_itoa(long int n)
{
	char			*str;
	int				len;
	int				sign;
	unsigned long	num;

	sign = (n >= 0) ? 0 : 1;
	num = (n >= 0) ? n : -n;
	len = ft_getlen(num, 10) + sign;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len--] = 0;
	while (len >= 0 + sign)
	{
		str[len--] = num % 10 + 48;
		num /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

char		*ft_itoa_unsigned(unsigned long n)
{
	char	*str;
	int		len;

	len = ft_getlen(n, 10);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len--] = 0;
	while (len >= 0)
	{
		str[len] = n % 10 + 48;
		len--;
		n = n / 10;
	}
	return (str);
}

static char	to_hex(unsigned long n, int c_case)
{
	int ascii_val;

	if (n < 10)
		return (n + 48);
	if (c_case == 0)
		ascii_val = 87;
	else
		ascii_val = 55;
	return (n + ascii_val);
}

char		*ft_itoa_hex(unsigned long n, int c_case)
{
	char	*str;
	int		len;

	len = ft_getlen(n, 16);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len--] = 0;
	while (len >= 0)
	{
		str[len--] = to_hex(n % 16, c_case);
		n /= 16;
	}
	return (str);
}
