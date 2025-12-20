/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haabu-sa <haabu-sa@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:19:25 by haabu-sa          #+#    #+#             */
/*   Updated: 2025/12/20 17:54:49 by haabu-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SO_LONG_H
# define SO_LONG_H

#include "/home/haabu-sa/file2/libft2.0/libft2.0/libft.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		moves;
	void	*mlx;
	void	*win;
}	t_game;


int 	close_window(void *param);
int 	key_pressed(int keycode, void *param);
char	**read_map(char *filename);
int 	is_rec(char **map);
int 	wall_check(char **map);
int 	check_coll(char **map);
int 	check_exit(char **map);
int 	check_player(char **map);
int		check_path(char **map);
void	free_map(char **map);

#endif
