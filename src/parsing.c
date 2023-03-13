/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:11:09 by rkedida           #+#    #+#             */
/*   Updated: 2023/03/10 13:06:06 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsing_input(t_mapData *Map, int ac, char **av)
{
	if (ac != 2)
		error_exit("usage: ./so_long maps/...");
	else if (av[1])
	{
		Map->map_path = av[1];
		Map->check = ft_strchr(Map->map_path, '.');
		if (ft_strcmp(Map->map_path + (ft_strlen(av[1]) - 4), ".ber") != 0)
			error_exit("is not a Valid map file.");
		else if (ft_strlen(Map->check) > 4)
			error_exit("is not a Valid map file.");
		if ((Map->result = access(Map->map_path, F_OK)) != 0)
			error_exit("File doesn't exist.");
		else if ((Map->result = access(Map->map_path, R_OK)) != 0)
			error_exit("You don't have read permissons for the file.");
	}
}

void	parsing(int ac, char **av, t_mapData *Map)
{
	parsing_input(Map, ac, av);
	parsing_map(Map);
	validate_map(Map);
}
