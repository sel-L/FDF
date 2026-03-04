/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:34:29 by selow             #+#    #+#             */
/*   Updated: 2025/11/11 20:34:34 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

// settings
# define WIN_WIDTH 1000 // need to double check
# define WIN_HEIGHT 800 // need to double check
# define H_SCALE 0.2 // IF TOO SPIKY, CAN REDUCE BY (x2)
# define ANGLE 0.6

// (WIN_WIDTH / 2.5)
# define H_MOVE 400

// (WIN_HEIGHT / 4) IF ITS TOO WEIRD, DIVIDE BY 3 INSTEAD
# define V_MOVE 200 // if its too weird, divide by 3 instead

# define MAGNIFY_DEFAULT 2

// BETWEEN 1.5 to 3
# define MAGNIFY_SCALE 1.5

// hooks and colours
# define ESC_KEY		0xff1b
# define CLOSE			17
# define LINE_COLOUR 	0xFFFFFFFF
# define BG_COLOUR 		0x00000000

// aliases

typedef struct s_img
{
	void	*img_ptr;
	int		line_len;
	int		bits_per_pixel;
	int		endian;
	char	*addrs;
}	t_img;

typedef struct s_map
{
	int	width;
	int	height;
	int	**map;
	int	**colored;
}	t_map;

typedef struct s_coor
{
	int		ori_x0;
	int		ori_y0;
	double	x1;
	double	y1;
	double	z1;
}	t_coor;

typedef struct s_vars
{
	t_map	map;
	t_img	img;
	t_coor	coord;
	void	*mlx;
	void	*win;
	float	magnify;
}	t_vars;

// fdf
int		close_window(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
void	init_everything(t_vars *vars, char **argv);
void	render_map(t_vars *vars);

// parse arg
void	parse_arg(char **argv, int argc, t_vars *vars);
void	parse_map(char **argv, t_vars *vars);
int		find_mapheight(char **argv, t_vars *vars);
int		open_file(char *file, int flags, t_vars *vars);

// split_atoi
int		*split_atoi(const char *s, char sep, int *out_len);
int		*split_atoi_colour(const char *s);

// draw map
void	convert_to_2d(double *x, double *y, double *z, t_vars *vars);
void	isometric(double *x, double *y, double z);
void	dda(double x0, double y0, t_vars *vars);
void	draw_line(double x0, double y0, t_vars *vars);
void	draw_map(t_vars *vars);

// free vars
void	free_vars(t_vars *vars);

// utils
void	error_message(char *s, int exit_code);
void	fill_background(t_vars *vars, int color);
void	error_message_free(char *s, int exit_code, t_vars *vars);

// put_pixel
void	put_pixel(t_vars *vars, int x, int y, int color);

#endif
