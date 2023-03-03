/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:11:09 by rkedida           #+#    #+#             */
/*   Updated: 2023/03/04 00:31:28 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parsing_input(int ac, char **av)
{
	char	*map;
	char	*check;
	int		result;

	map = NULL;
	check = NULL;
	result = 0;
	if (ac != 2)
		error_exit("usage: ./so_long maps/...");
	else if (av[1])
	{
		map = av[1];
		check = ft_strchr(map, '.');
		if (ft_strcmp(map + (ft_strlen(av[1]) - 4), ".ber") != 0)
			error_exit("is not a Valid map file.");
		else if (ft_strlen(check) > 4)
			error_exit("is not a Valid map file.");
		result = access(av[1], R_OK);
		if (result != 0)
			error_exit("You don't have read permissons for the file.");
		else
			return (0);
	}
	return (0);
}

// int parsing_map()
// {
	// t_map	*Map;
	// char	*buf = NULL;
	// int		fd;
	// int		read_bytes;
	// int		i;
	// int		num_cols;


	// Map = malloc(sizeof(Map));
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