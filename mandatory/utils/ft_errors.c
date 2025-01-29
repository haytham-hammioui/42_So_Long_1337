/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:04:08 by hhammiou          #+#    #+#             */
/*   Updated: 2025/01/22 15:01:22 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_msg_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

void	error(t_game_s ***vars, char *msg)
{
	int	i;

	i = 0;
	while ((**vars)->map[i])
	{
		free((**vars)->map[i]);
		i++;
	}
	free((**vars)->map);
	ft_printf("%s", msg);
	exit(1);
}

void	free_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
