/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haabu-sa <haabu-sa@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:53:51 by haabu-sa          #+#    #+#             */
/*   Updated: 2025/12/25 18:16:58 by haabu-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_tile(t_game *g, char c, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, g->floor, x, y);
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->wall, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->player, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->collect, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->exit, x, y);
}

void	draw_map(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			draw_tile(g, g->map[y][x], x * TILE, y * TILE);
			x++;
		}
		y++;
	}
}
