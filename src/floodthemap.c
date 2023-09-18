/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodthemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:48:13 by vschneid          #+#    #+#             */
/*   Updated: 2023/08/27 22:35:52 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	fill(map, y - 1, x);
	fill(map, y + 1, x);
	fill(map, y, x - 1);
	fill(map, y, x + 1);
}

void	check_floodfill(t_game *game, char **map)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map->height)
	{
		i = 0;
		while (i < game->map->width)
		{
			if (map[j][i] == 'C' || map[j][i] == 'E')
			{
				i = 0;
				while (map[i])
				{
					free(map[i]);
					i++;
				}
				free(map);
				map_error(7, game);
			}
			i++;
		}
		j++;
	}
}

void	flood_fill(t_game *game)
{
	char	**map;
	int		i;

	i = 0;
	map = ft_calloc(1, sizeof(char *) * (game->map->height + 1));
	if (!map)
		malloc_error(1, game);
	while (i < game->map->height)
	{
		map[i] = ft_strdup(game->map->map[i]);
		i++;
	}
	fill(map, game->map->plpoy, game->map->plpox);
	check_floodfill(game, map);
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
