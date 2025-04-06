/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:29:50 by dtanski           #+#    #+#             */
/*   Updated: 2024/11/22 10:35:33 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_sprites(t_data_game *game)
{
	game->collectible_image = create_sprite(game, COLLECTIBLE);
	game->exit_image = create_sprite(game, EXIT);
	game->wall_image = create_sprite(game, WALL);
	game->floor_image = create_sprite(game, FLOOR);
	game->player.player_r = create_sprite(game, PLAYER_R);
	game->player.player_l = create_sprite(game, PLAYER_L);
	game->player.player_u = create_sprite(game, PLAYER_U);
	game->player.player_d = create_sprite(game, PLAYER_D);
}

t_image	create_sprite(t_data_game *game, char *path)
{
	t_image	sprite;

	sprite.texture_ptr = mlx_xpm_file_to_image(game->mlx_ptr, path, &sprite.x,
			&sprite.y);
	if (!sprite.texture_ptr)
		end_game(game, "No loaded sprite", 1);
	return (sprite);
}

void	render_sprite(t_data_game *game, t_image *sprite, int line, int column)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite->texture_ptr,
		column * SPRITE_SIZE, line * SPRITE_SIZE);
}

void	render_player(t_data_game *game, int line, int column)
{
	if (game->player.direction == 'R')
		render_sprite(game, &game->player.player_r, line, column);
	else if (game->player.direction == 'L')
		render_sprite(game, &game->player.player_l, line, column);
	else if (game->player.direction == 'U')
		render_sprite(game, &game->player.player_u, line, column);
	else if (game->player.direction == 'D')
		render_sprite(game, &game->player.player_d, line, column);
}

int	render_map(t_data_game *game)
{
	int	line;
	int	column;

	line = 0;
	while (line < game->map.map_height)
	{
		column = 0;
		while (column < game->map.map_width)
		{
			if (game->map.map[line][column] == 'E')
				render_sprite(game, &game->exit_image, line, column);
			if (game->map.map[line][column] == 'C')
				render_sprite(game, &game->collectible_image, line, column);
			if (game->map.map[line][column] == '1')
				render_sprite(game, &game->wall_image, line, column);
			if (game->map.map[line][column] == '0')
				render_sprite(game, &game->floor_image, line, column);
			if (game->map.map[line][column] == 'P')
				render_player(game, line, column);
			column++;
		}
		line++;
	}
	display_moves_and_collectibles(game);
	return (0);
}
