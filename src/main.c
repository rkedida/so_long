/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:11:05 by rkedida           #+#    #+#             */
/*   Updated: 2023/03/19 01:16:52 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*init_map_struct(t_mapData *Map)
{
	Map = malloc(sizeof(t_mapData));
	Map->map_path = NULL;
	Map->check = NULL;
	Map->result = 0;
	Map->line = NULL;
	Map->map = NULL;
	Map->total_cols = 0;
	Map->max_width = 0;
	Map->max_height = 0;
	Map->rows = 0;
	Map->cols = 0;
	Map->player = 0;
	Map->num_collectibles = 0;
	Map->max_collectibles = 0;
	Map->num_exits = 0;
	Map->fd = 0;
	Map->read_bytes = 0;
	Map->visited = NULL;
	Map->found_exit = false;
	Map->img = NULL;
	Map->steps = 0;
	return (Map);
}

void	*init_windata(t_winData *img)
{
	img = malloc(sizeof(t_winData));
	img->mlx = NULL;
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_length = 0;
	img->endian = 0;
	img->img_width = 55;
	img->img_height = 55;
	img->relative_path = NULL;
	return (img);
}

void	leaks(void)
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	t_mapData	*map;

	// leaks();
	// atexit(leaks);
	map = NULL;
	map = init_map_struct(map);
	map->img = init_windata(map->img);
	parsing(ac, av, map);
	if ((map->max_width - 1) * map->img->img_width > MAX_WINDOW_WIDTH \
		|| map->max_height * map->img->img_height > MAX_WINDOW_HEIGHT)
		error_exit("Window to big max resolution 1920x1080.");
	map->img->mlx = mlx_init();
	map->img->mlx_win = mlx_new_window(map->img->mlx, \
		(map->max_width - 1) * map->img->img_width, \
			(map->max_height) * map->img->img_height, "Balu");
	load_textures(map, map->img);
	mlx_key_hook(map->img->mlx_win, &handle_keypress, map);
	mlx_hook(map->img->mlx_win, 17, 0L, cleanup_and_exit, map);
	mlx_loop(map->img->mlx);
	return (0);
}
