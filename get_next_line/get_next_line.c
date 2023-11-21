/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:25:02 by dkremer           #+#    #+#             */
/*   Updated: 2023/11/18 22:09:04 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
// #include "get_next_line.h"
//
// void	ft_free(char **substrs)
// {
// 	if (*substrs != NULL)
// 	{
// 		free(*substrs);
// 		substrs = NULL;
// 	}
// }
//
// char	*join_line(int nl_position, char **buffer)
// {
// 	char	*res;
// 	char	*tmp;
//
// 	tmp = NULL;
// 	if (nl_position <= 0)
// 	{
// 		if (**buffer == '\0')
// 		{
// 			free(*buffer);
// 			*buffer = NULL;
// 			return (NULL);
// 		}
// 		res = *buffer;
// 		*buffer = NULL;
// 		return (res);
// 	}
// 	tmp = ft_substr(*buffer, nl_position, BUFFER_SIZE);
// 	res = *buffer;
// 	res[nl_position] = 0;
// 	*buffer = tmp;
// 	return (res);
// }
//
// char	*ft_read_line(int fd, char **buffer, char *read_return)
// {
// 	size_t	bytes_read;
// 	char	*tmp;
// 	char	*nl;
//
// 	nl = ft_strchr(*buffer, '\n');
// 	tmp = NULL;
// 	bytes_read = 0;
// 	while (nl == NULL)
// 	{
// 		bytes_read = read(fd, read_return, BUFFER_SIZE);
// 		if (bytes_read <= 0)
// 			return (join_line(bytes_read, buffer));
// 		read_return[bytes_read] = 0;
// 		tmp = ft_strjoin(*buffer, read_return);
// 		ft_free(buffer);
// 		*buffer = tmp;
// 		nl = ft_strchr(*buffer, '\n');
// 	}
// 	return (join_line(nl - *buffer + 1, buffer));
// }
//
// char	*get_next_line(int fd)
// {
// 	static char	*buf[BUFFER_SIZE + 1];
// 	char		*next_line;
// 	char		*read_return;
//
// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	read_return = (char *)malloc(BUFFER_SIZE + 1);
// 	if (!read_return)
// 		return (NULL);
// 	if (!buf[fd])
// 		buf[fd] = ft_strdup("");
// 	next_line = ft_read_line(fd, &buf[fd], read_return);
// 	ft_free(&read_return);
// 	return (next_line);
// }
//
#include "get_next_line.h"

char	*get_line_ps(char *line)
{
	int		i;
	int		temp;
	char	*new_line;

	i = 0;
	temp = 0;
	if (line == NULL)
		return (NULL);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		temp++;
	new_line = ft_substr(line, 0, (i + temp));
	if (new_line == NULL)
		return (NULL);
	if (new_line [0] == '\0')
	{
		free(new_line);
		new_line = NULL;
	}
	free (line);
	line = NULL;
	return (new_line);
}

char	*get_remainder(char *line)
{
	int		i;
	int		line_len;
	char	*new_remainder;

	i = 0;
	if (line == NULL)
		return (NULL);
	line_len = ft_strlen(line);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (0);
	new_remainder = ft_substr(line, (i + 1), (line_len - i));
	if (new_remainder == NULL)
		return (NULL);
	if (new_remainder [0] == '\0')
	{
		free(new_remainder);
		new_remainder = NULL;
	}
	return (new_remainder);
}

char	*func(char *remainder, char *buffer)
{
	char	*new_remainder;

	new_remainder = ft_strjoin(remainder, buffer);
	if (new_remainder == NULL)
		return (NULL);
	free (remainder);
	remainder = NULL;
	return (new_remainder);
}

char	*get_buffer(char *remainder, char *buffer, int fd)
{
	int		charsread;

	charsread = 1;
	while (charsread != 0)
	{
		charsread = read(fd, buffer, BUFFER_SIZE);
		if (charsread < 0)
			return (NULL);
		if (charsread == 0)
			break ;
		buffer[charsread] = '\0';
		if (remainder == NULL)
			remainder = ft_strdup("");
		if (remainder == NULL)
			return (NULL);
		remainder = func(remainder, buffer);
		if (ft_strchr (buffer, '\n'))
			break ;
	}
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	line = get_buffer(remainder, buffer, fd);
	if (line == NULL)
	{
		free (remainder);
		remainder = NULL;
	}
	free (buffer);
	buffer = NULL;
	remainder = get_remainder(line);
	line = get_line_ps(line);
	return (line);
}
