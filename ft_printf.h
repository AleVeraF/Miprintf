/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:56:39 by alvera-f          #+#    #+#             */
/*   Updated: 2024/10/12 16:42:12 by alvera-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putnbr_base(unsigned long n, char *base);
int	ft_putnbr_fd(long n, int fd);
size_t	ft_strlen(const char *str);
int	ft_putstr_fd(char *s, int fd);
int	ft_printf(char const *format, ...);
int	ft_putchar_fd(char c);
int	handle_s(va_list args);
int	handle_d_i(va_list args);
int	handle_x_p(va_list args, char a);
int	handle_format(char const format, va_list args);
int	ft_putnbr_u(unsigned int n, int fd);
int	handle_u(va_list args);



#endif
