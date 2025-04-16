/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:06:41 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/16 20:20:07 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void    render_tile(t_game *game, int position_y, int position_x);

void    render_map(t_game *game)
{
    int position_y;
    int position_x;

    position_y = 0;
    while (position_y < game->map->height)
    {
        position_x = 0;
        while (position_x < game->map->width)
        {
            if (game->map->render_flag[position_y][position_x] == true)
            {
                // renderizar celda
                render_tile(game, position_y, position_x);
                // actualizar estado 'renderizado' = false
                game->map->render_flag[position_y][position_x] = false;
            }
            position_x++;
        }
        position_y++;
    }      
    // renderizar player en posicion
    mlx_image_to_window(game->mlx, game->img_player, game->map->player_position.x * TILE_SIZE, game->map->player_position.y * TILE_SIZE);
}

void    render_tile(t_game *game, int position_y, int position_x)
{
    mlx_image_t  *tmp_img;    
    if (game->map->data[position_y][position_x] == WALL)
        tmp_img = game->img_wall;
    else if (game->map->data[position_y][position_x] == COLLECT)
        tmp_img = game->img_collect;
    else if (game->map->data[position_y][position_x] == EXIT)
        tmp_img = game->img_exit;  
    else   
        tmp_img = game->img_ground;  // RENDERIZAR SUELO -> limpia renderizados anteriores (player, enemy, collect recogido)
    // RENDERIZAR CELDA SEGUN elemento 
    mlx_image_to_window(game->mlx, tmp_img, position_x * TILE_SIZE, position_y * TILE_SIZE);
}

