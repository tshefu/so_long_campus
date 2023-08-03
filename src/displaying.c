/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaying.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:33:50 by vschneid          #+#    #+#             */
/*   Updated: 2023/07/31 21:50:06 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void display_images(t_game *game)
{
    int pixels;

    game->graphic = malloc(sizeof(t_graphic));
    if (!game->graphic)
        // error message
    game->graphic->wall = mlx_xpm_file_to_image(game->mlxptr,
            "graphics/wall.xpm", &pixels, &pixels);
    game->graphic->collectible = mlx_xpm_file_to_image(game->mlxptr,
            "graphics/collectible.xpm", &pixels, &pixels);
    game->graphic->floor = mlx_xpm_file_to_image(game->mlxptr,
            "graphics/floor.xpm", &pixels, &pixels);
    game->graphic->player = mlx_xpm_file_to_image(game->mlxptr,
            "graphics/player.xpm", &pixels, &pixels);
    game->graphic->goal = mlx_xpm_file_to_image(game->mlxptr,
            "graphics/goal.xpm", &pixels, &pixels);
    if (game->graphic->wall == NULL || game->graphic->collectible == NULL
            || game->graphic->floor == NULL || game->graphic->player == NULL
            || game->graphic->goal == NULL)
            // error message
    game->graphicpixels = pixels;
}
int display_frame(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            add_image(game, game->map->map[y][x], x, y);
            x++;
        }
        y++;
    }
    return (0);
}
void add_image(t_game *game, char c, int x, int y)
{
    add_player(game);
    if (x != game->map->plpox || y != game->map->plpoy)
    {
        if (c == '0')
            mlx_put_image_to_window(game->mlxptr, game->window,
                game->graphic->floor, x * game->graphicpixels,
                y * game->graphicpixels);
        if (c == '1')
            mlx_put_image_to_window(game->mlxptr, game->window,
                game->graphic->wall, x * game->graphicpixels,
                y * game->graphicpixels);
        if (c == 'C')
            mlx_put_image_to_window(game->mlxptr, game->window,
                game->graphic->collectible, x * game->graphicpixels,
                y * game->graphicpixels);
        if (c == 'E')
            mlx_put_image_to_window(game->mlxptr, game->window,
                game->graphic->goal, x * game->graphicpixels,
                y * game->graphicpixels);
    }
    // add_moves(game);
}

//braucht es folgende Funktion überhaupt oder ist das Bonus? 

/*void add_moves(t_game *game)
{
    char *temp;
    char *temptwo;

    temptwo = ft_itoa(game->moves - 1);
    temp = ft_strjoin("Number of moves: ", temptwo);
    mlx_string_put(game->mlxptr, game->window, 2, 10, 0xccccff, temp);
    free(temp);
    free(temptwo); 
}*/

void add_player(t_game *game)
{
    if (game->map->map[game->map->plpoy][game->map->plpox] == 'E'
        && game->map->collcounter == 0)
    {
        if (game->victor > 5000000)
        {
            printf("You won! :)\n");
            freeing(game);
        }
        game->victor++;
    }
    else
        mlx_put_image_to_window(game->mlxptr, game->window, game->graphic->player,
            game->map->plpox * game->graphicpixels, game->map->plpoy * game->graphicpixels);
}
