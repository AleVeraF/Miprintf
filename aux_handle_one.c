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

int	ft_putnbr_u(unsigned int n, int fd)
{
	int	i;

	i = 0;
	if (n >= 10)
		i += ft_putnbr_u(n / 10, fd);
	ft_putchar_fd((n % 10 + '0'));
	i++;
	return (i);
}

int	handle_u(va_list args)
{
	unsigned int	num;
	int				len;
	unsigned int	temp;

	num = va_arg(args, unsigned int);
	len = 0;
	temp = num;
	if (num == 0)
		len = 1;
	while (temp != '\0')
	{
		temp /= 10;
		len++;
	}
	ft_putnbr_u(num, 1);
	return (len);
}

int	handle_x(va_list args, char a)
{
	unsigned int	num;
	int				len;

	len = 0;
	num = va_arg(args, unsigned int);
	if (a == 'x')
		len += ft_putnbr_base(num, "0123456789abcdef");
	else if (a == 'X')
		len += ft_putnbr_base(num, "0123456789ABCDEF");
	return (len);
}
