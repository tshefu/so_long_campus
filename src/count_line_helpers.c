/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_line_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:27:50 by vschneid          #+#    #+#             */
/*   Updated: 2023/09/30 12:27:45 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	fd_check(int fd, t_game *game)
{
	if (fd < 0)
		map_error(8, game, fd);
}

void	line_check(char *line, unsigned char bool, t_game *game, int fd)
{
	if (!line && bool)
		map_error(9, game, fd);
}

void	line_zero_check(int line_count, t_game *game, int fd)
{
	if (line_count == 0)
		map_error(8, game, fd);
}
