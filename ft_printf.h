/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcakirog <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:53:11 by kcakirog          #+#    #+#             */
/*   Updated: 2022/03/28 20:17:39 by kcakirog         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *ptr, ...);
int	to_what(char c, va_list list);
int	ft_hexadecimal(long double hex_number, int is_upper);
int	ft_putchar(char c);
int	ft_putnbr(long double n);
int	ft_putstr(char *s);

#endif
