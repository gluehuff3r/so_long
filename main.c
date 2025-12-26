/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haabu-sa <haabu-sa@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:19:11 by haabu-sa          #+#    #+#             */
/*   Updated: 2025/12/26 18:57:32 by haabu-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_map(char **map)
{
	if (!is_rec(map) || !wall_check(map) || !check_exit(map)
		|| !check_player(map) || !check_coll(map) || !check_path(map))
		return (0);
	return (1);
}

static void	init_game(t_game *game)
{
	game->moves = 0;
	game->on_exit = 0;
	game->width = ft_strlen(game->map[0]);
	game->height = map_height(game->map);
	game->collectibles = count_collectibles(game->map);
	find_player_in_game(game);
}

static void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * TILE,
			game->height * TILE, "so_long");
	load_images(game);
	draw_map(game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_hook(game->win, 2, 1L << 0, key_pressed, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\nUsage: ./so_long <map.ber>\n");	
		return (1);
	}
	game.map = read_map(argv[1]);
	if (!game.map)
	{
		ft_printf("Error\nFailed to read map!\n");
		return (1);
	}
	if (!validate_map(game.map))
	{
		ft_printf("Error\nInvalid map!\n");
		free_map(game.map);
		return (1);
	}
	init_game(&game);
	init_mlx(&game);
	mlx_loop(game.mlx);
	return (0);
}
