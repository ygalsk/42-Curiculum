/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:11:42 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/13 01:02:13 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft/libft.h"
#include "so_long.h"

int	map_file_check(char *filename)
{
	char	*temp;

	temp = ft_strnstr(filename, ".ber", ft_strlen(filename));
	if (temp == NULL)
		return (1);
	else if (ft_strlen(temp) > 4)
		return (1);
	else
		return (0);
}

// void	get_map(char *filename, t_game game)
// {
// 	
// }
//
void	file_to_map(t_game *game, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		game->map_temp = ft_strjoin_gnl(game->map_temp, line);
		free(line);
		if (!game->map_temp)
			exit (1);
		game->height++;
		line = get_next_line(fd);
	}
}

void	save_map(char *file, t_game *game)
{
	int	fd;

	game->map_temp = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(1);
	file_to_map(game, fd);
	close(fd);
	game->map = ft_split(game->map_temp, '\n');
	if (!game->map)
	{
		free_map(game);
		exit(1);
	}
	free(game->map_temp);
}
