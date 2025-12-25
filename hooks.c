/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haabu-sa <haabu-sa@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:23:31 by haabu-sa          #+#    #+#             */
/*   Updated: 2025/12/25 18:17:47 by haabu-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup_game(t_game *g)
{
	if (g->wall)
		mlx_destroy_image(g->mlx, g->wall);
	if (g->floor)
		mlx_destroy_image(g->mlx, g->floor);
	if (g->player)
		mlx_destroy_image(g->mlx, g->player);
	if (g->exit)
		mlx_destroy_image(g->mlx, g->exit);
	if (g->collect)
		mlx_destroy_image(g->mlx, g->collect);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	if (g->map)
		free_map(g->map);
}

int	close_window(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	cleanup_game(g);
	exit(0);
	return (0);
}

int	key_pressed(int keycode, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (keycode == XK_Up || keycode == XK_w)
		move_player(g, 0, -1);
	else if (keycode == XK_Down || keycode == XK_s)
		move_player(g, 0, 1);
	else if (keycode == XK_Left || keycode == XK_a)
		move_player(g, -1, 0);
	else if (keycode == XK_Right || keycode == XK_d)
		move_player(g, 1, 0);
	else if (keycode == XK_Escape)
	{
		cleanup_game(g);
		exit(0);
	}
	return (0);
}
