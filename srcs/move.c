/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:29:43 by dtanski           #+#    #+#             */
/*   Updated: 2024/11/22 11:35:47 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_positions(t_data_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.map_width)
	{
		y = 0;
		while (y < game->map.map_height)
		{
			if (game->map.map[y][x] == 'P')
			{
				game->map.player_x_position = x;
				game->map.player_y_position = y;
			}
			if (game->map.map[y][x] == 'E')
			{
				game->map.exit_x = x;
				game->map.exit_y = y;
			}
			y++;
		}
		x++;
	}
}

void	move_player_up(t_data_game *game)
{
	int	x;
	int	y;

	x = game->map.player_x_position;
	y = game->map.player_y_position;
	if (game->map.map[y - 1][x] != '1')
	{
		game->moves_count++;
		ft_printf("Player made %d moves\n", game->moves_count);
		if (game->map.map[y - 1][x] == 'C')
			game->total_collectibles--;
		game->map.map[y][x] = '0';
		game->map.map[game->map.exit_y][game->map.exit_x] = 'E';
		if (game->map.map[y - 1][x] == 'E' && game->total_collectibles == 0)
			end_game(game, NULL, 0);
		game->map.map[y - 1][x] = 'P';
		game->player.direction = 'U';
		game->map.player_y_position = y - 1;
	}
	render_map(game);
}

void	move_player_down(t_data_game *game)
{
	int	x;
	int	y;

	x = game->map.player_x_position;
	y = game->map.player_y_position;
	if (game->map.map[y + 1][x] != '1')
	{
		game->moves_count++;
		ft_printf("Player made %d moves\n", game->moves_count);
		if (game->map.map[y + 1][x] == 'C')
			game->total_collectibles--;
		game->map.map[y][x] = '0';
		game->map.map[game->map.exit_y][game->map.exit_x] = 'E';
		if (game->map.map[y + 1][x] == 'E' && game->total_collectibles == 0)
			end_game(game, NULL, 0);
		game->map.map[y + 1][x] = 'P';
		game->player.direction = 'D';
		game->map.player_y_position = y + 1;
	}
	render_map(game);
}

void	move_player_left(t_data_game *game)
{
	int	x;
	int	y;

	x = game->map.player_x_position;
	y = game->map.player_y_position;
	if (game->map.map[y][x - 1] != '1')
	{
		game->moves_count++;
		ft_printf("Player made %d moves\n", game->moves_count);
		if (game->map.map[y][x - 1] == 'C')
			game->total_collectibles--;
		game->map.map[y][x] = '0';
		game->map.map[game->map.exit_y][game->map.exit_x] = 'E';
		if (game->map.map[y][x - 1] == 'E' && game->total_collectibles == 0)
			end_game(game, NULL, 0);
		game->map.map[y][x - 1] = 'P';
		game->player.direction = 'L';
		game->map.player_x_position = x - 1;
	}
	render_map(game);
}

void	move_player_right(t_data_game *game)
{
	int	x;
	int	y;

	x = game->map.player_x_position;
	y = game->map.player_y_position;
	if (game->map.map[y][x + 1] != '1')
	{
		game->moves_count++;
		ft_printf("Player made %d moves\n", game->moves_count);
		if (game->map.map[y][x + 1] == 'C')
			game->total_collectibles--;
		game->map.map[y][x] = '0';
		game->map.map[game->map.exit_y][game->map.exit_x] = 'E';
		if (game->map.map[y][x + 1] == 'E' && game->total_collectibles == 0)
			end_game(game, NULL, 0);
		game->map.map[y][x + 1] = 'P';
		game->player.direction = 'R';
		game->map.player_x_position = x + 1;
	}
	render_map(game);
}
