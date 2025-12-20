/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haabu-sa <haabu-sa@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:19:11 by haabu-sa          #+#    #+#             */
/*   Updated: 2025/12/20 18:12:02 by haabu-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"


int main(int argc, char **argv)
{
	t_game game;
	int	i;
	
	if (argc != 2)
	{
		ft_printf("error must provide a map\n");
		return (1);	
	}
	game.map = read_map(argv[1]);
	if (!game.map)
	{
		ft_printf("failed to read map\n");
		return (1);	
	}
	i = 0;
	while (game.map[i])
	{
		ft_printf("line %d: %s\n",i,game.map[i]);
		i++;
	}
	game.map = read_map(argv[1]);
	if (!game.map)
	{
		ft_printf("failed to read map\n");
		return (1);	
	}
	if (!is_rec(game.map))
	{
		ft_printf("map is fucked\n");
		return (1);
	}
	if (!wall_check(game.map))
	{
		ft_printf("your walls are missing (-_-)\n");
		return (1);
	}
	if (!check_exit(game.map))
	{
		ft_printf("player is stuck !!!!!!!!!!!!!!!!\n");
		return (1);
	}
	if (!check_player(game.map))
	{
		ft_printf("must have 1 player\n");
		return (1);
	}
	if (!check_coll(game.map))
	{
		ft_printf("must have at least 1 collectible\n");
		return (1);
	}
	if (!check_path(game.map))
	{
    	ft_printf("some collectibles or exit are unreachable (-_-)\n");
    	return (1);
	}

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 400, 400, "so_long");

	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_hook(game.win, 2, 1L<<0, key_pressed, &game);
	mlx_loop(game.mlx);
	
}
