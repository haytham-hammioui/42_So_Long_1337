/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:15:04 by hhammiou          #+#    #+#             */
/*   Updated: 2025/01/29 10:54:34 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game_s	vars;

	if (argc <= 1)
	{
		ft_msg_error("\033[1;31m🛑 ERREUR :\033[0m Invalid arguments !");
	}
	check_file(argv[1]);
	vars.map = get_map(argv[1]);
	if (vars.map)
	{
		map_validation(&vars);
		init_game_s(&vars);
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, vars.win_w * 50,
				vars.win_h * 50, "So-Long");
		put_map(&vars);
		mlx_key_hook(vars.win, key_hook, &vars);
		mlx_hook(vars.win, 17, (1L << 0), ft_exit, &vars);
		mlx_string_put(vars.mlx, vars.win, 15, 10, 0xffff00, "MOVES : 0");
		mlx_loop_hook(vars.mlx, ft_animation, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
