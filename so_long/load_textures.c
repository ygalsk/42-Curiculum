/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:58:44 by dkremer           #+#    #+#             */
/*   Updated: 2024/01/18 20:26:14 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_texture_manager	*init_texture_manager(char **paths, size_t num_textures)
{
	t_texture_manager	*manager;

	manager = (t_texture_manager *)malloc(sizeof(t_texture_manager));
	if (!manager)
		error();
	manager->num_textures = num_textures;
	manager->texture_paths = paths;
	manager->textures = NULL;
	manager->images = NULL;
	manager->mlx = NULL;
	return (manager);
}

void	load_and_display_textures(t_texture_manager *manager)
{
	size_t	i;

	manager->textures = (mlx_texture_t **)malloc(manager->num_textures
			* sizeof(mlx_texture_t *));
	manager->images = (mlx_image_t **)malloc(manager->num_textures
			* sizeof(mlx_image_t *));
	manager->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!manager->mlx || !manager->textures || !manager->images)
		error();
	i = 0;
	while (i < manager->num_textures)
	{
		manager->textures[i] = mlx_load_png(manager->texture_paths[i]);
		if (!manager->textures[i])
			error();
		manager->images[i] = mlx_texture_to_image(manager->mlx,
				manager->textures[i]);
		if (!manager->images[i])
			error();
					// actually putting the textures on the corresponding pixel
		if (mlx_image_to_window(manager->mlx, manager->images[i], i * 50, i
				* 50) < 0)
			error();
		++i;
	}
}

void	free_texture_manager(t_texture_manager *manager)
{
	size_t	i;

	i = 0;
	while (i < manager->num_textures)
	{
		mlx_delete_texture(manager->textures[i]);
		mlx_delete_image(manager->mlx, manager->images[i]);
		++i;
	}
	free(manager->textures);
	free(manager->images);
	free(manager);
}
