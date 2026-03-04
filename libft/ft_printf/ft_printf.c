/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:35:15 by selow             #+#    #+#             */
/*   Updated: 2025/08/09 20:39:58 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_fd(int fd, const char *format, ...);
int	handle_format(const char **format, va_list ap, int fd);
int	put_c(char c, int fd);
int	ft_putnbr(long n, int fd);
int	put_s(char *str, int fd);
int	put_p(void *ptr, int fd);
int	put_u(unsigned int n, int fd);
int	put_x(unsigned int n, int fd);
int	put_big_x(unsigned int n, int fd);

int	ft_printf_fd(int fd, const char *format, ...)
{
	int		count;
	va_list	ap;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += handle_format(&format, ap, fd);
		else
		{
			write(fd, format, 1);
			count++;
		}
		format++;
	}
	va_end(ap);
	return (count);
}

int	handle_format(const char **format, va_list ap, int fd)
{
	int	count;

	(*format)++;
	count = 0;
	if (**format == 's')
		count += put_s(va_arg(ap, char *), fd);
	else if (**format == 'c')
		count += put_c(va_arg(ap, int), fd);
	else if (**format == 'i' || **format == 'd')
		count += ft_putnbr(va_arg(ap, int), fd);
	else if (**format == 'p')
		count += put_p(va_arg(ap, char *), fd);
	else if (**format == 'u')
		count += put_u(va_arg(ap, unsigned int), fd);
	else if (**format == 'x')
		count += put_x(va_arg(ap, unsigned int), fd);
	else if (**format == 'X')
		count += put_big_x(va_arg(ap, unsigned int), fd);
	else if (**format == '%')
		count += write(fd, "%", 1);
	return (count);
}

// simple put functions =======
int	put_s(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str)
		return (write(fd, "(null)", 6));
	while (str[i])
	{
		write(fd, &str[i++], 1);
	}
	return (i);
}

int	put_c(char c, int fd)
{
	return (write(fd, &c, 1));
}
// put functions ^^^ =====
