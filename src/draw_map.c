/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:57:30 by selow             #+#    #+#             */
/*   Updated: 2025/10/31 00:57:30 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dda(double x0, double y0, t_vars *vars)
{
	double	x_step;
	double	y_step;
	int		max;

	x_step = vars->coord.x1 - x0; // dx
	y_step = vars->coord.y1 - y0; // dy
	max = ft_max(ft_fabs(x_step), ft_fabs(y_step));
	x_step /= max;
	y_step /= max;
	while (ft_fabs(x0 - vars->coord.x1) > 1 || ft_fabs(y0 - vars->coord.y1) > 1)
	{
		if (x0 < WIN_WIDTH && y0 < WIN_HEIGHT && x0 > 0 && y0 > 0)
		{
			if (vars->map.colored[vars->coord.ori_y0][vars->coord.ori_x0] != -1)
				put_pixel(vars, x0, y0,
					vars->map.colored[vars->coord.ori_y0][vars->coord.ori_x0]);
			else
				put_pixel(vars, x0, y0, LINE_COLOUR);
		}
		x0 += x_step;
		y0 += y_step;
	}
}

void	isometric(double *x, double *y, double z)
{
	double	prev_x;
	double	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(ANGLE);
	*y = (prev_x + prev_y) * sin(ANGLE) - z;
}
// xyz -> xy
void	convert_to_2d(double *x, double *y, double *z, t_vars *vars)
{
	*z = vars->map.map[(int)*y][(int)*x];
	*z *= vars->magnify;
	*z *= H_SCALE;
	*y *= vars->magnify;
	*x *= vars->magnify;
	isometric(x, y, *z);
}

void	draw_line(double x0, double y0, t_vars *vars)
{
	double		z0;
	double		z1;

	vars->coord.ori_x0 = (int)x0;
	vars->coord.ori_y0 = (int)y0;
	convert_to_2d(&x0, &y0, &z0, vars);
	convert_to_2d(&vars->coord.x1, &vars->coord.y1, &z1, vars);
	x0 += H_MOVE;
	y0 += V_MOVE;
	vars->coord.x1 += H_MOVE;
	vars->coord.y1 += V_MOVE;
	dda(x0, y0, vars);
}

void	draw_map(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (y < vars->map.height)
	{
		x = 0;
		while (x < vars->map.width)
		{
			if (x < vars->map.width - 1)
			{
				vars->coord.x1 = x + 1;
				vars->coord.y1 = y;
				draw_line(x, y, vars);
			}
			if (y < vars->map.height - 1)
			{
				vars->coord.x1 = x;
				vars->coord.y1 = y + 1;
				draw_line(x, y, vars);
			}
			x++;
		}
		y++;
	}
}
