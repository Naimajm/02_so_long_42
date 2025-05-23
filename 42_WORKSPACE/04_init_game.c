/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:32:59 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/17 23:45:05 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int charge_textures(t_game *game);
t_game	*initialize_struct_game(t_game *game);

// INICIAR JUEGO
void    load_game(t_game *game, t_map *map)
{
    if (!game || !map)
        return ;

    // INICIALIZAR VARIABLES STRUCT GAME
    initialize_struct_game(game);

    // INSTANCIA MLX42 -> asignacion + validacion 
    game->mlx = mlx_init(map->width_pixels, map->height_pixels, WINDOW_TITLE, true);
    if (!game->mlx)
        return ;

    // CARGAR MAPA
    game->map = map;

    // CARGAR TEXTURAS
    charge_textures(game);
}

// ASIGNAR VARIABLES STRUCT GAME A IMG TEXTURAS (CONVERTIR TEXTURAS A IMAGENES)
int charge_textures(t_game *game)
{
	if (!game)
		return (FAILURE);

	game->texture_ground = mlx_load_png("./textures/ground.png");
    game->img_ground = mlx_texture_to_image(game->mlx, game->texture_ground);

	game->texture_wall = mlx_load_png("./textures/wall.png");
    game->img_wall = mlx_texture_to_image(game->mlx, game->texture_wall);

	game->texture_player = mlx_load_png("./textures/player.png");
    game->img_player = mlx_texture_to_image(game->mlx, game->texture_player);

	game->texture_collect = mlx_load_png("./textures/collect.png");
    game->img_collect = mlx_texture_to_image(game->mlx, game->texture_collect);

	game->texture_exit = mlx_load_png("./textures/exit.png");
    game->img_exit = mlx_texture_to_image(game->mlx, game->texture_exit);

    return (SUCCESS);
}

// INICIALIZAR VALORES STRUCTURA GAME 
t_game	*initialize_struct_game(t_game *game)
{
	if (!game)
		return (NULL);
	game->mlx = NULL;			
	game->map = NULL;		

	game->img_ground 		= NULL;
	game->img_wall 			= NULL;	
    game->img_player 	    = NULL;
	game->img_collect 		= NULL;
	game->img_exit 	        = NULL;

	game->move_count = 0;
	game->frame_count = 0;
    game->exit_success = false;
	game->loop_is_running = true; // loop juego encendido
	return (game);
}