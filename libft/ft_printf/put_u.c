/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:33:05 by selow             #+#    #+#             */
/*   Updated: 2025/08/09 20:40:36 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits(unsigned int n)
{
	int	ndigits;

	ndigits = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n > 0)
	{
		n /= 10;
		ndigits += 1;
	}
	return (ndigits);
}

static char	*fill_str(unsigned int long num, char *new, int len)
{
	if (num == 0)
	{
		new[len] = '0';
		return (new);
	}
	while (num > 0)
	{
		new[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (new);
}

int	put_u(unsigned int n, int fd)
{
	int					len;
	char				*str;
	unsigned int long	num;

	num = (unsigned int long)n;
	len = ft_count_digits(num);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	str[len] = '\0';
	fill_str(num, str, len - 1);
	write(fd, str, len);
	return (free(str), len);
}
