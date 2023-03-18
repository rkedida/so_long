#include <stdio.h>
#include <fcntl.h>
// #include "mlx/<mlx.h>"
#include "libs/get_next_line/get_next_line.h"
#include "libs/libft/libft.h"



// int main()
// {
// 	// if (open("so_long", O_RDONLY))
// 	// 	printf("YES\n");
// 	// else
// 	// 	printf("NO\n");

// 	char *buf = NULL;
// 	char *line = NULL;
// 	char **split_line = NULL;
// 	int fd = 0;
// 	char *s1 = "maps/maps.ber";
// 	int i = 0;
// 	int cols = 0;
// 	int num_cols = 0;
// 	int rows = 0;

// 	fd = open(s1, O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s\n", line);

// 		line = get_next_line(fd);
// 	if (!line)
// 		printf("Map is empty\n");

// 	// split the first line into individual characters
// 	split_line = ft_split(line, '\0');
// 	if (!split_line)
// 		printf("Failed to split map\n");

// 	// count the number of columns in the first line
// 	while (split_line[num_cols])
// 		num_cols++;

// 	// free the memory allocated for the split line
// 	free(split_line);
// 	rows++;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		split_line = ft_split(line, '\0');
// 		if (!split_line)
// 			printf("failed to split map.\n");
// 		while (split_line[cols])
// 			cols++;
// 		if (cols != num_cols)
// 			printf("Map is not rectangular\n");
// 		free(split_line);
// 		rows++;
// 	}

// 	// for (int i = 0; split_line; i++)
// 	printf("%c", split_line[1][0]);

// 	return (0);
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_wind;
// 	void	*img;
// 	char	*relative_path = "./test.xpm";
// 	int		img_width;
// 	int		img_height;

	
// 	if (!mlx)
// 		mlx = mlx_init();
// 	if (!mlx_wind)
// 		mlx_wind = mlx_new_window(mlx, 1920, 1080, "Hello");
// 	if (!img)
// 		img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// }

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// my_mlx_pixel_put(&img, 500, 500, 0x00FF0000);
	// my_mlx_pixel_put(&img, 0, 0, 0x00FF0000); // Draw a single pixel at (50, 50)
	// my_mlx_pixel_put(&img, 50, 51, 0x00FF0000); // Draw a single pixel at (50, 51)
	// my_mlx_pixel_put(&img, 50, 52, 0x00FF0000); // Draw a single pixel at (50, 52)
	// ... and so on

	// Draw a rectangle that is 200 pixels wide and 100 pixels tall with a red color
	for (int y = 0; y < 1080; y++)
	{
		for (int x = 0; x < 1920; x++)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	for (int y = 100; y < 300; y++) 
	{
		for (int x = 100; x < 1620; x++)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF00);
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 100, 100);

	for (int y = 200; y < 250; y++) 
	{
		for (int x = 200; x < 1420; x++)
		{
			my_mlx_pixel_put(&img, x, y, 0xFFFF00);
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 200, 200);
	mlx_loop(mlx);
}