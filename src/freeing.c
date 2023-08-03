/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:44:13 by vschneid          #+#    #+#             */
/*   Updated: 2023/07/21 11:58:09 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void freeing(t_game *game)
{
    int i;
    
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
            free(game->map);
        }
        free_mlx(game);
        free(game);
    }
    exit(1);
}

void free_mlx(t_game *game)
{
    if (game->graphic)
    {
        if(game->graphic->floor)
            mlx_destroy_image(game->mlxptr, game->graphic->floor);
        if (game->graphic->player)
            mlx_destroy_image(game->mlxptr, game->graphic->player);
        if (game->graphic->wall)
            mlx_destroy_image(game->mlxptr, game->graphic->wall);
        if (game->graphic->goal)
            mlx_destroy_image(game->mlxptr, game->graphic->goal);
        if (game->graphic->collectible)
            mlx_destroy_image(game->mlxptr, game->graphic->collectible);
        free(game->graphic);
    }
    if (game->mlxptr)
    {
        if (game->window)
            mlx_destroy_window(game->mlxptr, game->window);
        mlx_destroy_display(game->mlxptr);
        free(game->mlxptr);
    }
}