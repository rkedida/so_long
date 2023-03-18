/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:11:09 by rkedida           #+#    #+#             */
/*   Updated: 2023/03/18 18:20:54 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_if_map_is_rectangular(t_mapData *Map)
{
	if (Map->total_cols % Map->max_height != 0)
		error_exit("Map not rectangular.");
}

void	check_surrounded_walls(t_mapData *Map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < Map->max_height)
	{
		if (Map->map[i][0] != '1' || Map->map[i][Map->max_width -2] != '1')
			error_exit("Map is not closed.");
		i++;
	}
	while (j < Map->max_width - 1)
	{
		if (Map->map[0][j] != '1' || Map->map[Map->max_height - 1][j] != '1')
			error_exit("Map is not closed.");
		j++;
	}
}

void	check_tracked_data(t_mapData *Map)
{
	if (Map->player == 0 || Map->num_exits == 0 || Map->num_collectibles == 0)
		error_exit("Map needs at least one Player, 1 Collectible and 1 Exit.");
}

void	check_exit_collectibles(t_mapData *Map)
{
	if (!Map->found_exit || Map->num_collectibles != 0)
		error_exit("Invalid Path in Map.");
}
