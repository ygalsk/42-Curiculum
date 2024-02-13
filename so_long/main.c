/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:52:27 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/13 15:29:42 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/include/MLX42/MLX42.h"
#include "lib/libft/libft.h"
#include "so_long.h"
#include <stdlib.h>

void	ft_init(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!game->mlx)
		exit(EXIT_FAILURE);
	load_image(game);
	render_img(game);
	mlx_loop_hook(game->mlx, keyhooks, game);
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

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		exit(EXIT_FAILURE);
	map_file_check(argv[1]);
	game = init();
	save_map(argv[1], game);
	ft_init(game);
	mlx_terminate(game->mlx);
	free(game);
}
