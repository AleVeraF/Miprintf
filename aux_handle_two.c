/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_handle_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:56:12 by alvera-f          #+#    #+#             */
/*   Updated: 2024/10/12 16:49:01 by alvera-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c)
{
	write (1, &c, 1);
	return (1);
}

int	handle_s(va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (len);
}

int	handle_d_i(va_list args)
{
	int	num;
	int	len;
	int	temp;

	num = va_arg(args, int);
	len = 0;
	temp = num;
	if (num == 0)
		len = 1;
	else if (num < 0)
		len++;
	while (temp != '\0')
	{
		temp /= 10;
		len++;
	}
	ft_putnbr_fd(num, 1);
	return (len);
}

int	handle_p(va_list args)
{
	void	*ptr;
	int		len;

	len = 0;
	ptr = va_arg(args, void *);
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		len += 2;
		len += ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
	}
	return (len);
}

int	handle_format(char const format, va_list args)
{
	int	c;
	int	printed_chars;

	printed_chars = 0;
	if (format == 'd' || format == 'i')
		printed_chars += handle_d_i(args);
	else if (format == 'u')
		printed_chars += handle_u(args);
	else if (format == 's')
		printed_chars += handle_s(args);
	else if (format == 'c')
	{
		c = va_arg(args, int);
		printed_chars += ft_putchar_fd(c);
	}
	else if (format == 'p')
		printed_chars += handle_p(args);
	else if (format == 'x' || format == 'X')
		printed_chars += handle_x(args, format);
	else if (format == '%')
		printed_chars += ft_putchar_fd('%');
	return (printed_chars);
}
