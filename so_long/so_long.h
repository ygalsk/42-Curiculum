/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:15:34 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/14 13:24:37 by dkremer          ###   ########.fr       */
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
# define WALL_PNG "./assets/wall.png"
# define FLOOR_PNG "./assets/floor.png"
# define PLAYER_PNG "./assets/player.png"
# define COLLECTIBLE_PNG "./assets/collectible.png"
# define EXIT_PNG "./assets/exit.png"

// Game struct definition
typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	char			*map_temp;
	int				width;
	int				height;
	int				player_posx;
	int				player_posy;
	int				**player;
	int				player_pos_found;
	int				moves;
	int				collectible;
	int				coll_posx;
	int				coll_posy;
	int				**coll;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*floor_texture;
	mlx_texture_t	*player_texture;
	mlx_texture_t	*colle_texture;
	mlx_texture_t	*exit_texture;
	mlx_image_t		*wall_images;
	mlx_image_t		*floor_images;
	mlx_image_t		*player_images;
	mlx_image_t		*colle_images;
	mlx_image_t		*exit_images;
}					t_game;

void				error(void);
void				load_image(t_game *img);
void				image_to_win(int x, int y, char c, t_game *img);
int					render_img(t_game *img);
int					map_file_check(char *filename);
int					quit_game(t_game *game);
void				keyhooks(mlx_key_data_t keydata, void *param);
void				free_img(t_game *game);
void				free_map(t_game *game);
int					map_file_check(char *filename);
void				file_to_map(t_game *game, int fd);
void				save_map(char *file, t_game *game);
void				find_player_position(t_game *game);
void				move_y(t_game *game, char key);
void				move_x(t_game *game, char key);
int					find_c(t_game *game);
void				get_c(t_game *game);
void				load_player(t_game *game);
void				image_in_map(int x, int y, char c, t_game *img);
void				load_map(int x, int y, char c, t_game *img);

#endif
