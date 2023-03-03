/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:11:05 by rkedida           #+#    #+#             */
/*   Updated: 2023/03/03 21:26:51 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	// t_map	*map;


	if (parsing_input(ac, av) != 0)
		exit(1);
	(void) ac;
	(void) av;
	while(true)
	{
		void *mlx;
		void *mlx_win = NULL;
		mlx = mlx_init();
		if (!mlx_win)
			mlx_win = mlx_new_window(mlx, 1920, 1080, "Balu");
		mlx_loop(mlx);
	}

	return (0);
}









