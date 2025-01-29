/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:09:07 by hhammiou          #+#    #+#             */
/*   Updated: 2025/01/24 16:57:20 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**get_map(char *file_map)
{
	char	*line;
	char	*lines;
	int		fd;

	line = NULL;
	lines = ft_strdup("");
	if (!lines)
		ft_msg_error("\033[1;31m🛑ERROR:\033[0m Memory allocation failed.");
	fd = open(file_map, O_RDONLY);
	if (fd < 0)
		ft_msg_error("\033[1;31m🛑ERROR:\033[0m Unable to open the file");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		lines = ft_strjoin(lines, line, 1);
		free(line);
	}
	free(line);
	close(fd);
	if (lines[0] == '\0')
		ft_msg_error("\033[1;31m🛑ERROR:\033[0m The file is empty.");
	return (ft_split(lines, '\n'));
}

char	**duplicate_map(char **original_map, int rows, int cols)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		map_copy[i] = (char *)malloc(sizeof(char) * (cols + 1));
		if (!map_copy[i])
		{
			map_copy[i] = NULL;
			free_map(map_copy, i);
			return (NULL);
		}
		j = -1;
		while (++j < cols)
			map_copy[i][j] = original_map[i][j];
		map_copy[i][j] = '\0';
		i++;
	}
	map_copy[rows] = NULL;
	return (map_copy);
}
