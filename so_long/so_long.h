/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:15:34 by dkremer           #+#    #+#             */
/*   Updated: 2024/01/16 22:32:51 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// include needed libs
# include "lib/libft/libft.h"
# include "lib/libft/ft_printf/ft_printf.h"
# include "lib/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>

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

void	error(void);
mlx_t	*load_textures(void);

#endif
