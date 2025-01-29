/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:54:00 by hhammiou          #+#    #+#             */
/*   Updated: 2025/01/28 15:08:18 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	open_door(t_game_s **vars)
{
	int	i;
	int	j;
	int	height;
	int	img_w;
	int	img_h;

	i = 0;
	height = calc_height((*vars)->map);
	while (i != height)
	{
		j = 0;
		while ((*vars)->map[i][j] != '\0')
		{
			if ((*vars)->map[i][j] == 'E')
			{
				(*vars)->img = mlx_xpm_file_to_image((*vars)->mlx,
						"./textures/door/open_door.xpm", &img_w, &img_h);
				mlx_put_image_to_window(
					(*vars)->mlx, (*vars)->win, (*vars)->img, j * 50, i * 50);
			}
			j++;
		}
		i++;
	}
}

static void	render_img(t_game_s **vars)
{
	int			img_w;
	int			img_h;

	(*vars)->imgs[0] = "./textures/enemy/enemy1.xpm";
	(*vars)->imgs[1] = "./textures/enemy/enemy2.xpm";
	(*vars)->imgs[2] = "./textures/enemy/enemy3.xpm";
	(*vars)->imgs[3] = "./textures/enemy/enemy2.xpm";
	(*vars)->imgs[4] = "./textures/enemy/enemy1.xpm";
	(*vars)->img = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/ground/ground.xpm", &img_w, &img_h);
	if ((*vars)->img == NULL)
		error(&vars, "\033[1;31m🛑ERROR: files xpm for enemy not found\033[0m");
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win,
		(*vars)->img, (*vars)->col_m, (*vars)->row_m);
	(*vars)->img = mlx_xpm_file_to_image((*vars)->mlx,
			(*vars)->imgs[(*vars)->x], &img_w, &img_h);
	if ((*vars)->img == NULL)
		error(&vars, "\033[1;31m🛑ERROR: files xpm for enemy not found\033[0m");
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win,
		(*vars)->img, (*vars)->col_m, (*vars)->row_m);
}

static void	ft_lose(t_game_s **v, char *err)
{
	int	x;

	x = 0;
	while ((*v)->map[x])
	{
		free((*v)->map[x]);
		x++;
	}
	free((*v)->map);
	ft_printf("%s", err);
	exit(0);
}

int	ft_animation(t_game_s *vars)
{
	if (vars->sleep-- <= 0)
	{
		vars->x++;
		vars->sleep = 5;
	}
	if (vars->x == 5)
		vars->x = 0;
	if ((vars->row_m == vars->row_p) && (vars->col_m == vars->col_p))
		ft_lose(&vars, "\033[1;31mOooops, You Lose! 😢\033[0m\n");
	render_img(&vars);
	if (vars->collect <= 0)
		open_door(&vars);
	return (0);
}
