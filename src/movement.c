/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:09:55 by vschneid          #+#    #+#             */
/*   Updated: 2023/09/24 15:13:35 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

int	keypress(int key, t_game *game)
{
	int	plpox;
	int	plpoy;

	plpox = game->map->plpox;
	plpoy = game->map->plpoy;
	if ((key == W || key == UP) && game->map->map[plpoy - 1][plpox] != '1')
		game->map->plpoy--;
	if ((key == S || key == DOWN) && game->map->map[plpoy + 1][plpox] != '1')
		game->map->plpoy++;
	if ((key == A || key == LEFT) && game->map->map[plpoy][plpox - 1] != '1')
		game->map->plpox--;
	if ((key == D || key == RIGHT) && game->map->map[plpoy][plpox + 1] != '1')
		game->map->plpox++;
	if (key == ESC || key == Q)
	{
		ft_printf("------------------------------\n");
		ft_printf(KRED "🚥 🚥 GAME EXITED 🚥 🚥\n" KNRM);
		ft_printf("You didn't finish this lap 💔\n");
		ft_printf("Go for another round on a\ndifferent circuit? 🤙\n");
		ft_printf("------------------------------\n");
		freeing(game);
	}
	move_player(game, plpox, plpoy);
	return (0);
}

void	move_player(t_game *game, int x, int y)
{
	int	*moves;

	moves = ft_calloc(5, sizeof(int));
	if (!moves)
		malloc_error(4, game);
	if (game->map->map[y][x] == 'P')
		game->map->map[y][x] = '0';
	if (game->map->map[y][x] == 'C')
	{
		game->map->map[y][x] = '0';
		game->map->collcounter--;
	}
	if (x != game->map->plpox || y != game->map->plpoy)
	{
		ft_printf(KGRN "⏲ ⏲ YOUR CURRENT LAP TIME ⏲ ⏲\n");
		ft_printf(KNRM "------------------------------\n");
		ft_printf(KBLU "%d SECONDS\n\n" KNRM, game->map->moves++);
	}
	free(moves);
}

int	xklick(t_game *game)
{
	ft_printf("------------------------------\n");
	ft_printf(KRED "🚥 🚥 GAME EXITED 🚥 🚥\n" KNRM);
	ft_printf("You didn't finish this lap 💔\n");
	ft_printf("Go for another round on a\ndifferent circuit? 🤙\n");
	ft_printf("------------------------------\n");
	freeing(game);
	return (0);
}
