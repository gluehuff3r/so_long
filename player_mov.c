/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haabu-sa <haabu-sa@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 14:32:03 by haabu-sa          #+#    #+#             */
/*   Updated: 2025/12/21 16:50:25 by haabu-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void find_player(t_game *g)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (g->map[y])
// 	{
// 		x = 0;
// 		while (g->map[x][y])
// 		{
// 			if (g->map[x][y] == 'P')
// 			{
// 				g->player_x = x;
// 				g->player_y = y;
// 				return;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	move_player(t_game *g, int dx, int dy)
{
	int new_x;
	int new_y;

	new_x = g->player_x + dx;
	new_y = g->player_y + dy;
	if (new_x < 0 || new_y < 0 || new_y >= g->height || new_x >= g->width)
		return ;
	if (g->map[new_y][new_x] == '1')
		return ;
	if (g->map[new_y][new_x] == 'C')
		g->collectibles--;
	if (g->map[new_y][new_x] == 'E' && g->collectibles == 0)
	{
		ft_printf("you won!!!11!! %d\n", g->moves + 1);
		exit(0);
	}
	if (g->on_exit)
		g->map[g->player_y][g->player_x] = 'E';
	else
		g->map[g->player_y][g->player_x] = '0';
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
// int keys (int keycode, t_game *g)
// {
// 	if (keycode == 13 || keycode == 126) //w
// 	move_player(g, 0, -1);
// 	else if (keycode == 1 || keycode == 125) //s
// 		move_player(g, 0, 1);
// 	else if (keycode == 0 || keycode == 123) //a
// 		move_player(g, -1, 0);
// 	else if (keycode == 2 || keycode == 124) //d
// 		move_player(g, 1, 0);
// 	else if (keycode == 53) //esc
// 		exit(0);
		
// 	return (0);
// }
void	find_player_in_game(t_game *g)
{
	find_player(g->map, &g->player_x, &g->player_y);
}