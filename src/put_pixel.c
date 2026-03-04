/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:32:01 by selow             #+#    #+#             */
/*   Updated: 2025/11/11 20:32:06 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_vars *vars, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		i = (x * vars->img.bits_per_pixel / 8) + (y * vars->img.line_len);
		vars->img.addrs[i] = color;
		vars->img.addrs[++i] = color >> 8;
		vars->img.addrs[++i] = color >> 16;
	}
}
