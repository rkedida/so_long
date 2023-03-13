/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:12:22 by rkedida           #+#    #+#             */
/*   Updated: 2023/03/13 18:25:21 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"


typedef struct s_mapData
{
// input parsing
	char	*map_path;
	char	*check;
	int		result;
// map parsing
	char	*line;
	char	**map;
	int		total_cols;
	int		MAX_WIDTH;
	int		MAX_HEIGHT;
	int		cols;
	int		rows;
// map Data Tracking
	int		player;
	int		num_collectibles;
	int		num_exits;
	int		player_row;
	int		player_col;
	bool	**visited;
// open and read from a Map file
	int		fd;
	int		read_bytes;
// map Data

	bool	found_exit;
}				t_mapData;

// typedef struct s_data
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	void	*img;
// }				t_data;

// error.c
void			error_exit(char *message);
void			*ft_malloc(void *str, size_t size);
void			ft_free(void **str, t_mapData *Map);

// parsing.c
void			parsing_input(t_mapData *Map, int ac, char **av);
void			parsing(int ac, char **av, t_mapData *Map);

// checkers.c
void			check_if_map_is_rectangular(t_mapData *Map);
void			check_surrounded_walls(t_mapData *Map);
void			check_tracked_data(t_mapData *Map);
void			check_exit_collectibles(t_mapData *Map);

// parsing_map.c
void			track_map_data(char c, t_mapData *Map);
void			ft_append(char **str, char c, t_mapData *Map);
void			read_validate_append(char c, t_mapData *Map);
void			open_file(t_mapData *Map);
void			parsing_map(t_mapData *Map);

// validate_map.c
void			set_player_pos(t_mapData *Map);
void			init_bool_visited(t_mapData *Map);
void			validate_map(t_mapData *Map);

// dfs_search.c

void			dfs(t_mapData *Map, int row, int col, bool **visited);
void			up(t_mapData *Map, int row, int col, bool **visited);
void			down(t_mapData *Map, int row, int col, bool **visited);
void			left(t_mapData *Map, int row, int col, bool **visited);
void			right(t_mapData *Map, int row, int col, bool **visited);

// main.c
void			*init_map_struct(t_mapData *Map);

#endif