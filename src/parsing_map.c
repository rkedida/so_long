/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:11:09 by rkedida           #+#    #+#             */
/*   Updated: 2023/03/18 18:20:54 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	track_map_data(char c, t_mapData *Map)
{
	if (c == 'C')
	{
		Map->num_collectibles++;
		Map->max_collectibles = Map->num_collectibles;
	}
	else if (c == 'E')
	{
		Map->num_exits++;
		if (Map->num_exits > 1)
			error_exit("Only one Exit possible.");
	}
	else if (c == 'P')
	{
		Map->player++;
		if (Map->player > 1)
			error_exit("Only one Player possible.");
	}
}

void	ft_append(char **str, char c, t_mapData *Map)
{
	char	*new_str;
	int		len;

	new_str = NULL;
	len = 0;
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == '\n')
	{
		Map->cols++;
		track_map_data(c, Map);
	}
	else
		error_exit("Invalid Character.");
	if (!str)
		return ;
	len = ft_strlen(*str);
	new_str = ft_malloc(new_str, (len + 2));
	ft_memcpy(new_str, *str, len);
	new_str[len] = c;
	new_str[len + 1] = '\0';
	free(*str);
	*str = new_str;
}

void	read_validate_append(char buf, t_mapData *Map)
{
	if (buf == '\n')
	{	
		ft_append(&(Map->line), buf, Map);
		Map->max_width = Map->cols;
		Map->total_cols += Map->cols;
		Map->rows++;
		Map->max_height = Map->rows;
		Map->cols = 0;
	}
	else
		ft_append(&(Map->line), buf, Map);
}

void	open_file(t_mapData *Map)
{
	Map->fd = open(Map->map_path, O_RDONLY);
	if (Map->fd == -1)
		error_exit("Error opening file.");
}

void	parsing_map(t_mapData *Map)
{
	char		*buf;

	buf = NULL;
	open_file(Map);
	buf = ft_malloc(buf, 1);
	Map->line = ft_malloc(Map->line, 1);
	Map->read_bytes = read(Map->fd, buf, 1);
	while (Map->read_bytes > 0)
	{
		read_validate_append(buf[0], Map);
		Map->read_bytes = read(Map->fd, buf, 1);
	}
	check_if_map_is_rectangular(Map);
	Map->map = ft_split(Map->line, '\n');
	check_surrounded_walls(Map);
	check_tracked_data(Map);
	free(buf);
	free(Map->line);
	close(Map->fd);
}
