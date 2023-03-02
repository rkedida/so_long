/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:11:09 by rkedida           #+#    #+#             */
/*   Updated: 2023/03/02 16:57:23 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parsing(int ac, char **av)
{
	char	*map;
	char	*buf;
	int		fd;
	int		read_bytes;

	map = av[1];

	if (ac != 2)
		error("usage: ./so_long maps/...");
	else if (strcmp(map + (strlen(av[1]) - 4), ".ber") != 0)
		error("is not a Valid map file.");

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file.");
		exit(1);
	}
	else
	{
		read_bytes = read(fd, buf, 1);
		if (read_bytes == -1)
		{
			perror("Error reading file.");
			exit(1);
		}
		else
		{
			
		}
	}


	return (0);
}