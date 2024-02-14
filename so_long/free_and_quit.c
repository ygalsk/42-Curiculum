/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_quit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:49:50 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/14 13:24:13 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/include/MLX42/MLX42.h"
#include "so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	free_img(t_game *game)
{
	mlx_delete_texture(game->exit_texture);
	mlx_delete_texture(game->wall_texture);
	mlx_delete_texture(game->player_texture);
	mlx_delete_texture(game->colle_texture);
	mlx_delete_texture(game->floor_texture);
	mlx_delete_image(game->mlx, game->exit_images);
	mlx_delete_image(game->mlx, game->wall_images);
	mlx_delete_image(game->mlx, game->player_images);
	mlx_delete_image(game->mlx, game->colle_images);
	mlx_delete_image(game->mlx, game->floor_images);
	mlx_close_window(game->mlx);
	free_map(game);
}

int	quit_game(t_game *game)
{
	free_img(game);
	free(game);
	exit(0);
}
