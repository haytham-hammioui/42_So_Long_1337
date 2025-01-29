/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:05:41 by hhammiou          #+#    #+#             */
/*   Updated: 2025/01/16 13:02:58 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_flags(va_list args, const char format, int *len)
{
	if (format == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (format == 'i' || format == 'd')
		ft_putnbr(va_arg(args, int), len);
	else
		ft_putchar(format, len);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	if (write(1, "", 0) < 0)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			check_flags(args, *format, &count);
		}
		else
			ft_putchar(*format, &count);
		format++;
	}
	va_end(args);
	return (count);
}
