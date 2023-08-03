/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:05:23 by vschneid          #+#    #+#             */
/*   Updated: 2023/08/01 15:59:16 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int mapfilechecker(char *file)
{
    if (access(file, F_OK | R_OK) == -1)
        return (-1);
    else if (ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4))
        return (-1);
    else
    {
        if (access("graphics/collectible.xpm", F_OK | R_OK) == -1
        || access("graphics/floor.xpm", F_OK | R_OK) == -1
        || access("graphics/goal.xpm", F_OK | R_OK) == -1
        || access("graphics/player.xpm", F_OK | R_OK) == -1
        || access("graphics/wall.xpm", F_OK | R_OK) == -1)
        {
            game_error(1, NULL);
        }
        return (1);

    }
}
void check_rectangle(t_game *game)
{
    int i;

    i = 0;
    while (game->map->map[i] && i < game->map->height)
    {
        if (ft_strlen(game->map->map[i]) != (size_t)game->map->width)
            game_error(7, game);
        i++;
    }
}

void check_walls(t_game *game)
{
    int i;
    int j;

    j = 0;
    while (game->map->map[j])
    {
        i = 0;
        while (game->map->map[j][i])
        {
            // kann man das folgende einfacher kürzen? 
            
            if (j == 0 || j == game->map->height - 1)
            {
                if(game->map->map[j][i] != '1')
                    game_error(2, game);
            }
            if (i == 0 || i == game->map->width - 1)
            {
                if(game->map->map[j][i] != '1')
                    game_error(2, game);
            }
            i++;
        }
        j++;
    }
}

void check_characters(t_game *game)
{
    int i;
    int j;
    int k;
    
    j = 0;
    while (j < game->map->height)
    {
        i = 0;
        while (i < game->map->width)
        {
            k = 0;
            while (game->map->map[j][i] != "01CEP"[k])
            {
                if (!"01CEP"[k])
                    game_error(3, game);
                k++;
            }
            charcount("01CEP"[k], game, 0);
            i++;
        }
        j++;
    }
    charcount("01CEP"[k], game, 1);
}

void charcount(char c, t_game *game, int map_finish)
{
    if (c == 'P')
        game->map->playercounter += 1;
    if (c == 'E')
        game->map->exitcounter += 1;
    if (c == 'C')
        game->map->collcounter += 1;
    if (map_finish == 1)
    {
        if (game->map->playercounter != 1)
            game_error(4, game);
        if (game->map->exitcounter != 1)
            game_error(5, game);
        if (game->map->collcounter < 1)
            game_error(6, game);
    }
}


void check_map(t_game *game)
{
    check_rectangle(game);
    check_walls(game);
    check_characters(game);
    flood_fill(game);
}