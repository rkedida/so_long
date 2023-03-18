/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:11:05 by rkedida           #+#    #+#             */
/*   Updated: 2023/03/18 16:32:31 by rkedida          ###   ########.fr       */
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
	Map->MAX_WIDTH = 0;
	Map->MAX_HEIGHT = 0;
	Map->rows = 0;
	Map->cols = 0;
	Map->player = 0;
	Map->num_collectibles = 0;
	Map->MAX_COLLECTIBLES = 0;
	Map->num_exits = 0;

	Map->fd = 0;
	Map->read_bytes = 0;
	Map->visited = NULL;
	Map->found_exit = false;
	Map->img = NULL;
	Map->steps = 0;

	return (Map);
}

void	*init_winData(t_winData *img)
{
	img = malloc(sizeof(t_winData));
	img->mlx = NULL;
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_length = 0;
	img->endian = 0;

	img->img_width = 32;
	img->img_height = 32;
	img->relative_path = NULL;
	return (img);
}

void	leaks()
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	// atexit(leaks);
	// leaks();
	t_mapData	*Map;

	Map = NULL;

	Map = init_map_struct(Map);
	Map->img = init_winData(Map->img);
	parsing(ac, av, Map);
	Map->img->mlx = mlx_init();
	if ((Map->MAX_WIDTH - 1) * Map->img->img_width > MAX_WINDOW_WIDTH || Map->MAX_HEIGHT * Map->img->img_height > MAX_WINDOW_HEIGHT)
	{
		printf("%d - width === %d - height\n", (Map->MAX_WIDTH - 1) * Map->img->img_width, Map->MAX_HEIGHT * Map->img->img_height);
		error_exit("Window to big.");
	}
		printf("%d - width === %d - height\n", (Map->MAX_WIDTH - 1) * Map->img->img_width, Map->MAX_HEIGHT * Map->img->img_height);
	Map->img->mlx_win = mlx_new_window(Map->img->mlx, (Map->MAX_WIDTH - 1) * Map->img->img_width, (Map->MAX_HEIGHT) * Map->img->img_height, "Francesca");
	load_textures(Map, Map->img);
	mlx_key_hook(Map->img->mlx_win, &handle_keypress, Map);
	mlx_hook(Map->img->mlx_win, 17, 0L, cleanup_and_exit, Map);
	mlx_loop(Map->img->mlx);

	return (0);
}
