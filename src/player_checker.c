/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 22:33:42 by vschneid          #+#    #+#             */
/*   Updated: 2023/09/18 12:29:41 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	check_valid_characters(t_game *game)
{
	int	i;
	int	j;
	int	x;

	j = 0;
	while (j < game->map->height)
	{
		i = 0;
		while (i < game->map->width)
		{
			x = 0;
			while (game->map->map[j][i] != "01CEP"[x])
			{
				if (!"01CEP"[x])
					map_error(2, game);
				x++;
			}
			count_characters("01CEP"[x], game);
			i++;
		}
		j++;
	}
	check_characters(game);
}

void	count_characters(char c, t_game *game)
{
	if (c == 'P')
		game->map->playercounter++;
	if (c == 'E')
		game->map->exitcounter++;
	if (c == 'C')
		game->map->collcounter++;
}

void	check_characters(t_game *game)
{
	if (game->map->playercounter != 1)
		map_error(3, game);
	if (game->map->exitcounter != 1)
		map_error(4, game);
	if (game->map->collcounter < 1)
		map_error(5, game);
}

void	find_player(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map->map[j])
	{
		i = 0;
		while (game->map->map[j][i])
		{
			if (game->map->map[j][i] == 'P')
			{
				game->map->plpoy = j;
				game->map->plpox = i;
				return ;
			}
			i++;
		}
		j++;
	}
	map_error(3, game);
}
