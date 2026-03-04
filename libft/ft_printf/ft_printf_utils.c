/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:22:13 by selow             #+#    #+#             */
/*   Updated: 2025/08/09 20:42:53 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_x(unsigned int n, int fd)
{
	char			*hex;
	char			buffer[21];
	int				i;
	unsigned long	num;

	if (n == 0)
		return (write(fd, "0", 1));
	num = (unsigned long)n;
	hex = "0123456789abcdef";
	i = 20;
	buffer[i--] = '\0';
	while (num)
	{
		buffer[i--] = hex[num % 16];
		num /= 16;
	}
	return (put_s(&buffer[i + 1], fd));
}

int	put_big_x(unsigned int n, int fd)
{
	char			*hex;
	char			buffer[21];
	int				i;
	unsigned long	num;

	if (n == 0)
		return (write(fd, "0", 1));
	num = (unsigned long)n;
	hex = "0123456789ABCDEF";
	i = 20;
	buffer[i--] = '\0';
	while (num)
	{
		buffer[i--] = hex[num % 16];
		num /= 16;
	}
	return (put_s(&buffer[i + 1], fd));
}

int	put_p(void *ptr, int fd)
{
	char			*hex;
	char			buffer[19];
	int				i;
	unsigned long	p;

	p = (unsigned long)ptr;
	hex = "0123456789abcdef";
	if (p == 0)
		return (write(fd, "(nil)", 5));
	i = 19;
	buffer[i--] = '\0';
	while (p)
	{
		buffer[i--] = hex[p % 16];
		p /= 16;
	}
	buffer[i--] = 'x';
	buffer[i] = '0';
	return (put_s(&buffer[i], fd));
}
