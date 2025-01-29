/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:07:29 by hhammiou          #+#    #+#             */
/*   Updated: 2025/01/25 21:27:14 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
	vars->x = 0;
	vars->sleep = 5;
}

void	put_text(t_game_s ***v)
{
	int		img_w;
	int		img_h;
	char	*movement;
	char	*number;

	number = ft_itoa(++(**v)->mov);
	movement = ft_strjoin("MOVES : ", number, 0);
	(**v)->img = mlx_xpm_file_to_image(
			(**v)->mlx, "./textures/wall/wall.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(**v)->mlx, (**v)->win, (**v)->img, 0, 0);
	mlx_put_image_to_window(
		(**v)->mlx, (**v)->win, (**v)->img, 50, 0);
	mlx_put_image_to_window(
		(**v)->mlx, (**v)->win, (**v)->img, 100, 0);
	mlx_string_put((**v)->mlx, (**v)->win, 15, 10, 0xfffff00, movement);
	ft_printf("\033[1;35mMOVES :\033[0m %d\n", ++(**v)->mov);
	free(movement);
	free(number);
}

void	esc(t_game_s **vars)
{
	exit_d(&vars, 0);
}
