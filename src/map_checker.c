/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:41:10 by vschneid          #+#    #+#             */
/*   Updated: 2023/08/27 22:33:56 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	check_valid_map(t_game *game)
{
	check_full_walls(game);
	check_rectangle(game);
	check_valid_characters(game);
	find_player(game);
	flood_fill(game);
}

void	check_rectangle(t_game *game)
{
	int	j;

	j = 0;
	while (game->map->map[j] && j < game->map->height)
	{
		if (ft_strlen(game->map->map[j]) != (size_t)game->map->width)
			map_error(6, game);
		j++;
	}
}

void	check_full_walls(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map->map[j])
	{
		i = 0;
		while (game->map->map[j][i])
		{
			if (i == 0 || i == game->map->width - 1)
			{
				if (game->map->map[j][i] != '1')
					map_error(1, game);
			}
			if (j == 0 || j == game->map->height - 1)
			{
				if (game->map->map[j][i] != '1')
					map_error(1, game);
			}
			i++;
		}
		j++;
	}
}
