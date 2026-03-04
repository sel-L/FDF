/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:28:55 by selow             #+#    #+#             */
/*   Updated: 2025/10/27 17:53:39 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
int	main(int argc, char **argv)
{
	0xff1b	
	return (0);
}*/
#include "fdf.h"

int	close_window(t_vars *vars)
{
	free_vars(vars);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
		close_window(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (1);
	parse_arg(argv, argc, vars);
	init_everything(vars, argv);
	render_map(vars);
	free_vars(vars);
	return (0);
}

void	init_everything(t_vars *vars, char **argv)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, argv[1]);
	vars->img.img_ptr = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->img.addrs = mlx_get_data_addr(vars->img.img_ptr,
			&vars->img.bits_per_pixel, &vars->img.line_len, &vars->img.endian);
	vars->magnify = (WIN_WIDTH / vars->map.width) / MAGNIFY_SCALE;
	vars->coord.x1 = 0;
	vars->coord.y1 = 0;
	vars->coord.z1 = 0;
}

void	render_map(t_vars *vars)
{
	fill_background(vars, BG_COLOUR);
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ptr, 0, 0);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, CLOSE, 1L << 1, close_window, vars);
	mlx_loop(vars->mlx);
}
