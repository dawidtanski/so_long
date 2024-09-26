/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:45:42 by dtanski           #+#    #+#             */
/*   Updated: 2024/09/24 14:49:39 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_root *root, int x, int y)
{
	if (root->game->map[y - 1][x] == 0)
		root->game->player.y -= 1;
}

void	move_down(t_root *root, int x, int y)
{
	if (root->game->map[y + 1][x] == 0)
		root->game->player.y += 1;
}

void	move_left(t_root *root, int x, int y)
{
	if (root->game->map[y][x - 1] == 0)
		root->game->player.x -= 1;
}

void	move_right(t_root *root, int x, int y)
{
	if (root->game->map[y][x + 1] == 0)
		root->game->player.x += 1;
}
