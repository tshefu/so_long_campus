/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:54:40 by vschneid          #+#    #+#             */
/*   Updated: 2023/09/18 12:41:36 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	access_check_ber(char *ber_file)
{
	if (access(ber_file, F_OK | R_OK) == -1)
		startup_error(2, NULL);
}

void	access_check_xpm(void)
{
	if (access("graphics/collectible.xpm", F_OK | R_OK) == -1
		|| access("graphics/floor.xpm", F_OK | R_OK) == -1
		|| access("graphics/goal.xpm", F_OK | R_OK) == -1
		|| access("graphics/player.xpm", F_OK | R_OK) == -1
		|| access("graphics/wall.xpm", F_OK | R_OK) == -1)
		graphic_error(1, NULL);
}

void	gnl_check(char **map, int i, t_game *game)
{
	if (!map[i])
	{
		i = 0;
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
		map_error(9, game);
	}
}
