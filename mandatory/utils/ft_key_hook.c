/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:21:57 by hhammiou          #+#    #+#             */
/*   Updated: 2025/01/19 11:30:50 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
