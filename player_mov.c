/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haabu-sa <haabu-sa@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 14:32:03 by haabu-sa          #+#    #+#             */
/*   Updated: 2025/12/25 18:22:23 by haabu-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handle_win(t_game *g)
{
	ft_printf("you won!!!11!! %d\n", g->moves + 1);
	cleanup_game(g);
	exit(0);
}

static void	update_old_position(t_game *g)
{
	if (g->on_exit)
		g->map[g->player_y][g->player_x] = 'E';
	else
		g->map[g->player_y][g->player_x] = '0';
}

static void	update_new_position(t_game *g, int new_x, int new_y)
{
	if (g->map[new_y][new_x] == 'E')
		g->on_exit = 1;
	else
		g->on_exit = 0;
	g->map[new_y][new_x] = 'P';
	g->player_x = new_x;
	g->player_y = new_y;
	g->moves++;
	ft_printf("Moves: %d\n", g->moves);
	mlx_clear_window(g->mlx, g->win);
	draw_map(g);
}

void	move_player(t_game *g, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = g->player_x + dx;
	new_y = g->player_y + dy;
	if (new_x < 0 || new_y < 0 || new_y >= g->height || new_x >= g->width)
		return ;
	if (g->map[new_y][new_x] == '1')
		return ;
	if (g->map[new_y][new_x] == 'C')
		g->collectibles--;
	if (g->map[new_y][new_x] == 'E' && g->collectibles == 0)
		handle_win(g);
	update_old_position(g);
	update_new_position(g, new_x, new_y);
}

void	find_player_in_game(t_game *g)
{
	find_player(g->map, &g->player_x, &g->player_y);
}
