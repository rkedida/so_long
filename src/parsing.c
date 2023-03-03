/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:11:09 by rkedida           #+#    #+#             */
/*   Updated: 2023/03/03 15:33:24 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parsing_input(int ac, char **av)
{
	// t_map	*Map;
	char	*map;
	// char	*buf = NULL;
	// int		fd;
	// int		read_bytes;
	// int		i;
	// int		num_cols;


	// Map = malloc(sizeof(Map));
	map = av[1];

	if (ac != 2)
		error("usage: ./so_long maps/...");
	else if (strcmp(map + (strlen(av[1]) - 4), ".ber") != 0)
		error("is not a Valid map file.");

	return (0);
}

// int parsing_map()
// {
// 	fd = open(map, O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file.");
// 		exit(EXIT_FAILURE);
// 	}
// 	else
// 	{
// 		read_bytes = read(fd, buf, 1);
// 		if (read_bytes == -1)
// 		{
// 			perror("Error reading file.");
// 			exit(EXIT_FAILURE);
// 		}
// 		while (i < read_bytes)
// 		{
// 			if (buf[i] == '\n')
// 			{
// 				Map->rows++;
// 				if (Map->cols == 0)
// 					Map->cols = num_cols;
// 				else if (Map->cols != num_cols)
// 					error("Map not rectangular");
// 				num_cols = 0;
// 			}
// 			else if (buf[i] == '0' || buf[i] == 'P' || buf[i] == '1' || buf[i] == 'C' || buf[i] == 'E')
// 				num_cols++;
// 			else
// 				error("Map Invalid character");
// 		}
// 		if (Map->cols || Map->rows == 0)
// 			error("Map Invalid empty");
// 	}
// }