/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:07:45 by vschneid          #+#    #+#             */
/*   Updated: 2023/09/24 16:28:21 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	gnl_check(char **map, int i, t_game *game)
{
	if (!map[i])
	{
		i = 0;
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
		map_error(9, game);
	}
}

char	**remove_newline(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == '\n')
				map[j][i] = '\0';
			i++;
		}
		j++;
	}
	return (map);
}

void	add_map_values_map(t_game *game, char **map, int i)
{
	game->map->map = map;
	game->map->height = i;
	game->map->width = ft_strlen(map[0]);
}

void	initialise_map(char *file, t_game *game)
{
	char	**map;
	int		i;
	int		fd;
	int		lines;

	lines = game->map->lines;
	map = ft_calloc(1, sizeof(char *) * (lines + 1));
	if (!map)
		missing_map(map, game);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		opening_error(map, game);
	i = 0;
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		gnl_check(map, i, game);
		i++;
	}
	free(get_next_line(fd));
	map = remove_newline(map);
	add_map_values_map(game, map, i);
	check_valid_map(game);
	close(fd);
}

int	count_lines(char *file, t_game *game)
{
	int		fd;
	int		line_count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		map_error(8, game);
	line_count = 0;
	line = get_next_line(fd);
	if (line)
		line_count = 1;
	while (line != NULL)
	{
		if (line_count == 1)
			free(line);
		line = get_next_line(fd);
		if (line)
			line_count++;
		free(line);
	}
	if (line_count == 0)
		map_error(8, game);
	close(fd);
	return (line_count);
}