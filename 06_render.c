/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:06:41 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/17 13:25:26 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void    render_tile(t_game *game, int position_y, int position_x);

void    render_map(t_game *game)
{
    if (!game || !game->map || !game->mlx)
        return ;

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
    if (game->img_player)
        mlx_image_to_window(game->mlx, game->img_player, game->map->player_position.x * TILE_SIZE, game->map->player_position.y * TILE_SIZE);
}

void    render_tile(t_game *game, int position_y, int position_x)
{
    char tile_type; 
    mlx_image_t  *tmp_img;    

    if (!game || !game->map || !game->mlx)
        return;
    tmp_img = NULL;
    tile_type = game->map->data[position_y][position_x];
        
    if (tile_type == WALL)
        tmp_img = game->img_wall;
    else if (tile_type == COLLECT)
        tmp_img = game->img_collect;
    else if (tile_type == EXIT)
        tmp_img = game->img_exit;  
    else 
        tmp_img = game->img_ground;  // RENDERIZAR SUELO -> limpia renderizados anteriores (player, enemy, collect recogido)
    // RENDERIZAR CELDA SEGUN elemento 
    if (tmp_img)
        mlx_image_to_window(game->mlx, tmp_img, position_x * TILE_SIZE, position_y * TILE_SIZE);
}

