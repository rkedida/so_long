/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:12:22 by rkedida           #+#    #+#             */
/*   Updated: 2023/03/03 17:32:11 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <fcntl.h>
# include "libs/libft/libft.h"
# include "libs/get_next_line/get_next_line.h"
# include "libs/ft_printf/ft_printf.h"




# define BUF_SIZE 1024;

typedef struct s_map
{
	char	**maps;
	char	*map;
	int		fd;
	int		read_bytes;
	int		rows;
	int		cols;
	int		num_exits;
	int		num_collectibles;
	int		num_start_pos;
	int		exit_row;
	int		exit_col;
	int		player_row;
	int		player_col;
	int		**data;
}				t_map;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
}				t_data;

int		parsing_input(int ac, char **av);
void	error(char *message);

#endif