/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:46:20 by selow             #+#    #+#             */
/*   Updated: 2025/10/27 20:46:23 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_message(char *s, int exit_code)
{
	ft_printf_fd(2, s);
	exit(exit_code);
}

void	error_message_free(char *s, int exit_code, t_vars *vars)
{
	ft_printf_fd(2, s);
	free_vars(vars);
	exit(exit_code);
}

void	fill_background(t_vars *vars, int color)
{
	int	x;
	int	y;

	y = 0;
	while (++y < WIN_HEIGHT)
	{
		x = 0;
		while (++x < WIN_WIDTH)
			put_pixel(vars, x, y, color);
	}
}
