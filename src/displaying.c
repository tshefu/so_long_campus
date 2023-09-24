/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaying.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:41:55 by vschneid          #+#    #+#             */
/*   Updated: 2023/09/24 15:14:53 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	display_image(t_game *game)
{
	int	pixels;

	game->graphic = ft_calloc(1, sizeof(t_graphic));
	if (!game->graphic)
		malloc_error(5, game);
	game->graphic->collectible = mlx_xpm_file_to_image(game->mlxptr,
			"graphics/collectible.xpm", &pixels, &pixels);
	game->graphic->floor = mlx_xpm_file_to_image(game->mlxptr,
			"graphics/floor.xpm", &pixels, &pixels);
	game->graphic->goal = mlx_xpm_file_to_image(game->mlxptr,
			"graphics/goal.xpm", &pixels, &pixels);
	game->graphic->player = mlx_xpm_file_to_image(game->mlxptr,
			"graphics/player.xpm", &pixels, &pixels);
	game->graphic->wall = mlx_xpm_file_to_image(game->mlxptr,
			"graphics/wall.xpm", &pixels, &pixels);
	game->graphic->pixels = pixels;
	if (game->graphic->collectible == NULL
		|| game->graphic->floor == NULL || game->graphic->goal == NULL
		|| game->graphic->player == NULL || game->graphic->wall == NULL)
		graphic_error(2, game);
}

int	display_frame(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			add_player(game);
			add_image(game, game->map->map[y][x], x, y);
			x++;
		}
		y ++;
	}
	return (0);
}

void	add_player(t_game *game)
{
	if (game->map->collcounter != 0
		|| game->map->map[game->map->plpoy][game->map->plpox] != 'E')
		mlx_put_image_to_window(game->mlxptr, game->window,
			game->graphic->player, game->map->plpox * game->graphic->pixels,
			game->map->plpoy * game->graphic->pixels);
	if (game->map->collcounter == 0
		&& game->map->map[game->map->plpoy][game->map->plpox] == 'E')
	{
		mlx_put_image_to_window(game->mlxptr, game->window,
			game->graphic->player, game->map->plpox * game->graphic->pixels,
			game->map->plpoy * game->graphic->pixels);
		win_game(game);
	}
}

void	win_game(t_game *game)
{
	long long int	timer;

	if (game->map->map[game->map->plpoy][game->map->plpox] == 'E'
		&& game->map->collcounter == 0)
	{
		timer = 0;
		while (timer < 50000000)
			timer++;
		ft_printf("YOU WON THE RACE! 🏆\n🏎🏎🏎  CONGRATS 🏎🏎🏎\n");
		freeing(game);
	}
}

void	add_image(t_game *game, char c, int x, int y)
{
	if (x != game->map->plpox || y != game->map->plpoy)
	{
		if (c == '0')
			mlx_put_image_to_window(game->mlxptr, game->window,
				game->graphic->floor,
				x * game->graphic->pixels, y * game->graphic->pixels);
		if (c == '1')
			mlx_put_image_to_window(game->mlxptr,
				game->window, game->graphic->wall,
				x * game->graphic->pixels, y * game->graphic->pixels);
		if (c == 'C')
			mlx_put_image_to_window(game->mlxptr, game->window,
				game->graphic->collectible,
				x * game->graphic->pixels, y * game->graphic->pixels);
		if (c == 'E')
			mlx_put_image_to_window(game->mlxptr,
				game->window, game->graphic->goal,
				x * game->graphic->pixels, y * game->graphic->pixels);
	}
}
