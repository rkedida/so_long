/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:49:55 by rkedida           #+#    #+#             */
/*   Updated: 2022/05/15 02:14:31 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_next_line(char *protect)
{
	int		i;
	char	*s;

	i = 0;
	if (!protect[i])
		return (NULL);
	while (protect[i] && protect[i] != '\n')
		i++;
	s = (char *)malloc((i + 2) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (protect[i] && protect[i] != '\n')
	{
		s[i] = protect[i];
		i++;
	}
	if (protect[i] == '\n')
	{
		s[i] = protect[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_protect(char *protect)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	while (protect[i] && protect[i] != '\n')
		i++;
	if (!protect[i])
	{
		free(protect);
		return (NULL);
	}
	p = (char *)malloc(sizeof(char) * (ft_strlen(protect) - i + 1));
	if (!p)
		return (NULL);
	i++;
	j = 0;
	while (protect[i])
		p[j++] = protect[i++];
	p[j] = '\0';
	free(protect);
	return (p);
}

char	*ft_read_protect(int fd, char *protect)
{
	int		i;
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	i = 1;
	while (!ft_strchr(protect, '\n') && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		protect = ft_strjoin(protect, buff);
	}
	free(buff);
	return (protect);
}

char	*get_next_line(int fd)
{
	static char	*protect[OPEN_MAX];
	char		*l;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	protect[fd] = ft_read_protect(fd, protect[fd]);
	if (!protect[fd])
		return (NULL);
	l = ft_next_line(protect[fd]);
	protect[fd] = ft_protect(protect[fd]);
	return (l);
}
