/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:47:30 by alvera-f          #+#    #+#             */
/*   Updated: 2024/10/12 17:05:06 by alvera-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, char *base)
{
	unsigned int	base_len;
	int				i;

	i = 0;
	base_len = ft_strlen(base);
	if (n >= base_len)
		i += ft_putnbr_base(n / base_len, base);
	ft_putchar_fd((base[n % base_len]));
	i++;
	return (i);
}

int	ft_putnbr_fd(long n, int fd)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		ft_putchar_fd('-');
		i++;
		n = -n;
	}
	if (n >= 10)
		i += ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10 + '0'));
	i++;
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		i += ft_putstr_fd("(null)", fd);
		return (i);
	}
	while (s[i])
	{
		ft_putchar_fd(s[i]);
		i++;
	}
	return (i);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	size_t	len;
	int	i;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			len += handle_format(format[i], args);
		}
		else
			len += ft_putchar_fd(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
