/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:51:00 by vschneid          #+#    #+#             */
/*   Updated: 2023/09/29 23:58:11 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	freeing(t_game *game)
{
	int	i;

	i = 0;
	if (game != NULL)
	{
		if (game->map != NULL)
		{
			if (game->map->map != NULL)
			{
				while (game->map->map[i])
				{
					free(game->map->map[i]);
					i++;
				}
				free(game->map->map);
			}
			free_graphic(game);
			free_mlxptr(game);
			free(game->map);
		}
		free(game);
	}
	exit(1);
}

void	free_graphic(t_game *game)
{
	if (game->graphic)
	{
		if (game->graphic->collectible)
			mlx_destroy_image(game->mlxptr, game->graphic->collectible);
		if (game->graphic->floor)
			mlx_destroy_image(game->mlxptr, game->graphic->floor);
		if (game->graphic->goal_off)
			mlx_destroy_image(game->mlxptr, game->graphic->goal_off);
		if (game->graphic->player)
			mlx_destroy_image(game->mlxptr, game->graphic->player);
		if (game->graphic->wall)
			mlx_destroy_image(game->mlxptr, game->graphic->wall);
		free(game->graphic);
	}
}

void	free_mlxptr(t_game *game)
{
	if (game->mlxptr)
	{
		if (game->window)
			mlx_destroy_window(game->mlxptr, game->window);
		mlx_destroy_display(game->mlxptr);
		free(game->mlxptr);
	}
}
