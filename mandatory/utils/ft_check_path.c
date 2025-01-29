/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:31:45 by hhammiou          #+#    #+#             */
/*   Updated: 2025/01/21 18:09:51 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_point	get_pos(char **map)
{
	t_point	pos;
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	pos.x = -1;
	pos.y = -1;
	return (pos);
}

static void	flod_fill(char **map, t_point size, t_point cur)
{
	if (cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y)
		return ;
	if (map[cur.y][cur.x] == '1')
		return ;
	map[cur.y][cur.x] = '1';
	flod_fill(map, size, (t_point){cur.x, cur.y - 1});
	flod_fill(map, size, (t_point){cur.x, cur.y + 1});
	flod_fill(map, size, (t_point){cur.x - 1, cur.y});
	flod_fill(map, size, (t_point){cur.x + 1, cur.y});
}

static int	is_all_reachable(char **map, int rows, int cols)
{
	int	y;
	int	x;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_path(char **map, int rows, int cols)
{
	t_point	size;
	t_point	start;

	size.x = cols;
	size.y = rows;
	start = get_pos(map);
	flod_fill(map, size, start);
	return (is_all_reachable(map, rows, cols));
}
