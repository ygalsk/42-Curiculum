/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:01:11 by dkremer           #+#    #+#             */
/*   Updated: 2023/12/15 23:38:08 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	read_line(int fd, char *nx_line)
{
	char	*buff;
	ssize_t	err_check;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	err_check = 1;
	while (!(ft_strchr(nx_line, '\n')) && err_check)
	{
		err_check = read(fd, buff, BUFFER_SIZE);
		if (err_check == -1) {
		
		}
	}
}
