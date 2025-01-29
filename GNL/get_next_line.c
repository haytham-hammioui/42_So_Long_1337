/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:24:46 by hhammiou          #+#    #+#             */
/*   Updated: 2025/01/24 16:44:08 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_buffer_line(char *str, int fd)
{
	ssize_t		line_b;
	char		*dest;

	dest = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	line_b = 1;
	while (line_b > 0)
	{
		line_b = read(fd, dest, BUFFER_SIZE);
		if (line_b == 0)
			break ;
		if (line_b == -1)
			return (free(dest), NULL);
		dest[line_b] = '\0';
		str = ft_strjoin(str, dest, 1);
		if (ft_strchr(dest, '\n'))
			break ;
	}
	free(dest);
	return (str);
}

static char	*ft_line_in_buffer(char *str)
{
	int		i;
	int		x;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	x = 0;
	while (x < i)
	{
		line[x] = str[x];
		x++;
	}
	line[x] = '\0';
	return (line);
}

static char	*rm_line(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = malloc(ft_strlen(buffer) - i + 1);
	if (!new_buffer)
		return (free(buffer), NULL);
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buff;

	if (fd > OPEN_MAX || fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (exit(1), NULL);
	str = ft_buffer_line(str, fd);
	if (!str)
		return (NULL);
	buff = ft_line_in_buffer(str);
	str = rm_line(str);
	return (buff);
}
