/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 22:17:15 by selow             #+#    #+#             */
/*   Updated: 2025/10/29 14:40:52 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
	splits a string of numbers separated by a separator,
	and includes them into an int array. 
	
	Returns NULL if one element contains something that isnt a number.
*/

static int	*fill_int_arr(const char *s, char sep, int *arr)
{
	const char	*p;
	int			i;

	p = s;
	i = 0;
	while (*p)
	{
		while (*p && *p == sep)
			p++;
		if (!(*p))
			break ;
		arr[i++] = ft_atoi(p);
		while (*p && *p != sep)
			p++;
	}
	return (arr);
}

int	*split_atoi(const char *s, char sep, int *out_len)
{
	int			count;
	const char	*p;
	int			*arr;

	if (!s || !*s)
		return (NULL);
	count = 0;
	p = s;
	*out_len = 0;
	while (*p)
	{
		while (*p && *p == sep)
			p++;
		if (*p)
		{
			count++;
			while (*p && *p != sep)
				p++;
		}
	}
	arr = malloc(sizeof(int) * count);
	if (!arr)
		return (NULL);
	*out_len = count;
	return (fill_int_arr(s, sep, arr));
}
