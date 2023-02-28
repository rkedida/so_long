/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:11:09 by rkedida           #+#    #+#             */
/*   Updated: 2023/02/28 21:28:14 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int parsing(int ac, char **av)
{
	char	*map;

	map = av[1];

	if (ac != 2)
	{
		printf("usage: ./so_long maps/...\n");
		exit(1);
	}
	if (strcmp(map + (strlen(av[1]) - 4), ".ber") != 0)
		printf("Error: %s is not a Valid map file.\n", map);
	
	return (0);
}