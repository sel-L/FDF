/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:16:36 by selow             #+#    #+#             */
/*   Updated: 2025/08/09 20:36:20 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits_and_neg(long n)
{
	int	ndigits;

	ndigits = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
	{
		ndigits += 1;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		ndigits += 1;
	}
	return (ndigits);
}

static char	*fill_str(long num, char *new, int len)
{
	if (num == 0)
	{
		new[len] = '0';
		return (new);
	}
	if (num < 0)
	{
		new[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		new[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (new);
}

int	ft_putnbr(long n, int fd)
{
	int		len;
	char	*str;

	len = ft_count_digits_and_neg(n);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	str[len] = '\0';
	fill_str(n, str, len - 1);
	write(fd, str, len);
	return (free(str), len);
}
