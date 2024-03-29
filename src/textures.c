/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:11:05 by rkedida           #+#    #+#             */
/*   Updated: 2023/03/19 01:47:01 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(int i, int j, t_winData *img)
{
	img->img = mlx_xpm_file_to_image(img->mlx, img->relative_path, \
		&img->img_width, &img->img_height);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, j * \
		img->img_width, i * img->img_height);
	img->addr = mlx_get_data_addr(img->mlx_win, &img->bpp, \
		&img->line_length, &img->endian);
}

void	load_texture(char c, int i, int j, t_winData *img)
{
	if (c == 'P')
	{
		img->relative_path = "./xpm/ground1.xpm";
		load_images(i, j, img);
		img->relative_path = "./xpm/player1.xpm";
	}
	else if (c == '0')
		img->relative_path = "./xpm/ground1.xpm";
	else if (c == '1')
		img->relative_path = "./xpm/wall1.xpm";
	else if (c == 'C')
	{
		img->relative_path = "./xpm/ground1.xpm";
		load_images(i, j, img);
		img->relative_path = "./xpm/collectible1.xpm";
	}
	else if (c == 'E')
	{
		img->relative_path = "./xpm/ground1.xpm";
		load_images(i, j, img);
		img->relative_path = "./xpm/exit1.xpm";
	}
	load_images(i, j, img);
}

void	load_textures(t_mapData *Map, t_winData *img)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (Map->map[i] != NULL)
	{
		j = 0;
		while (Map->map[i][j] != '\0')
		{
			c = Map->map[i][j];
			load_texture(c, i, j, img);
			j++;
		}
		i++;
	}
}

int	cleanup_and_exit(t_mapData *Map)
{
	mlx_destroy_window(Map->img->mlx, Map->img->mlx_win);
	ft_free((void **)Map->map, Map);
	free(Map->img);
	free(Map);
	exit(0);
	return (0);
}
