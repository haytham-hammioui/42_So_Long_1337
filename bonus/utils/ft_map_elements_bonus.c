/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_elements_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:07:39 by hhammiou          #+#    #+#             */
/*   Updated: 2025/01/25 21:50:40 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	init(t_map_s *map, t_game_s ***v)
{
	map->c = 0;
	map->p = 0;
	map->e = 0;
	map->m = 0;
	map->y = calc_height((**v)->map);
}

void	map_elements(t_game_s **vars)
{
	t_map_s	map;

	init(&map, &vars);
	while (map.y--)
	{
		map.x = 0;
		while ((*vars)->map[map.y][map.x] != '\0')
		{
			if ((*vars)->map[map.y][map.x] == 'E')
				map.e++;
			else if ((*vars)->map[map.y][map.x] == 'P')
				map.p++;
			else if ((*vars)->map[map.y][map.x] == 'C')
				map.c++;
			else if ((*vars)->map[map.y][map.x] == 'M')
				map.m++;
			else if ((*vars)->map[map.y][map.x] != '1' &&
				(*vars)->map[map.y][map.x] != '0')
				error(&vars, "\033[1;31m🛑ERROR: unknown element in map\033[0m");
			map.x++;
		}
	}
	if (map.c == 0 || map.p != 1 || map.e != 1 || map.m != 1)
		error(&vars, "\033[1;31m🛑ERROR: problem in elements map\033[0m");
}
