/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haabu-sa <haabu-sa@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:51:36 by haabu-sa          #+#    #+#             */
/*   Updated: 2025/12/21 12:19:43 by haabu-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images (t_game *g)
{
	int	w;
	int	h;

	g->wall = mlx_xpm_file_to_image(g->mlx, "textures/W.xpm", &w, &h);
	g->floor = mlx_xpm_file_to_image(g->mlx, "textures/F.xpm", &w, &h);
	g->player = mlx_xpm_file_to_image(g->mlx, "textures/P.xpm", &w, &h);
	g->exit = mlx_xpm_file_to_image(g->mlx, "textures/E.xpm", &w, &h);
	g->collect = mlx_xpm_file_to_image(g->mlx, "textures/C.xpm", &w, &h);
}


