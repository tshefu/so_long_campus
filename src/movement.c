/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:04:09 by vschneid          #+#    #+#             */
/*   Updated: 2023/07/31 21:47:47 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int keypress(int key, t_game *game)
{
    int plpox;
    int plpoy;

    plpox = game->map->plpox;
    plpoy = game->map->plpoy;
    if (key == ESC)
    // free game
    if ((key == W || key == UP) && game->map->map[plpoy - 1][plpox] != 1)
        game->map->plpoy -= 1;
    if ((key == S || key == DOWN) && game->map->map[plpoy + 1][plpox] != 1)
        game->map->plpoy += 1;
    if ((key == A || key == LEFT) && game->map->map[plpoy][plpox - 1] != 1)
        game->map->plpox -= 1;
    if ((key == D || key == RIGHT) && game->map->map[plpoy][plpox + 1] != 1)
        game->map->plpox += 1;
    move_player(game, plpox, plpoy);
    return (0);
}

int xclick(t_game *game)
{
    freeing(game);
    return (0);
}

void player_pos(t_game *game)
{
    int i;
    int j;

    j = 0;
    while (game->map->map[j])
    {
        i = 0;
        while (game->map->map[j][i])
        {
            if (game->map->map[j][i] == 'P')
            {
                game->map->plpox = i;
                game->map->plpoy = j;
                return ;                
            }
            i++;
        }
        j++;
    }
    game_error(10, game);
}

void move_player(t_game *game, int x, int y)
{
    int *moves;
    moves = malloc(sizeof(int) * 5);
    if (!moves)
        game_error(9, game);
    if (x != game->map->plpox || y != game->map->plpoy)
        printf("Moves: %d\n", game->moves++);
    if (game->map->map[y][x] == 'P')
    {
        game->map->map[y][x] = '0';
    }
    if (game->map->map[y][x] == 'C')
    {
        game->map->map[y][x] = '0';
        game->map->collcounter -= 1;
    }
}
