/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:47:09 by hhammiou          #+#    #+#             */
/*   Updated: 2025/01/29 10:54:57 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_file(char *file_l)
{
	int		i;
	char	*ber;

	ber = ".ber";
	i = 0;
	while (*file_l)
	{
		if (*file_l == '.')
		{
			while (ber[i])
			{
				if (ber[i] != file_l[i])
					break ;
				i++;
			}
			if (ber[i] == '\0' && file_l[i] == '\0')
				return ;
		}
		file_l++;
	}
	ft_msg_error("\033[1;31m🛑ERROR:\033[0m Invalid file !");
}
