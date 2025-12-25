/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haabu-sa <haabu-sa@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:19:25 by haabu-sa          #+#    #+#             */
/*   Updated: 2025/12/25 18:16:01 by haabu-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE 64
# include "/home/haabu-sa/file2/libft2.0/libft2.0/libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		moves;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		on_exit;
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*collect;
}	t_game;

int		close_window(void *param);
int		key_pressed(int keycode, void *param);
char	**read_map(char *filename);
int		is_rec(char **map);
int		wall_check(char **map);
int		check_coll(char **map);
int		count_collectibles(char **map);
int		check_exit(char **map);
int		check_player(char **map);
int		check_path(char **map);
void	free_map(char **map);
void	load_images(t_game *g);
void	draw_map(t_game *g);
int		map_height(char **map);
void	find_player(char **map, int *x, int *y);
void	move_player(t_game *g, int dx, int dy);
void	find_player_in_game(t_game *g);
void	cleanup_game(t_game *g);
void	free_partial(char **cpy, int i);

#endif