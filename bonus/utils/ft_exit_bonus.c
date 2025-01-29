/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:07:19 by hhammiou          #+#    #+#             */
/*   Updated: 2025/01/25 22:51:55 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	exit_d(t_game_s ***vars, int i)
{
	int	x;

	x = 0;
	if (i == 1)
		ft_printf("\033[1;32mCONGRATULATIONS! YOU WIN! 🎊\033[0m\n");
	while ((**vars)->map[x])
	{
		free((**vars)->map[x]);
		x++;
	}
	free((**vars)->map);
	mlx_destroy_window((**vars)->mlx, (**vars)->win);
	if (i == 1)
		exit(0);
	exit(1);
}

int	ft_exit(t_game_s *v)
{
	int	x;

	x = 0;
	while (v->map[x])
	{
		free(v->map[x]);
		x++;
	}
	free(v->map);
	mlx_destroy_window(v->mlx, v->win);
	exit(1);
	return (0);
}
