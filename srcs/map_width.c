/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:37:25 by dtanski           #+#    #+#             */
/*   Updated: 2024/09/24 14:39:40 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_width(t_root *root, char *file)
{
	root->game->width = 0;
	while (file[root->game->width] && file[root->game->width] != '\n')
		root->game->width++;
	if (root->game->width == 0 || file[root->game->width] == 0)
	{
		free(file);
		root_destroy(root, "Map is invalid!", 0);
	}
}
