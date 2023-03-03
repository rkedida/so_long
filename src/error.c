/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:18:51 by rkedida           #+#    #+#             */
/*   Updated: 2023/03/03 13:34:12 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *message)
{
	if (message)
	{
		write(2, "Error: ", 7);
		write(2, message, strlen(message));
		write(2, "\n", 1);
		exit(EXIT_FAILURE);
	}
	else
	{
		write(2, "Error: UNKNOWN", 14);
		exit(EXIT_FAILURE);
	}
}
