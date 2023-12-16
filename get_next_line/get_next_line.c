/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:01:11 by dkremer           #+#    #+#             */
/*   Updated: 2023/12/16 02:51:46 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*read_line(int fd, char *nx_line)
{
	char	*buff;
	ssize_t	err_check;

	buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	err_check = 1;
	while (!ft_strchr(nx_line, '\n') && err_check)
	{
		err_check = read(fd, buff, BUFFER_SIZE);
		if (err_check == -1)
		{
			free(buff);
			free(nx_line);
			return (NULL);
		}
		buff[err_check] = '\0';
		nx_line = ft_strjoin(nx_line, buff);
	}
	free(buff);
	return (nx_line);
}

char	*ft_nx_line(char *str)
{
	char	*new;
	int		i;

	i = ft_len_nl(str);
	if (!str)
		return (NULL);
	if (str[i] == '\n')
		new = (char *)malloc(sizeof(char) * (i + 2));
	else
		new = (char *) malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_leftover(char *save)
{
	int		i;
	int		j;
	char	*new;

	if (!save)
		return (NULL);
	i = ft_len_nl(save);
	new = (char *) malloc(sizeof(*new) * (ft_strlen(save) - i + 1));
	if (!new)
		return (NULL);
	if (save[i] == '\n')
		i++;
	j = 0;
	while (save[i] != '\0')
		new[j++] = save[i++];
	new[j] = '\0';
	free(save);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_line(fd, save);
	if (!save)
		return (NULL);
	line = ft_nx_line(save);
	save = ft_leftover(save);
	if (line[0] == '\0')
	{
		free(save);
		save = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
