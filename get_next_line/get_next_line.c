/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:00:10 by dkremer           #+#    #+#             */
/*   Updated: 2023/12/12 14:21:21 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **substrs)
{
	if (*substrs != NULL)
	{
		free(*substrs);
		substrs = NULL;
	}
}

char	*join_line(int nl_position, char **buffer)
{
	char	*res;
	char	*tmp;

	tmp = NULL;
	if (nl_position <= 0)
	{
		if (**buffer == '\0')
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		res = *buffer;
		*buffer = NULL;
		return (res);
	}
	tmp = ft_substr(*buffer, nl_position, BUFFER_SIZE);
	res = *buffer;
	res[nl_position] = 0;
	*buffer = tmp;
	return (res);
}

char	*ft_read_line(int fd, char **buffer, char *read_return)
{
	size_t	bytes_read;
	char	*tmp;
	char	*nl;

	nl = ft_strchr(*buffer, '\n');
	tmp = NULL;
	bytes_read = 0;
	while (nl == NULL)
	{
		bytes_read = read(fd, read_return, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (join_line(bytes_read, buffer));
		read_return[bytes_read] = 0;
		tmp = ft_strjoin(*buffer, read_return);
		ft_free(buffer);
		*buffer = tmp;
		nl = ft_strchr(*buffer, '\n');
	}
	return (join_line(nl - *buffer + 1, buffer));
}

char	*get_next_line(int fd)
{
	static char	*buf[BUFFER_SIZE + 1];
	char		*next_line;
	char		*read_return ;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_return = ((char *)malloc(BUFFER_SIZE + 1));
	if (!read_return)
		return (NULL);
	if (!buf[fd])
		buf[fd] = ft_strdup("");
	next_line = ft_read_line(fd, &buf[fd], read_return);
	ft_free(&read_return);
	return (next_line);
}
