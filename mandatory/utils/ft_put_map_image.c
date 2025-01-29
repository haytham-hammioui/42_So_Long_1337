/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_map_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:14:43 by hhammiou          #+#    #+#             */
/*   Updated: 2025/01/20 20:04:26 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	pp_image(t_game_s ***v, int x, int y, char *img)
{
	int	img_w;
	int	img_h;

	(**v)->img = mlx_xpm_file_to_image((**v)->mlx, img, &img_w, &img_h);
	if ((**v)->img == NULL)
		error(v, "\033[1;31m🛑ERROR: files xpm not found\033[0m");
	mlx_put_image_to_window((**v)->mlx, (**v)->win, (**v)->img, x, y);
}

static void	put_image(char element, int x_pixel, int y_pixel, t_game_s **vars)
{
	if (element == '1')
		pp_image(&vars, x_pixel, y_pixel, "./textures/wall/wall.xpm");
	else if (element == 'C')
	{
		pp_image(&vars, x_pixel, y_pixel, "./textures/ground/ground.xpm");
		pp_image(&vars, x_pixel, y_pixel, "./textures/coins/coins.xpm");
		(*vars)->collect++;
	}
	else if (element == 'E')
		pp_image(&vars, x_pixel, y_pixel, "./textures/door/open_door.xpm");
	else if (element == 'P')
	{
		(*vars)->row_p = y_pixel;
		(*vars)->col_p = x_pixel;
		pp_image(&vars, x_pixel, y_pixel, "./textures/ground/ground.xpm");
		pp_image(&vars, x_pixel, y_pixel, "./textures/player/player_front.xpm");
	}
	else
		pp_image(&vars, x_pixel, y_pixel, "./textures/ground/ground.xpm");
}

void	put_map(t_game_s *vars)
{
	int	y_pixel;
	int	y_map;
	int	x_pixel;
	int	x_map;
	int	backup_w;

	y_pixel = 0;
	y_map = 0;
	backup_w = vars->win_w;
	while (vars->win_h > 0)
	{
		x_pixel = 0;
		x_map = 0;
		while (vars->win_w > 0)
		{
			put_image(vars->map[y_map][x_map], x_pixel, y_pixel, &vars);
			x_map++;
			x_pixel += 50;
			vars->win_w--;
		}
		vars->win_w = backup_w;
		y_map++;
		y_pixel += 50;
		vars->win_h--;
	}
}
