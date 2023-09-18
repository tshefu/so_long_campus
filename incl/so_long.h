/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:23:13 by vschneid          #+#    #+#             */
/*   Updated: 2023/09/18 17:21:18 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <fcntl.h>
# include <errno.h>
# include <X11/X.h>

// KEY PRESSES //

# ifdef __linux__
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363
#  define W 119
#  define S 115
#  define A 97
#  define D 100
#  define ESC 65307
#  define Q 113
# endif

// COLORS //

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		lines;
	int		playercounter;
	int		exitcounter;
	int		collcounter;
	int		plpox;
	int		plpoy;
}	t_map;

typedef struct s_graphic
{
	void	*player;
	void	*collectible;
	void	*floor;
	void	*wall;
	void	*goal;
}	t_graphic;

typedef struct s_game
{
	void		*window;
	void		*mlxptr;
	int			moves;
	int			graphicpixels;
	t_map		*map;
	t_graphic	*graphic;
}	t_game;

// DISPLAYING

void	display_image(t_game *game);
int		display_frame(t_game *game);
void	add_player(t_game *game);
void	win_game(t_game *game);
void	add_image(t_game *game, char c, int x, int y);

// ERRORS

void	graphic_error(int id, t_game *game);
void	map_error(int id, t_game *game);
void	malloc_error(int id, t_game *game);
void	startup_error(int id, t_game *game);
void	mlx_error(t_game *game);

// MORE ERRORS

void	opening_error(char **map, t_game *game);
void	reading_error(int fd, t_game *game);
void	missing_map(char **map, t_game *game);

// FLOOD FILL

void	fill(char **map, int y, int x);
void	check_floodfill(t_game *game, char **map);
void	flood_fill(t_game *game);

// FREEING

void	freeing(t_game *game);
void	free_graphic(t_game *game);
void	free_mlxptr(t_game *game);

// INITIALISE MAP

void	add_map_values_map(t_game *game, char **map, int i);
void	initialise_map(char *file, t_game *game);
int		count_lines(char *file, t_game *game);
char	**remove_newline(char **map);

// MAIN

void	add_map_values_struct(t_game *game, char *file);
t_game	*initialise_struct(char *file);
int		main(int argc, char **argv);

// MAP CHECKERS

void	check_valid_map(t_game *game);
void	check_rectangle(t_game *game);
void	check_full_walls(t_game *game);

// PLAYER CHECKERS

void	check_valid_characters(t_game *game);
void	check_characters(t_game *game);
void	count_characters(char c, t_game *game);
void	find_player(t_game *game);

// MORE CHECKERS

void	access_check_ber(char *ber_file);
void	access_check_xpm(void);
void	gnl_check(char **map, int i, t_game *game);

// MOVEMENT

int		keypress(int key, t_game *game);
void	move_player(t_game *game, int x, int y);
int		xklick(t_game *game);

#endif
