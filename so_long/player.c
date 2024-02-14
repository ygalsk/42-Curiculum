/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:03:36 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/14 13:26:37 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/include/MLX42/MLX42.h"
#include "so_long.h"

void	find_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height && !game->player_pos_found)
	{
		x = 0;
		while (x < game->width && !game->player_pos_found)
		{
			if (game->map[y][x] == PLAYER)
			{
				game->player_posx = x;
				game->player_posy = y;
				game->player_pos_found = 1;
			}
			x++;
		}
		y++;
	}
}

int	find_c(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == COLLECTIBLE)
			{
				game->collectible++;
				game->coll_posx = x;
				game->coll_posy = y;
			}
			x++;
		}
		y++;
	}
	return (game->collectible);
	ft_printf("Collectible: %d\n", game->collectible);
}

void	get_c(t_game *game)
{
	int	y;
	int	x;

	x = game->player_posx;
	y = game->player_posy;
	if (game->map[y][x] == COLLECTIBLE)
	{
		game->collectible--;
		game->map[y][x] = FLOOR;
		ft_printf("Collectibles left: %d\n", game->collectible);
		load_player(game);
		load_map(x, y, game->map[y][x], game);
		game->player_posx = x;
		game->player_posy = y;
		mlx_image_to_window(game->mlx, game->player_images, game->player_posx \
											* 64, game->player_posy * 64);
	}
	if (game->map[y][x] == EXIT)
	{
		if (game->collectible != 0)
			return ;
		ft_printf("CONGRATS!%s");
		quit_game(game);
	}
}
