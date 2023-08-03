/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:06:39 by vschneid          #+#    #+#             */
/*   Updated: 2023/07/23 13:25:11 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void game_error(int message_id, t_game *game)
{
    perror("Error");
    if (message_id == 1)
        printf("xpm files missing\n");
    if (message_id == 2)
        printf("Walls not properly connected\n");
    if (message_id == 3)
        printf("Map contains invalid characters\n");
    if (message_id == 4)
        printf("Incorrect number of players\n");
    if (message_id == 5)
        printf("Incorrect number of exits\n");
    if (message_id == 6)
        printf("Incorrect number of collectibles\n");
    if (message_id == 7)
        printf("Map is not a rectangle\n");
    if (message_id == 8)
        printf("Exits or collectibles cannot be reached\n");
    if (message_id == 9)
        printf("Malloc failed\n");
    if (message_id == 10)
        printf("No player found\n");
    if (message_id == 11)
        printf("Error opening file\n");
    if (message_id == 12)
        printf("Error reading file\n");
    if (message_id == 13)
        printf("Not enough arguments: ./so_long 'mapfile'\n");
    freeing(game);
}

void error_open(char **map, t_game *game)
{
    free(map);
    game_error(11, game);
}

void error_read(int fd, t_game *game)
{
    close(fd);
    game_error(12, game);
}

void missing_map(char **map, t_game *game)
{
    free(map);
    game_error(9, game);
}