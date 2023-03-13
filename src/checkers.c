/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:11:09 by rkedida           #+#    #+#             */
/*   Updated: 2023/03/13 17:50:58 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_if_map_is_rectangular(t_mapData *Map)
{
	if (Map->total_cols % Map->MAX_HEIGHT != 0)
		error_exit("Map not rectangular.");
}

void	check_surrounded_walls(t_mapData *Map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	
	while (i  < Map->MAX_HEIGHT)
	{
		if (Map->map[i][0] != '1' || Map->map[i][Map->MAX_WIDTH -2] != '1')
			error_exit("Map is not closed.");
		i++;
	}
	while (j < Map->MAX_WIDTH - 1)
	{
		if (Map->map[0][j] != '1' || Map->map[Map->MAX_HEIGHT-1][j] != '1')
			error_exit("Map is not closed.");
		j++;
	}
}

void	check_tracked_data(t_mapData *Map)
{
	if (Map->player == 0 || Map->num_exits  == 0 || Map->num_collectibles == 0)
		error_exit("Map needs at least one Player, one Collectible and one Exit.");
}

void	check_exit_collectibles(t_mapData *Map)
{
	if (!Map->found_exit || Map->num_collectibles != 0 )
		error_exit("Invalid Path in Map.");
}
