/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:44:32 by vschneid          #+#    #+#             */
/*   Updated: 2023/08/03 17:05:21 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <fcntl.h>
# include <errno.h>
# include <X11/X.h>
# include "../libft/libft.h"

// key presses // 
# ifdef __linux__
#  define W 119
#  define S 115
#  define A 97
#  define D 100
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363
#  define ESC 65307
# endif

typedef struct s_map
{
    char **map;
    int width;
    int height;
    int playercounter;
    int exitcounter;
    int collcounter;
    int plpox;
    int plpoy;
} t_map;

typedef struct s_graphic
{
    void *player;
    void *collectible;
    void *floor;
    void *wall;
    void *goal;  
} t_graphic;

typedef struct s_game
{
    void *window;
    void *mlxptr;
    int moves;
    int victor;
    int graphicpixels;
    t_map *map;
    t_graphic *graphic;
}   t_game;

void display_images(t_game *game);
int display_frame(t_game *game);
void add_image(t_game *game, char c, int x, int y);
/* void add_moves(t_game *game); */
void add_player(t_game *game);

void game_error(int message_id, t_game *game);
void error_open(char **map, t_game *game);
void error_read(int fd, t_game *game);
void missing_map(char **map, t_game *game);

void fill(char **map, int y, int x);
void check_floodfill(t_game *game, char **map);
void free_flood(char **map);
void flood_fill(t_game *game);

void freeing(t_game *game);
void free_mlx(t_game *game);

t_game *initialise_struct(char *file);
void initialise_map(char *file, t_game *game);
int number_of_lines(char *file, t_game *game);
char **remove_newline(char **map);
int empty_file(char *file, t_game *game);

int mapfilechecker(char *file);
void check_rectangle(t_game *game);
void check_walls(t_game *game);
void check_characters(t_game *game);
void charcount(char c, t_game *game, int map_finish);
void check_map(t_game *game);

int keypress(int key, t_game *game);
int xclick(t_game *game);
void player_pos(t_game *game);
void move_player(t_game *game, int x, int y);

/*char *ft_itoa(int n);
char *ft_strjoin(char *s1, char *s2);
char *ft_strdup(const char *s1);*/

#endif