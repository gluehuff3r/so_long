/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haabu-sa <haabu-sa@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:01:04 by haabu-sa          #+#    #+#             */
/*   Updated: 2025/12/25 18:16:31 by haabu-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rec(char **map)
{
	int	i;
	int	len;
	int	j;

	j = 0;
	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		j = ft_strlen(map[i]);
		if (j != len)
			return (0);
		i++;
	}
	return (1);
}

int	wall_check(char **map)
{
	int	i;
	int	j;
	int	height;
	int	width;

	width = ft_strlen(map[0]);
	j = 0;
	height = 0;
	while (map[height])
		height++;
	while (j < width)
	{
		if (map[0][j] != '1' || map[height - 1][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	free_partial(char **cpy, int i)
{
	while (--i >= 0)
		free(cpy[i]);
	free(cpy);
}
