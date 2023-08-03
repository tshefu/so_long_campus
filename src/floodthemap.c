/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodthemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:24:49 by vschneid          #+#    #+#             */
/*   Updated: 2023/08/02 20:42:04 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void fill(char **map, int y, int x)
{
    if (map[y][x] == '1' || map[y][x] == 'F')
        return ;
    map[y][x] = 'F';
    fill(map, y - 1, x);
    fill(map, y + 1, x);
    fill(map, y, x - 1);
    fill(map, y, x + 1);
}

void check_floodfill(t_game *game, char **map)
{
    int i;
    int j;
    
    j = 0;
    while (j < game->map->height)
    {
        i = 0;
        while (i < game->map->width)
        {
            if (map[j][i] == 'C' || map[j][i] == 'E')
            {
                free_flood(map);
                game_error(8, game);
            }
            i++;
        }
        j++;
    }
}

void free_flood(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void flood_fill(t_game *game)
{
    char **testmap;
    int i;

    i = 0;
    testmap = malloc(sizeof(char *) * (game->map->height + 1));
    if (!testmap)
        game_error(9, game);
    while (i < game->map->height)
    {
        testmap[i] = ft_strdup(game->map->map[i]);
        i++;
    }
    fill(testmap, game->map->plpoy, game->map->plpox);
    check_floodfill(game, testmap);
    free_flood(testmap);
}