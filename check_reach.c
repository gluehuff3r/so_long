/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reach.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haabu-sa <haabu-sa@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:03:10 by haabu-sa          #+#    #+#             */
/*   Updated: 2025/12/25 18:16:42 by haabu-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map)
{
	char	**cpy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	cpy = malloc(sizeof(char *) * (i + 1));
	if (!cpy)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		cpy[i] = ft_strdup(map[i]);
		if (!cpy[i])
		{
			free_partial(cpy, i);
			return (NULL);
		}
	}
	cpy[i] = NULL;
	return (cpy);
}

void	flood_fill(char **map, int x, int y)
{
	int	width;
	int	height;

	height = 0;
	while (map[height])
		height++;
	width = ft_strlen(map[0]);
	if (x < 0 || y < 0 || x >= width || y >= height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	*x = -1;
	*y = -1;
}

int	check_reach(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_path(char **map)
{
	char	**temp;
	int		x;
	int		y;

	temp = copy_map(map);
	if (!temp)
		return (0);
	find_player(temp, &x, &y);
	if (x == -1 || y == -1)
	{
		free_map(temp);
		return (0);
	}
	flood_fill(temp, x, y);
	if (!check_reach(temp))
	{
		free_map(temp);
		return (0);
	}
	free_map(temp);
	return (1);
}
