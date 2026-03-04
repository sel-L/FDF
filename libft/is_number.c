/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:44:17 by selow             #+#    #+#             */
/*   Updated: 2025/10/29 14:45:56 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_number(const char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	if (!*s)
		return (false);
	if (*s < '0' || *s > '9')
		return (false);
	while (*s)
	{
		if (*s == ' ')
			break ;
		if (*s < '0' || *s > '9')
			return (false);
		s++;
	}
	return (true);
}
