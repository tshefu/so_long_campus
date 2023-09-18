/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:49:44 by vschneid          #+#    #+#             */
/*   Updated: 2023/08/18 11:50:21 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	opening_error(char **map, t_game *game)
{
	free(map);
	perror("Error:");
	ft_putstr_fd(KRED "Could not open file\n" KNRM, 2);
	freeing(game);
}

void	reading_error(int fd, t_game *game)
{
	close(fd);
	perror("Error:");
	ft_putstr_fd(KRED "Could not read file (read = -1)\n" KNRM, 2);
	freeing(game);
}

void	missing_map(char **map, t_game *game)
{
	free(map);
	malloc_error(6, game);
}
