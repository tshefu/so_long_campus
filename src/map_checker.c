/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:41:10 by vschneid          #+#    #+#             */
/*   Updated: 2023/09/25 18:36:33 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	check_valid_map(t_game *game, int fd)
{
	check_full_walls(game, fd);
	check_rectangle(game, fd);
	check_valid_characters(game, fd);
	find_player(game, fd);
	flood_fill(game, fd);
}

void	check_rectangle(t_game *game, int fd)
{
	int	j;

	j = 0;
	while (game->map->map[j] && j < game->map->height)
	{
		if (ft_strlen(game->map->map[j]) != (size_t)game->map->width)
			map_error(6, game, fd);
		j++;
	}
}

void	check_full_walls(t_game *game, int fd)
{
	int	i;
	int	j;

	j = 0;
	while (game->map->map[j])
	{
		i = 0;
		while (game->map->map[j][i])
		{
			if ((i == 0 || i == game->map->width - 1)
				|| (j == 0 || j == game->map->height - 1))
			{
				if (game->map->map[j][i] != '1')
					map_error(1, game, fd);
			}
			i++;
		}
		j++;
	}
}
