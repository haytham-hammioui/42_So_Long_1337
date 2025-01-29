/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:44:19 by hhammiou          #+#    #+#             */
/*   Updated: 2025/01/22 20:09:10 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	calc_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

void	init_game_s(t_game_s *vars)
{
	vars->collect = 0;
	vars->mov = 0;
	vars->win_w = ft_strlen(vars->map[0]);
	vars->win_h = calc_height(vars->map);
}

void	put_text(t_game_s ***v)
{
	ft_printf("\033[1;35mMOVES :\033[0m %d\n", ++(**v)->mov);
}

void	esc(t_game_s **vars)
{
	exit_d(&vars, 0);
}
