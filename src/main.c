/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:11:57 by vschneid          #+#    #+#             */
/*   Updated: 2023/07/23 13:41:40 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game *game;
    int file;

    if (argc == 1)
        game_error(13, NULL);
    file = mapfilechecker(argv[1]);
    if (argc != 2 || file == -1)
        game_error(13, NULL);
    game = initialise_struct(argv[1]);
    game->mlxptr = mlx_init();
    if (!game->mlxptr)
        game_error(13, NULL); 
    display_images(game);
    game->window = mlx_new_window(game->mlxptr,
                        game->graphicpixels * game->map->width,
                        game->graphicpixels * game->map->height, "SO_LONG");
    mlx_loop_hook(game->mlxptr, display_frame, game);
    mlx_hook(game->window, KeyPress, KeyPressMask, keypress, game);
    mlx_hook(game->window, DestroyNotify, NoEventMask, xclick, game);
    mlx_loop(game->mlxptr);
    return (0);
}
