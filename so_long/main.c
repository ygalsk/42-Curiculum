/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:52:27 by dkremer           #+#    #+#             */
/*   Updated: 2024/01/18 20:25:20 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(void *param)
{
	t_texture_manager	*manager;

	manager = (t_texture_manager *)param;
	if (mlx_is_key_down(manager->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(manager->mlx);
}

int32_t	main(void)
{
	t_texture_manager	*manager;
	char				*texture_paths[5];

	texture_paths[0] = WALL_PNG;
	texture_paths[1] = FLOOR_PNG;
	texture_paths[2] = PLAYER_PNG;
	texture_paths[3] = COLLECTIBLE_PNG;
	texture_paths[4] = EXIT_PNG;
	manager = init_texture_manager(texture_paths, sizeof(texture_paths)
			/ sizeof(char *));
	if (!manager)
		error();
	load_and_display_textures(manager);
	mlx_loop_hook(manager->mlx, ft_hook, manager);
	mlx_loop(manager->mlx);
	mlx_terminate(manager->mlx);
	free_texture_manager(manager);
	return (EXIT_SUCCESS);
}
