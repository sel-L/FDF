/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:36:37 by selow             #+#    #+#             */
/*   Updated: 2025/10/31 00:36:38 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_vars(t_vars *vars)
{
	int	i;

	i = -1;
	if (vars->map.map)
	{
		while (++i < vars->map.height)
			free(vars->map.map[i]);
		free(vars->map.map);
	}
	i = -1;
	if (vars->map.colored)
	{
		while (++i < vars->map.height)
			free(vars->map.colored[i]);
		free(vars->map.colored);
	}
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->img.img_ptr)
		mlx_destroy_image(vars->mlx, vars->img.img_ptr);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	if (vars->mlx)
		free(vars->mlx);
	free(vars);
}
