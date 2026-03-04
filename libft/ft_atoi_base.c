/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:07:11 by selow             #+#    #+#             */
/*   Updated: 2025/11/07 15:07:13 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_to_val(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (-1);
}

static const char	*parse_prefix(const char *str, int base, int *sign)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	*sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	if (base == 16 && str[0] == '0'
		&& (str[1] == 'x' || str[1] == 'X'))
		str += 2;
	return (str);
}

int	ft_atoi_base(const char *str, int base)
{
	int	result;
	int	sign;
	int	val;

	if (!str || base < 2 || base > 16)
		return (0);
	str = parse_prefix(str, base, &sign);
	while (*str)
	{
		val = ft_char_to_val(*str);
		if (val < 0 || val >= base)
			break ;
		result = result * base + val;
		str++;
	}
	return (result * sign);
}
