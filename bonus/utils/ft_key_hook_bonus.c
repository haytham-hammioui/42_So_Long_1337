/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:07:34 by hhammiou          #+#    #+#             */
/*   Updated: 2025/01/22 20:30:16 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	key_hook(int keycode, t_game_s *vars)
{
	if (keycode == 2 || keycode == 124)
		mov_right(&vars);
	else if (keycode == 0 || keycode == 123)
		mov_left(&vars);
	else if (keycode == 13 || keycode == 126)
		mov_up(&vars);
	else if (keycode == 1 || keycode == 125)
		mov_down(&vars);
	else if (keycode == 53)
		esc(&vars);
	return (0);
}
