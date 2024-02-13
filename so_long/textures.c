/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:55:40 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/13 15:46:59 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_image(t_game *game)
{
	game->exit_texture = mlx_load_png(EXIT_PNG);
	game->exit_images = mlx_texture_to_image(game->mlx, game->exit_texture);
	game->wall_texture = mlx_load_png(WALL_PNG);
	game->wall_images = mlx_texture_to_image(game->mlx, game->wall_texture);
	game->player_texture = mlx_load_png(PLAYER_PNG);
	game->player_images = mlx_texture_to_image(game->mlx, game->player_texture);
	game->colle_texture = mlx_load_png(COLLECTIBLE_PNG);
	game->colle_images = mlx_texture_to_image(game->mlx, game->colle_texture);
	game->floor_texture = mlx_load_png(FLOOR_PNG);
	game->floor_images = mlx_texture_to_image(game->mlx, game->floor_texture);
}

void	image_in_map(int x, int y, char c, t_game *img)
{
	if (c == 'E')
		mlx_image_to_window(img->mlx, img->exit_images, x * 64, y * 64);
	if (c == '1')
		mlx_image_to_window(img->mlx, img->wall_images, x * 64, y * 64);
	if (c == 'C')
		mlx_image_to_window(img->mlx, img->colle_images, x * 64, y * 64);
	if (c == '0')
		mlx_image_to_window(img->mlx, img->floor_images, x * 64, y * 64);
	if (c == 'P')
		mlx_image_to_window(img->mlx, img->player_images, x * 64, x * 64);
}

int	render_img(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			image_in_map(x, y, game->map[y][x], game);
			x++;
		}
		y++;
	}
	return (0);
}
