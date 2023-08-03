/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:37:04 by vschneid          #+#    #+#             */
/*   Updated: 2023/08/03 15:45:50 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*vs_buff_to_pot(int fd, char *pot_str)
{
	char	*buff;
	int		bytes_read;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(pot_str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			free(pot_str);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		pot_str = ft_strjoin(pot_str, buff);
		if (ft_strchr(pot_str, '\n'))
			break;
	}
	free (buff);
	return (pot_str);
}

char	*vs_check_line(char *pot_str)
{
	int		i;
	char	*final_line;

	i = 0;
	if (!pot_str[i])
		return (NULL);
	final_line = (char *)malloc(sizeof(char) * (ft_strlen(pot_str) + 2));
	if (!final_line)
		return (NULL);
	while (pot_str[i] && pot_str[i] != '\n')
	{
		final_line[i] = pot_str[i];
		i++;
	}
	if (pot_str[i] == '\n')
	{
		final_line[i] = pot_str[i];
		i++;
	}
	final_line[i] = '\0';
	return (final_line);
}

char	*vs_fresh_pot(char *old_pot)
{
	int		i;
	int		j;
	char	*new_pot;

	i = 0;
	while (old_pot[i] && old_pot[i] != '\n')
		i++;
	if (!old_pot[i])
	{
		free(old_pot);
		return (NULL);
	}
	new_pot = (char *)malloc(sizeof(char) * (ft_strlen(old_pot) -i + 1));
	if (!new_pot)
		return (NULL);
	i++;
	j = 0;
	while (old_pot[i])
		new_pot[j++] = old_pot[i++];
	new_pot[j] = '\0';
	free(old_pot);
	return (new_pot);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*pot[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	pot[fd] = vs_buff_to_pot(fd, pot[fd]);
	if (!pot[fd])
		return (NULL);
	line = vs_check_line(pot[fd]);
	pot[fd] = vs_fresh_pot(pot[fd]);
	return (line);
}