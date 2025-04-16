/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:32:59 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/16 23:12:38 by juagomez         ###   ########.fr       */
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
    {
        cleanup_game(game);
        return ;
    }
    // CARGAR MAPA
    game->map = map;
    // CARGAR TEXTURAS
    charge_textures(game);    
	//printf("load game:		OK");
}
// ASIGNAR VARIABLES STRUCT GAME A IMG TEXTURAS (CONVERTIR TEXTURAS A IMAGENES)
int charge_textures(t_game *game)
{
	//mlx_texture_t	*texture_tmp;
	if (!game)
		return (FAILURE);
	/* texture_tmp = mlx_load_png("./textures/ground.png");
    game->img_ground = mlx_texture_to_image(game->mlx, texture_tmp);
	mlx_delete_texture(texture_tmp); // liberar texturas

	texture_tmp = mlx_load_png("./textures/wall.png");
    game->img_wall = mlx_texture_to_image(game->mlx, texture_tmp);
	mlx_delete_texture(texture_tmp);

	texture_tmp = mlx_load_png("./textures/player.png");
    game->img_player = mlx_texture_to_image(game->mlx, texture_tmp);
	mlx_delete_texture(texture_tmp);

	texture_tmp = mlx_load_png("./textures/collect.png");
    game->img_collect = mlx_texture_to_image(game->mlx, texture_tmp);
	mlx_delete_texture(texture_tmp);

	texture_tmp = mlx_load_png("./textures/exit.png");
    game->img_exit = mlx_texture_to_image(game->mlx, texture_tmp);
	mlx_delete_texture(texture_tmp); */
	

	game->img_ground = mlx_texture_to_image(game->mlx, mlx_load_png("./textures/ground.png"));
	game->img_wall = mlx_texture_to_image(game->mlx, mlx_load_png("./textures/wall.png"));
	game->img_player = mlx_texture_to_image(game->mlx, mlx_load_png("./textures/player.png"));
	game->img_collect = mlx_texture_to_image(game->mlx, mlx_load_png("./textures/collect.png"));
	game->img_exit = mlx_texture_to_image(game->mlx, mlx_load_png("./textures/exit.png"));
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
	return (game);
}