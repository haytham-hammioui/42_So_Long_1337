/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:14:30 by hhammiou          #+#    #+#             */
/*   Updated: 2025/01/28 10:38:28 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	map_size(t_game_s **vars)
{
	int	width;
	int	height;

	width = 0;
	height = calc_height((*vars)->map);
	if (height > 28)
		error(&vars,
			"\033[1;31m🛑ERROR: Map height exceeds the maximum limit (28)\033[0m");
	while ((*vars)->map[0][width] != '\0')
	{
		width++;
	}
	if (width > 51)
		error(&vars,
			"\033[1;31m🛑ERROR: Map width exceeds the maximum limit (51)\033[0m");
}

static void	map_lines(t_game_s **vars)
{
	int	map_row;
	int	map_col;
	int	height;
	int	width;

	map_row = 0;
	width = 0;
	height = calc_height((*vars)->map);
	while (map_row != height)
	{
		map_col = 0;
		while ((*vars)->map[map_row][map_col] != '\0')
			map_col++;
		map_row++;
		if (height == map_col)
			error(&vars,
				"\033[1;31m🛑ERROR: map is not rectangular (is square)\033[0m");
		if (width != 0)
		{
			if (width != map_col)
				error(&vars, "\033[1;31m🛑ERROR: fix lines\033[0m");
		}
		else
			width = map_col;
	}
}

static int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static void	map_walls(t_game_s **vars)
{
	int		i;
	char	*msg;

	msg = "\033[1;31m🛑ERROR: map is not surrounded by walls\033[0m";
	if (check_line((*vars)->map[0]))
		error(&vars, msg);
	i = calc_height((*vars)->map) - 1;
	while (i)
	{
		if ((*vars)->map[i][0] != '1' 
			|| (*vars)->map[i][ft_strlen((*vars)->map[i]) - 1] != '1')
		{
			error(&vars, msg);
		}
		i--;
	}
	if (check_line((*vars)->map[calc_height((*vars)->map) - 1]))
		error(&vars, msg);
}

void	map_validation(t_game_s *vars)
{
	int	cols;
	int	rows;

	cols = ft_strlen(vars->map[0]);
	rows = calc_height(vars->map);
	vars->map_copyy = duplicate_map(vars->map, rows, cols);
	map_lines(&vars);
	map_size(&vars);
	map_walls(&vars);
	map_elements(&vars);
	if (check_path(vars->map_copyy, rows, cols) == 0)
	{
		free_map(vars->map_copyy, rows);
		free_map(vars->map, rows);
		ft_printf("\033[1;31m🛑ERROR: problem in path the map\033[0m");
		exit(1);
	}
	free_map(vars->map_copyy, rows);
}
