/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialising.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:30:27 by vschneid          #+#    #+#             */
/*   Updated: 2023/08/02 21:02:52 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game *initialise_struct(char *file)
{
    t_game *game;

    game = malloc(sizeof (t_game));
    if (!game)
        game_error(9, game); 
    game->map = malloc(sizeof(t_map));
    if (!game->map)
        game_error(9, game);
    game->victor = 0;
    game->moves = 1;
    game->map->playercounter = 0;
    game->map->exitcounter = 0;
    game->map->collcounter = 0;
    initialise_map(file, game);
    check_map(game);
    return (game);
}

void initialise_map(char *file, t_game *game)
{
    char **map;
    int i;
    int fd;
    int lines;

    i = 0;
    lines = empty_file(file, game);
    map = malloc(sizeof(char *) * (lines + 1));
    if (!map)
        missing_map(map, game);
    fd = open(file, O_RDONLY);
    if (fd == -1)
        error_open(map, game); 
    while (i < lines)
    {
        map[i] = get_next_line(fd);
        i++;
    }
    free(get_next_line(fd));
    map = remove_newline(map);
    game->map->map = map;
    game->map->height = i;
    game->map->width = ft_strlen(map[0]);
    close (fd);
}

int number_of_lines(char *file, t_game *game)
{
    int fd;
    int bytes;
    int lines;
    char buffer;
    char old_buffer;

    lines = 0;
    fd = open(file, O_RDONLY);
    if (fd < 0)
        game_error(11, game);
    bytes = 1;
    old_buffer = '\0';
    while (bytes)
    {
        bytes = read(fd, &buffer, 1);
        if (old_buffer == buffer && buffer == '\n')
            return (lines);
        if (bytes == -1)
            error_read(fd, game);
        if (buffer == '\n')
            lines++;
        old_buffer = buffer;
    }
    close(fd);
    return (lines + 1);
}

char **remove_newline(char **map)
{
    int i;
    int j;

    j = 0;
    while (map[j])
    {
        i = 0;
        while (map[j][i] != '\0')
        {
            if (map[j][i] == '\n')
                map[j][i] = '\0';
            i++;
        }
        j++;
    }
    return (map);
}

int empty_file(char *file, t_game *game)
{
    int fd;
    char buffer;
    int lines;

    fd = open(file, O_RDONLY);
    if (read(fd, &buffer, 1) == 0)
        game_error(12, game);
    lines = number_of_lines(file, game);
    return (lines);
}