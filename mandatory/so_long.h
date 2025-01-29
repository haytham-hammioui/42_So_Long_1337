/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:29:42 by hhammiou          #+#    #+#             */
/*   Updated: 2025/01/25 21:53:26 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../GNL/get_next_line.h"
# include "../FT_PRINTF/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_game_state {
	char	**map;
	char	**map_copyy;
	void	*mlx;
	void	*img;
	void	*win;
	int		win_w;
	int		win_h;
	int		col_p;
	int		row_p;
	int		mov;
	int		collect;
}	t_game_s;

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_map_state {
	int	c;
	int	p;
	int	e;
	int	x;
	int	y;
}	t_map_s;

void	check_file(char *file_l);
void	ft_msg_error(char *msg);
void	error(t_game_s ***vars, char *msg);
void	exit_d(t_game_s ***vars, int i);
int		ft_exit(t_game_s *v);
char	**get_map(char *file_map);
int		key_hook(int keycode, t_game_s *vars);
void	map_elements(t_game_s **vars);
void	map_validation(t_game_s *vars);
void	mov_right(t_game_s **vars);
void	mov_left(t_game_s **vars);
void	mov_up(t_game_s **vars);
void	mov_down(t_game_s **vars);
void	put_map(t_game_s *vars);
char	**ft_split(char *s, char c);
int		calc_height(char **map);
void	init_game_s(t_game_s *vars);
void	put_text(t_game_s ***v);
void	esc(t_game_s **vars);
char	**duplicate_map(char **original_map, int rows, int cols);
int		check_path(char **map, int rows, int cols);
void	free_map(char **map, int rows);

#endif