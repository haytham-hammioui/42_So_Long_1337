/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:07:50 by hhammiou          #+#    #+#             */
/*   Updated: 2025/01/22 16:14:22 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	coins(t_game_s ***v)
{
	int		img_w;
	int		img_h;

	(**v)->collect--;
	(**v)->map[((**v)->row_p / 50)][((**v)->col_p / 50)] = '0';
	(**v)->img = mlx_xpm_file_to_image(
			(**v)->mlx, "./textures/ground/ground.xpm", &img_w, &img_h);
	mlx_put_image_to_window((**v)->mlx,
		(**v)->win, (**v)->img, (**v)->col_p, (**v)->row_p);
}

void	mov_right(t_game_s **vars)
{
	int	img_w;
	int	img_h;

	(*vars)->img = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/ground/ground.xpm", &img_h, &img_w);
	mlx_put_image_to_window((*vars)->mlx,
		(*vars)->win, (*vars)->img, (*vars)->col_p, (*vars)->row_p);
	if ((*vars)->map[((*vars)->row_p / 50)][((*vars)->col_p / 50) + 1] == 'E')
	{
		if ((*vars)->collect <= 0)
			exit_d(&vars, 1);
	}
	else if ((*vars)->map[((*vars)->row_p / 50)]
		[((*vars)->col_p / 50) + 1] != '1')
	{
		(*vars)->col_p += 50;
		put_text(&vars);
	}
	if ((*vars)->map[((*vars)->row_p / 50)][((*vars)->col_p / 50)] == 'C')
		coins(&vars);
	(*vars)->img = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/player/player_right.xpm", &img_h, &img_w);
	mlx_put_image_to_window((*vars)->mlx,
		(*vars)->win, (*vars)->img, (*vars)->col_p, (*vars)->row_p);
}

void	mov_left(t_game_s **vars)
{
	int	img_w;
	int	img_h;

	(*vars)->img = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/ground/ground.xpm", &img_h, &img_w);
	mlx_put_image_to_window((*vars)->mlx,
		(*vars)->win, (*vars)->img, (*vars)->col_p, (*vars)->row_p);
	if ((*vars)->map[((*vars)->row_p / 50)][((*vars)->col_p / 50) - 1] == 'E')
	{
		if ((*vars)->collect <= 0)
			exit_d(&vars, 1);
	}
	else if ((*vars)->map[((*vars)->row_p / 50)]
		[((*vars)->col_p / 50) - 1] != '1')
	{
		(*vars)->col_p -= 50;
		put_text(&vars);
	}
	if ((*vars)->map[((*vars)->row_p / 50)][((*vars)->col_p / 50)] == 'C')
		coins(&vars);
	(*vars)->img = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/player/player_left.xpm", &img_h, &img_w);
	mlx_put_image_to_window((*vars)->mlx,
		(*vars)->win, (*vars)->img, (*vars)->col_p, (*vars)->row_p);
}

void	mov_up(t_game_s **vars)
{
	int	img_w;
	int	img_h;

	(*vars)->img = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/ground/ground.xpm", &img_h, &img_w);
	mlx_put_image_to_window((*vars)->mlx,
		(*vars)->win, (*vars)->img, (*vars)->col_p, (*vars)->row_p);
	if ((*vars)->map[((*vars)->row_p / 50) - 1][((*vars)->col_p / 50)] == 'E')
	{
		if ((*vars)->collect <= 0)
			exit_d(&vars, 1);
	}
	else if ((*vars)->map[((*vars)->row_p / 50) - 1]
		[((*vars)->col_p / 50)] != '1')
	{
		(*vars)->row_p -= 50;
		put_text(&vars);
	}
	if ((*vars)->map[((*vars)->row_p / 50)][((*vars)->col_p / 50)] == 'C')
		coins(&vars);
	(*vars)->img = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/player/player_back.xpm", &img_h, &img_w);
	mlx_put_image_to_window((*vars)->mlx,
		(*vars)->win, (*vars)->img, (*vars)->col_p, (*vars)->row_p);
}

void	mov_down(t_game_s **vars)
{
	int	img_w;
	int	img_h;

	(*vars)->img = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/ground/ground.xpm", &img_h, &img_w);
	mlx_put_image_to_window((*vars)->mlx,
		(*vars)->win, (*vars)->img, (*vars)->col_p, (*vars)->row_p);
	if ((*vars)->map[((*vars)->row_p / 50) + 1][((*vars)->col_p / 50)] == 'E')
	{
		if ((*vars)->collect <= 0)
			exit_d(&vars, 1);
	}
	else if ((*vars)->map[((*vars)->row_p / 50) + 1]
		[((*vars)->col_p / 50)] != '1')
	{
		(*vars)->row_p += 50;
		put_text(&vars);
	}
	if ((*vars)->map[((*vars)->row_p / 50)][((*vars)->col_p / 50)] == 'C')
		coins(&vars);
	(*vars)->img = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/player/player_front.xpm", &img_h, &img_w);
	mlx_put_image_to_window((*vars)->mlx,
		(*vars)->win, (*vars)->img, (*vars)->col_p, (*vars)->row_p);
}
