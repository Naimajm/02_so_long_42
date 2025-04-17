/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:55:38 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/13 14:08:09 by juagomez         ###   ########.fr       */
/*                                                                            */ 
/* ************************************************************************** */

#include "./include/so_long.h"


void    ft_loop_hook(void *param);
void    close_window_handler(t_game *game);
void    key_handler(t_game *game);
void    update_player_movement(t_game *game, t_coord old_position, t_coord new_position);

// INICIO CARGA HOOK + BUCVLE JUEGO
void    start_game(t_game *game)
{
    // contador tiempo inicio
	/* game->frame_count = -25;
	while (game->frame_count < 0)
		game->frame_count++; */

    mlx_loop_hook(game->mlx, ft_loop_hook, game);
	mlx_loop(game->mlx);
}

// LOOP_HOOK
void    ft_loop_hook(void *param)
{
    t_game  *game;

    game = (t_game *)param;  // cast -> carga parametros estructura game
    if (!game)
        return;

    // contador tiempo
    /* while (game->frame_count < 5)
        game->frame_count++;
    game->frame_count = 0; */
    if (!game->loop_is_running) // verificacion si el loop del juego continua abierto
        return;

    //key_handler(game);
    //close_window_handler(game);

    // renderizar mapa
    //render_map(game);
}
// CLOSE_HANDLER
void    close_window_handler(t_game *game)
{
    if (!game || !game->mlx || !game->loop_is_running) 
        return;
    // Tecla escape para cerrar la ventana
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
    {
        mlx_close_window(game->mlx);  // ?
        game_over(game);
    }
}

// hook procesamiento inputs teclado
void    key_handler(t_game *game)
{
    t_coord old_position;
    t_coord new_position;

    if (!game || !game->map || !game->loop_is_running)
        return;
   
    old_position = game->map->player_position;
    new_position = old_position;
    // gestion teclas movimiento -> variables libreria MLX42
    if (mlx_is_key_down(game->mlx, MLX_KEY_W))
        new_position.y -= 1;
    else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
        new_position.y += 1;
    else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
        new_position.x -= 1;
    else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
        new_position.x += 1;    
    update_player_movement(game, old_position, new_position);
}

void    update_player_movement(t_game *game, t_coord old_position, t_coord new_position)
{
    if (!game)
        return ;

    // gestión movimientos -> no muro + (no salida y coleccionables no cogidos)
    if (game->map->data[new_position.y][new_position.x] != WALL && (game->map->data[new_position.y][new_position.x] == EXIT && game->exit_success == false) == 0)
    {
        // hay movimiento
        if (new_position.x != old_position.x || new_position.y != old_position.y)
        {
            // CASO USO -> RECOGER COLECCIONABLE
            if (game->map->data[new_position.y][new_position.x] == COLLECT)
            {
                // recoleccion objetos
                game->map->data[new_position.y][new_position.x] = GROUND;                
                game->map->collect_number--; // actualizar contador coleccionables en escena
                // CASO TODOS COLECCIONALBES OK -> FLAG 'EXIT_SUCCESS' = 1 -> ABRIR PUERTA
                if (game->map->collect_number == 0)
                {
                    //game->map->render_flag[new_position.y][new_position.x] = true; // renderizar
                    game->exit_success = true; // salida accesible
                }                    
            }
            // actualizar posicion player
            game->map->player_position = new_position;
            // actualizar contador movimiento
            game->move_count++;
            ft_printf("Number of movements: %d\n", game->move_count);
                     
            // actualizar flags para renderizar
            game->map->render_flag[old_position.y][old_position.x] = true;
            game->map->render_flag[new_position.y][new_position.x] = true;
            
            //ft_printf("player_position -> (%i, %i)\n", game->map->player_position.x,game->map->player_position.y);
            //ft_printf("exit_success -> %i\n", game->exit_success);
            // CASO USO SALIDA-> PLAYER en posicion EXIT_POSITION (todos coleccionables recogidos)
            if (game->map->data[new_position.y][new_position.x] == EXIT && game->exit_success)
            {           
                printf("--------- ** PLAYER WIN **--------------\n");          
                game_over(game); 
            }
        }
    }
}


