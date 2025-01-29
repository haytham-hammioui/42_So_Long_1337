/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:01:37 by hhammiou          #+#    #+#             */
/*   Updated: 2025/01/19 16:10:21 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_elements(t_game_s **vars)
{
	t_map_s	map;

	map.c = 0;
	map.p = 0;
	map.e = 0;
	map.y = calc_height((*vars)->map);
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
			else if ((*vars)->map[map.y][map.x] != '1' &&
				(*vars)->map[map.y][map.x] != '0')
				error(&vars, "\033[1;31m🛑ERROR: unknown element in map\033[0m");
			map.x++;
		}
	}
	if (map.c == 0 || map.p != 1 || map.e != 1)
		error(&vars, "\033[1;31m🛑ERROR: problem in elements map\033[0m");
}
