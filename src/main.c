/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:11:05 by rkedida           #+#    #+#             */
/*   Updated: 2023/03/13 18:24:05 by rkedida          ###   ########.fr       */
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
	Map->num_exits = 0;
	Map->player_row = -1;
	Map->player_col = -1;
	Map->fd = 0;
	Map->read_bytes = 0;
	Map->visited = NULL;
	Map->found_exit = false;
	return (Map);
}

void	leaks()
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	atexit(leaks);
	t_mapData	*Map;

	Map = NULL;

	Map = init_map_struct(Map);
	
	parsing(ac, av, Map);

	(void) ac;
	(void) av;
	printf("%s", Map->line);
	printf("%d - HEIGHT ------------ %d - WIDTH\n", Map->MAX_HEIGHT, Map->MAX_WIDTH);
	printf("%d - rows ------------ %d - cools\n", Map->rows, Map->cols);

	int i = 0;
	void *mlx = NULL;
	// void *mlx_win = NULL;
	void *img = NULL;
	
	mlx = mlx_init;
	if (!img)
		img = mlx_new_image(mlx, 1920, 1080);


	for (int i = 0; Map->map[i] != NULL; i++)
		printf("%s\n", Map->map[i]);
	ft_free((void**)Map->map, Map);
	free(Map);

	return (0);
}

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	// my_mlx_pixel_put(&img, 500, 500, 0x00FF0000);
// 	// my_mlx_pixel_put(&img, 0, 0, 0x00FF0000); // Draw a single pixel at (50, 50)
// 	// my_mlx_pixel_put(&img, 50, 51, 0x00FF0000); // Draw a single pixel at (50, 51)
// 	// my_mlx_pixel_put(&img, 50, 52, 0x00FF0000); // Draw a single pixel at (50, 52)
// 	// ... and so on

// 	// Draw a rectangle that is 200 pixels wide and 100 pixels tall with a red color
// 	for (int y = 0; y < 1080; y++)
// 	{
// 		for (int x = 0; x < 1920; x++)
// 		{
// 			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
// 		}
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	for (int y = 100; y < 300; y++) 
// 	{
// 		for (int x = 100; x < 1620; x++)
// 		{
// 			my_mlx_pixel_put(&img, x, y, 0x00FF00);
// 		}
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 100, 100);

// 	for (int y = 200; y < 250; y++) 
// 	{
// 		for (int x = 200; x < 1420; x++)
// 		{
// 			my_mlx_pixel_put(&img, x, y, 0xFFFF00);
// 		}
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 200, 200);
// 	mlx_loop(mlx);
// }
