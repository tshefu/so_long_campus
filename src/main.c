/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:12:06 by vschneid          #+#    #+#             */
/*   Updated: 2023/10/03 16:36:20 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	add_map_values_struct(t_game *game, char *file)
{
	game->map->playercounter = 0;
	game->map->exitcounter = 0;
	game->map->collcounter = 0;
	game->map->moves = 1;
	game->map->lines = count_lines(file, game);
}

t_game	*initialise_struct(char *file)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		malloc_error(1, game);
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map)
		malloc_error(1, game);
	add_map_values_struct(game, file);
	initialise_map(file, game);
	return (game);
}

int	main(int argc, char **argv)
{
	t_game		*game;

	if (argc != 2 || (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4)))
		startup_error(1, NULL);
	game = initialise_struct(argv[1]);
	game->mlxptr = mlx_init();
	if (!game->mlxptr)
		mlx_error(NULL);
	display_image(game);
	access_check_images(game);
	game->window = mlx_new_window(game->mlxptr,
			(game->graphic->pixels * game->map->width),
			(game->graphic->pixels * game->map->height), "RAWE CEEK");
	mlx_loop_hook(game->mlxptr, display_frame, game);
	mlx_hook(game->window, KeyPress, KeyPressMask, keypress, game);
	mlx_hook(game->window, DestroyNotify, NoEventMask, xklick, game);
	mlx_loop(game->mlxptr);
	return (0);
}
