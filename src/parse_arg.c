/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:08:03 by selow             #+#    #+#             */
/*   Updated: 2025/10/31 17:08:06 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_arg(char **argv, int argc, t_vars *vars)
{
	int	fd;

	if (argc != 2)
		error_message_free("Usage:\n./fdf <map_name.fdf>\n", 1, vars);
	fd = open_file(argv[1], O_RDONLY, vars);
	if (!fd)
		error_message_free("Nothing in file to parse\n", 1, vars);
	vars->map.height = find_mapheight(argv, vars);
	parse_map(argv, vars);
	if (!vars)
	{
		free_vars(vars);
		exit(1);
	}
}

void	parse_map(char **argv, t_vars *vars)
{
	char	*line;
	int		i;
	int		fd;

	fd = open_file(argv[1], O_RDONLY, vars);
	vars->map.map = ft_calloc(sizeof(int *), vars->map.height);
	vars->map.colored = ft_calloc(sizeof(int *), vars->map.height);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		vars->map.map[i] = split_atoi(line, ' ', &vars->map.width);
		if (!(vars->map.map[i]))
			free_vars(vars);
		vars->map.colored[i++] = split_atoi_colour(line);
		if (!(vars->map.colored[i - 1]))
			free_vars(vars);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

int	find_mapheight(char **argv, t_vars *vars)
{
	char	*str;
	int		count;
	int		fd;

	fd = open_file(argv[1], O_RDONLY, vars);
	if (!fd)
		error_message("Nothing in file to parse\n", 1);
	count = 0;
	str = get_next_line(fd);
	while (str)
	{
		count++;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (count);
}

int	open_file(char *file, int flags, t_vars *vars)
{
	int	fd;

	fd = open(file, flags, 0644);
	if (fd == -1)
		error_message_free("fdf: Invalid file, could not open.\n", 1, vars);
	return (fd);
}
/*
void	print_double_int(t_vars *vars, int collumns, int rows)
{
	int	i;
	int	j;

	i = -1;
	printf("first meow\n");
	while (++i < rows)
	{
		printf("meow\n");
		j = -1;
		while (++j < collumns)
		{
			printf("%i, ", vars->map.colored[i][j]);
		}
	}
}
*/
