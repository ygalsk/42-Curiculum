/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:15:34 by dkremer           #+#    #+#             */
/*   Updated: 2024/01/17 00:24:10 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// include needed libs
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/libft/ft_printf/ft_printf.h"
# include "lib/libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

// define window size
# define WIDTH 256
# define HEIGHT 256

// define map
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'

// define textures
# define WALL_PNG "./asssets/wall.png"
# define FLOOR_PNG "./asssets/floor.png"
# define PLAYER_PNG "./asssets/player.png"
# define COLLECTIBLE_PNG "./asssets/collectible.png"
# define EXIT_PNG "./asssets/exit.png"

// Texture manager struct definition
typedef struct s_texture_manager
{
	mlx_texture_t	**textures;
	mlx_image_t		**images;
	mlx_t			*mlx;
	size_t			num_textures;
	char			**texture_paths;
}					t_texture_manager;

void				error(void);
t_texture_manager	*init_texture_manager(char **paths, size_t num_textures);
void				load_and_display_textures(t_texture_manager *manager);
void				free_texture_manager(t_texture_manager *manager);

#endif
