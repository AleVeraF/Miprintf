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
	int		i;

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

/*int main() {
    char *str = "NULL";
    int number = 42;
    unsigned int unsigned_number = 12345;
	int *ptr = &number;
	int *ptr2 = NULL;
    // Uso de ft_printf
    ft_printf("Prueba de ft_printf:\n");
    ft_printf("Cadena: %s\n", str);
    ft_printf("Número: %d\n", number);
    ft_printf("Número sin signo: %u\n", unsigned_number);
    ft_printf("Caracter: %c\n", 'A');
    ft_printf("Porcentaje: %%\n");
	ft_printf("Hexadecimal minuscula %x\n", 59);
	ft_printf("Hexadecimal mayuscula %X\n", 78);
	ft_printf("%X\n", -78);
	ft_printf("Puntero %p\n", ptr );
	ft_printf("Puntero %p\n",ptr2 );
    // Uso de printf para comparación
    printf("\nPrueba de printf:\n");
    printf("Cadena: %s\n", str);
    printf("Número: %d\n", number);
    printf("Número sin signo: %u\n", unsigned_number);
    printf("Caracter: %c\n", 'A');
    printf("Porcentaje: %%\n");
	printf("Hexadecimal minuscula %x\n", 59);
	printf("Hexadecimal mayuscula %X\n", 78 );
	printf("%X\n", -78);
	printf("Puntero %p\n", ptr );
	printf("Puntero %p\n",ptr2 );
    return 0;
}*/










