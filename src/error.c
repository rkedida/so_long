/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:18:51 by rkedida           #+#    #+#             */
/*   Updated: 2023/03/02 15:39:50 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *message)
{
	if (message)
	{
		printf("Error: %s\n", message);
		exit(1);
	}
	else
	{
		printf("Error: UNKNOWN");
		exit(1);
	}
}