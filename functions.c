/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcakirog <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:37:35 by kcakirog          #+#    #+#             */
/*   Updated: 2022/03/29 12:56:45 by kcakirog         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_hexadecimal(long double hex_number, int is_upper)
{
	int	count;

	count = 1;
	if (hex_number > 15)
	{
		count += ft_hexadecimal((unsigned long long)hex_number / 16, is_upper);
	}
	if (is_upper)
	{
		write(1, &"0123456789ABCDEF"[(unsigned long long)hex_number % 16], 1);
	}
	else
		write(1, &"0123456789abcdef"[(unsigned long long)hex_number % 16], 1);
	return (count);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(long double n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		n = n * -1;
		write(1, "-", 1);
		count++;
	}
	if (n >= 0)
	{
		if (n > 9)
		{
			count += ft_putnbr((unsigned long)n / 10);
		}
		write(1, &"0123456789"[(unsigned long)n % 10], 1);
	}
	return (count);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
