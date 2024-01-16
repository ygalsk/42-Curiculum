/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:58:44 by dkremer           #+#    #+#             */
/*   Updated: 2024/01/16 22:48:11 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/include/MLX42/MLX42.h"
#include "so_long.h"

mlx_t	*load_textures(void)
{
	mlx_texture_t	**textures;
	mlx_image_t		**img;
	mlx_t			*mlx;

	textures = (mlx_texture_t **)malloc(sizeof(mlx_texture_t *));
	if (!textures)
		error();
	img = (mlx_image_t **)malloc(sizeof(mlx_image_t *));
	if (!img)
		error();
	mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!mlx)
		error();
	// Try to load the file
	textures[0] = mlx_load_png(PLAYER_PNG);
	textures[1] = mlx_load_png(COLLECTIBLE_PNG);
	if (!textures)
		error();
	// Convert texture to a displayable image
	img[0] = mlx_texture_to_image(mlx, textures[0]);
	img[1] = mlx_texture_to_image(mlx, textures[1]);
	if (!img)
		error();
	// Display the image
	if (mlx_image_to_window(mlx, img[0], 0, 0) < 0)
		error();
	if (mlx_image_to_window(mlx, img[1], 50, 50) < 0)
		error();
	free(textures);
	free(img);
	return (mlx);
}
