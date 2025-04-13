/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:32:59 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/13 14:08:11 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int charge_textures(t_game *game);
t_game	*initialize_struct_game(t_game *game);

// INICIAR JUEGO
void    load_game(t_game *game, t_map *map)
{
    // INICIALIZAR VARIABLES STRUCT GAME
    initialize_struct_game(game);

    // INSTANCIA MLX42 -> asignacion + validacion 
    game->mlx = mlx_init(map->width_pixels, map->height_pixels, WINDOW_TITLE, true);
    if (!game->mlx)
    {
        // cleanup(game);
        return ;
    }
    // CARGAR MAPA
    game->map = map;
    // CARGAR TEXTURAS
    charge_textures(game);    
}
// ASIGNAR VARIABLES STRUCT GAME A IMG TEXTURAS
int charge_textures(t_game *game)
{
    game->img_ground = mlx_texture_to_image(game->mlx, mlx_load_png("./textures/ground.png"));
    game->img_wall = mlx_texture_to_image(game->mlx, mlx_load_png("./textures/wall_1.png"));

    game->img_player_down = mlx_texture_to_image(game->mlx, mlx_load_png("./textures/player.png"));
    game->img_player_up = mlx_texture_to_image(game->mlx, mlx_load_png("./textures/player_up.png"));
    game->img_player_left = mlx_texture_to_image(game->mlx, mlx_load_png("./textures/player_left.png"));
    game->img_player_right = mlx_texture_to_image(game->mlx, mlx_load_png("./textures/player_right.png"));

    game->img_collect = mlx_texture_to_image(game->mlx, mlx_load_png("./textures/collect_1.png"));
    game->img_exit_open = mlx_texture_to_image(game->mlx, mlx_load_png("./textures/exit_open.png"));
    game->img_exit_closed = mlx_texture_to_image(game->mlx, mlx_load_png("./textures/exit_closed.png"));
    return (SUCCESS);
}

// INICIALIZAR VALORES STRUCTURA GAME 
t_game	*initialize_struct_game(t_game *game)
{
	game->mlx = NULL;			
	game->map = NULL;		

	game->img_ground 		= NULL;
	game->img_wall 			= NULL;	

    game->img_player_down 	= NULL;
	game->img_player_up 	= NULL;	
	game->img_player_left 	= NULL;	
	game->img_player_right	= NULL;	
	
	/* game->img_enemy_up 		= NULL;	
	game->img_enemy_down 	= NULL;	
	game->img_enemy_left 	= NULL;	
	game->img_enemy_right	= NULL;	 */

	game->img_collect 		= NULL;
	game->img_exit_open 	= NULL;
	game->img_exit_closed 	= NULL;

	game->move_count = 0;
	//game->wmoves = NULL;
	game->frame_count = 0;
	return (game);
}