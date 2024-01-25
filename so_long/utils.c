/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:14:00 by dkremer           #+#    #+#             */
/*   Updated: 2024/01/22 20:26:36 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_fd(char *path_to_map)
{
	int	fd;

	fd = open(path_to_map, O_RDONLY);
	if (fd == -1)
		error();
	close(fd);
	return (fd);
}
