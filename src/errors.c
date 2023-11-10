/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:46:24 by vschneid          #+#    #+#             */
/*   Updated: 2023/09/26 15:05:55 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	graphic_error(t_game *game)
{
	perror("Error");
	ft_putstr_fd(KRED "Rendering images failed\n" KNRM, 2);
	freeing(game);
}

void	map_error(int id, t_game *game, int fd)
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
		ft_putstr_fd(KRED "Empty file or couldn't read file\n" KNRM, 2);
	if (id == 9)
		ft_putstr_fd(KRED "No map generated\n" KNRM, 2);
	close(fd);
	freeing(game);
}

void	malloc_error_fd(t_game *game, int fd)
{
	perror("Error");
	ft_putstr_fd(KRED "Malloc failed (flood fill)\n" KNRM, 2);
	close(fd);
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
