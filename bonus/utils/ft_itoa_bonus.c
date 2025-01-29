/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:16:18 by hhammiou          #+#    #+#             */
/*   Updated: 2025/01/24 11:50:50 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	ncount(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	long	nb;

	len = ncount(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	nb = n;
	s[len] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		s[0] = '-';
	}
	if (nb == 0)
		s[0] = '0';
	while (--len >= 0 && nb)
	{
		s[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (s);
}
