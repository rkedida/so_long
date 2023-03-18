/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:11:09 by rkedida           #+#    #+#             */
/*   Updated: 2023/03/17 20:49:58 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_exit_player_pos(t_mapData *Map)
{
	Map->rows = 0;
	Map->cols = 0;

	while (Map->rows < Map->MAX_HEIGHT)
	{
		Map->cols = 0;
		while (Map->cols < Map->MAX_WIDTH-1)
		{
			if (Map->map[Map->rows][Map->cols] == 'P')
			{
				Map->player_pos[0] = Map->rows;
				Map->player_pos[1] = Map->cols;
			}
			if (Map->map[Map->rows][Map->cols] == 'E')
			{
				Map->exit_pos[0] = Map->rows;
				Map->exit_pos[1] = Map->cols;
			}
			Map->cols++;
		}
		Map->rows++;
	}
}

void	init_bool_visited(t_mapData *Map)
{
	int		i;

	i = 0;
	Map->visited = malloc(Map->MAX_HEIGHT * sizeof(bool *));
	while (i < Map->MAX_HEIGHT)
	{
		Map->visited[i] = malloc(Map->MAX_WIDTH * sizeof(bool));
		ft_memset(Map->visited[i], false, Map->MAX_WIDTH * sizeof(bool));
		i++;
	}
}

void validate_map(t_mapData *Map)
{
	init_bool_visited(Map);
	set_exit_player_pos(Map);
	dfs(Map, Map->player_pos[0], Map->player_pos[1], Map->visited);
	check_exit_collectibles(Map);
	ft_free((void**)Map->visited, Map);
}
