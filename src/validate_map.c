/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:11:09 by rkedida           #+#    #+#             */
/*   Updated: 2023/03/18 18:20:54 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_exit_player_pos(t_mapData *Map)
{
	Map->rows = 0;
	Map->cols = 0;
	while (Map->rows < Map->max_height)
	{
		Map->cols = 0;
		while (Map->cols < Map->max_width - 1)
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
	Map->visited = malloc(Map->max_height * sizeof(bool *));
	while (i < Map->max_height)
	{
		Map->visited[i] = malloc(Map->max_width * sizeof(bool));
		ft_memset(Map->visited[i], false, Map->max_width * sizeof(bool));
		i++;
	}
}

void	validate_map(t_mapData *Map)
{
	init_bool_visited(Map);
	set_exit_player_pos(Map);
	dfs(Map, Map->player_pos[0], Map->player_pos[1], Map->visited);
	check_exit_collectibles(Map);
	ft_free((void **)Map->visited, Map);
}
