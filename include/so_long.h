/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:32:39 by dtanski   	       #+#    #+#             */
/*   Updated: 2024/11/22 11:16:02 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "key_alias.h"
# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include <fcntl.h>

# define SPRITE_SIZE 50

# define COLLECTIBLE "textures/collectible.xpm"
# define EXIT "textures/exit.xpm"
# define WALL "textures/wall.xpm"
# define FLOOR "textures/tile.xpm"
# define PLAYER_R "textures/player-right.xpm"
# define PLAYER_L "textures/player-left.xpm"
# define PLAYER_U "textures/player-up.xpm"
# define PLAYER_D "textures/player-down.xpm"

typedef struct s_map
{
	char		**map;
	int			map_width;
	int			map_height;
	int			player_x_position;
	int			player_y_position;
	int			exit_x;
	int			exit_y;
}				t_map;

typedef struct s_image
{
	void		*texture_ptr;
	int			x;
	int			y;
}				t_image;

typedef struct s_player
{
	t_image		player_r;
	t_image		player_l;
	t_image		player_u;
	t_image		player_d;
	char		direction;
}				t_player;

typedef struct s_data_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			total_collectibles;
	int			moves_count;
	t_map		map;
	t_image		collectible_image;
	t_image		exit_image;
	t_image		wall_image;
	t_image		floor_image;
	t_player	player;
	/*check accesible elements*/
	int			total_collectibles_found;
	int			exit_found;
}				t_data_game;

typedef struct s_element_count
{
	int	player;
	int	exit;
}	t_element_count;

// init possition E and P, and move player
void			init_positions(t_data_game *game);
void			move_player_up(t_data_game *game);
void			move_player_down(t_data_game *game);
void			move_player_left(t_data_game *game);
void			move_player_right(t_data_game *game);

// init sprites and render sprites and map
void			init_sprites(t_data_game *game);
t_image			create_sprite(t_data_game *game, char *path);
void			render_sprite(t_data_game *game, t_image *sprite, int line,
					int column);
void			render_player(t_data_game *game, int line, int column);
int				render_map(t_data_game *game);

// read map with file and fill map and check expections
void			read_map(t_data_game *game, char *path);
void			fill_map(t_data_game *game, char *path);
void			validate_elements(t_data_game *game);
void			check_walls(t_data_game *game);
void			count_elements(t_data_game *game);
void			process_map_element(t_data_game *game, int i, int j,
					t_element_count *count);

// Utils
int				open_map(char *path, t_data_game *game);
char			*split_line(char *line);
void			display_moves_and_collectibles(t_data_game *game);

// Messages
int				end_game(t_data_game *game, char *message, int code);
void			destroy_images(t_data_game *game);
void			exit_message(t_data_game *game, char *message, int code);
void			validate_path(t_data_game *game);

#endif
