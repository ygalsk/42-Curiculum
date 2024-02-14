/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:52:27 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/14 12:28:53 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	game_init(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(game->width * 64, game->height * 64, "so_long", true);
	if (!game->mlx)
		exit(EXIT_FAILURE);
	load_image(game);
	render_img(game);
	mlx_image_to_window(game->mlx, game->player_images, game->player_posx * 64, \
											game->player_posy * 64);
	mlx_key_hook(game->mlx, keyhooks, game);
	mlx_loop(game->mlx);
}

t_game	*init(void)
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		exit(EXIT_FAILURE);
	game->width = 0;
	game->height = 0;
	return (game);
}

void	leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_game	*game;

	atexit(&leaks);
	if (argc != 2)
		exit(EXIT_FAILURE);
	map_file_check(argv[1]);
	game = init();
	save_map(argv[1], game);
	find_c(game);
	game_init(game);
	mlx_terminate(game->mlx);
	quit_game(game);
}
