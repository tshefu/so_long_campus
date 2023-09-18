/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:46:24 by vschneid          #+#    #+#             */
/*   Updated: 2023/09/18 15:34:23 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	graphic_error(int id, t_game *game)
{
	perror("Error");
	if (id == 1)
		ft_putstr_fd("Graphic missing or no access\n", 2);
	if (id == 2)
		ft_putstr_fd("Rendering images failed\n", 2);
	freeing(game);
}

void	map_error(int id, t_game *game)
{
	perror("Error");
	if (id == 1)
		ft_putstr_fd(KRED "Map not fully surrounded by walls\n" KNRM, 2);
	if (id == 2)
		ft_putstr_fd(KRED "Forbidden character! Use 01CEP\n" KNRM, 2);
	if (id == 3)
		ft_putstr_fd(KRED "Wrong number of players\n" KNRM, 2);
	if (id == 4)
		ft_putstr_fd(KRED "Wrong number of exits\n" KNRM, 2);
	if (id == 5)
		ft_putstr_fd(KRED "Wrong number of collectibles\n" KNRM, 2);
	if (id == 6)
		ft_putstr_fd(KRED "Lines not of the same length\n" KNRM, 2);
	if (id == 7)
		ft_putstr_fd(KRED "Exits or coins can't be reached\n" KNRM, 2);
	if (id == 8)
		ft_putstr_fd(KRED "Empty file or no permission\n" KNRM, 2);
	if (id == 9)
		ft_putstr_fd(KRED "No map generated\n" KNRM, 2);
	freeing(game);
}

void	malloc_error(int id, t_game *game)
{
	perror("Error");
	if (id == 1)
		ft_putstr_fd(KRED "Malloc failed (flood fill)\n" KNRM, 2);
	if (id == 2)
		ft_putstr_fd(KRED "Malloc failed (get_next_line)\n" KNRM, 2);
	if (id == 3)
		ft_putstr_fd(KRED "Malloc failed (game initialising)\n" KNRM, 2);
	if (id == 4)
		ft_putstr_fd(KRED "Malloc failed (moves of player)\n" KNRM, 2);
	if (id == 5)
		ft_putstr_fd(KRED "Malloc failed (rendering image)\n" KNRM, 2);
	if (id == 6)
		ft_putstr_fd(KRED "Malloc failed (no map)\n" KNRM, 2);
	freeing(game);
}

void	startup_error(int id, t_game *game)
{
	perror("Error:");
	if (id == 1)
		ft_putstr_fd(KRED "Wrong input! ./so_long maps/mapname.ber\n" KNRM, 2);
	if (id == 2)
		ft_putstr_fd(KRED "Cannot access file\n" KNRM, 2);
	freeing(game);
}

void	mlx_error(t_game *game)
{
	perror("Error:");
	ft_putstr_fd(KRED "Failed initialising MLX\n" KNRM, 2);
	freeing(game);
}
