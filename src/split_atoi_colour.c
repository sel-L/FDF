/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_atoi_colour.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:46:33 by selow             #+#    #+#             */
/*   Updated: 2025/11/07 15:46:35 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// checks for a comma and returns 0 if none found
// returns where the comma's position is

static int	get_comma_pos(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != ',')
		i++;
	if (s[i] == ',')
		return (i);
	return (-1);
}

static int	*fill_int_arr(const char *s, int *arr)
{
	int			i;
	const char	*p;
	int			comma;

	i = 0;
	p = s;
	while (*p)
	{
		while (*p == ' ')
			p++;
		if (!*p)
			break ;
		comma = get_comma_pos(p);
		if (comma >= 0)
			arr[i++] = ft_atoi_base(p + comma + 1, 16);
		else
			arr[i++] = -1;
		while (*p && *p != ' ')
			p++;
	}
	return (arr);
}

int	*split_atoi_colour(const char *s)
{
	int			count;
	const char	*p;
	int			*arr;

	count = 0;
	p = s;
	while (*p)
	{
		while (*p == ' ')
			p++;
		if (*p)
		{
			count++;
			while (*p && *p != ' ')
				p++;
		}
	}
	arr = malloc(sizeof(int) * count);
	if (!arr)
		return (NULL);
	return (fill_int_arr(s, arr));
}
