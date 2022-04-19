/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcakirog <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:59:22 by kcakirog          #+#    #+#             */
/*   Updated: 2022/03/29 13:30:33 by kcakirog         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	to_what(char c, va_list list)
{	
	int	i;

	i = 0;
	if (c == 'd' || c == 'i')
		i += ft_putnbr(va_arg(list, int));
	else if (c == 'c')
		i += ft_putchar(va_arg(list, int));
	else if (c == 's')
		i += ft_putstr(va_arg(list, char *));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		i += ft_hexadecimal(va_arg(list, unsigned long), 0) + 2;
	}
	else if (c == 'u')
		i += ft_putnbr(va_arg(list, unsigned int));
	else if (c == 'x')
		i += ft_hexadecimal(va_arg(list, unsigned int), 0);
	else if (c == 'X')
		i += ft_hexadecimal(va_arg(list, unsigned int), 1);
	else if (c == '%')
		i += write(1, "%", 1);
	return (i);
}

int	ft_printf(const char *ptr, ...)
{	
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, ptr);
	count = 0;
	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == '%')
		{
			count += to_what(ptr[i + 1], ap);
			i++;
		}
		else
		count += write(1, &ptr[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
