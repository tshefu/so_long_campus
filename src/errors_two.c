/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:49:44 by vschneid          #+#    #+#             */
/*   Updated: 2023/09/27 18:29:24 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	opening_error(char **map, t_game *game)
{
	free(map);
	perror("Error:");
	ft_putstr_fd(KRED "Could not open file\n" KNRM, 2);
	freeing(game);
}

void	missing_map(char **map, t_game *game)
{
	free(map);
	malloc_error(3, game);
}

void	malloc_error(int id, t_game *game)
{
	perror("Error");
	if (id == 1)
		ft_putstr_fd(KRED "Malloc failed (game initialising)\n" KNRM, 2);
	if (id == 2)
		ft_putstr_fd(KRED "Malloc failed (rendering image)\n" KNRM, 2);
	if (id == 3)
		ft_putstr_fd(KRED "Malloc failed (no map)\n" KNRM, 2);
	freeing(game);
}

void	access_check_images(t_game *game)
{
	if (game->graphic->collectible == NULL
		|| game->graphic->floor == NULL || game->graphic->goal_off == NULL
		|| game->graphic->player == NULL || game->graphic->wall == NULL)
		graphic_error(game);
}
