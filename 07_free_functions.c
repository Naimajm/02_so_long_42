/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_free_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:00:41 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/17 22:35:20 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	cleanup_game(t_game *game);
void	clean_images(t_game *game);
void	clean_map(t_map *map);
void	free_matrix(void **matrix, int height);

void	game_over(t_game *game)
{
	ft_printf("------------- GAME OVER -------------\n");	
	if (!game)
		return; 

	// Detener el bucle principal
    game->loop_is_running = false;
	
	// contador tiempo antes de cierre
	/* game->frame_count = -25;
	while (game->frame_count < 0)
		game->frame_count++; */
	//mlx_close_window(game->mlx); 

	if (game->mlx)
	{			
		ft_printf("closing window		...\n");
        mlx_close_window(game->mlx);
		
        // liberar mapa
        if (game->map)
        {
            ft_printf(" cleaning  map		...\n");
            clean_map(game->map);
            game->map = NULL;
            ft_printf(" cleaning  map:		OK\n");
        }
		// liberar imágenes/texturas
        ft_printf(" cleaning  images	...\n");
        clean_images(game);
        ft_printf(" cleaning  images:	OK\n");

        mlx_terminate(game->mlx); // destruir GLFW/GLAD

		// **liberar el struct de MLX que allocaste en mlx_init**
		//free(game->mlx);
        //game->mlx = NULL;
        ft_printf("closing window		OK\n");
	}			
	// LIMPIEZA recursos -> game, game->map	
	free(game);	
}

void	cleanup_game(t_game *game)
{
	// ya no hace free(game);
    if (!game)
        return ;
    // solo limpiar mapa e imágenes si se usa en otro contexto
    if (game->map)
        clean_map(game->map);
    clean_images(game);
		
}

void	clean_images(t_game *game)
{	
	if (game->img_ground)
    {
        mlx_delete_image(game->mlx, game->img_ground);
        game->img_ground = NULL;
    }
    if (game->texture_ground)
    {
        mlx_delete_texture(game->texture_ground);
        game->texture_ground = NULL;
    }

    if (game->img_wall)
    {
        mlx_delete_image(game->mlx, game->img_wall);
        game->img_wall = NULL;
    }
    if (game->texture_wall)
    {
        mlx_delete_texture(game->texture_wall);
        game->texture_wall = NULL;
    }

    if (game->img_player)
    {
        mlx_delete_image(game->mlx, game->img_player);
        game->img_player = NULL;
    }
    if (game->texture_player)
    {
        mlx_delete_texture(game->texture_player);
        game->texture_player = NULL;
    }

    if (game->img_collect)
    {
        mlx_delete_image(game->mlx, game->img_collect);
        game->img_collect = NULL;
    }
    if (game->texture_collect)
    {
        mlx_delete_texture(game->texture_collect);
        game->texture_collect = NULL;
    }

    if (game->img_exit)
    {
        mlx_delete_image(game->mlx, game->img_exit);
        game->img_exit = NULL;
    }
    if (game->texture_exit)
    {
        mlx_delete_texture(game->texture_exit);
        game->texture_exit = NULL;
    }	
}

void	clean_map(t_map *map)
{	
	if (!map)
		return ;
	if (map->data && map->height > 0)	
	{
		free_matrix((void **)map->data, map->height);	// liberar filas data + ptr data
		map->data = NULL; // Evitar liberación doble
	}
	
	if (map->render_flag && map->height > 0)
	{
		free_matrix((void **)map->render_flag, map->height); // liberar filas render_flag + ptr render_flag
		map->render_flag = NULL; // Evitar liberación doble
	}	
	free(map);
}

void	free_matrix(void **matrix, int height)
{
	int row;

	if (!matrix || height <= 0)
		return ;
	row = 0;
	while (row < height)
	{
		if (matrix[row])
		{
			free(matrix[row]); 	// liberacion filas
			matrix[row] = NULL; // Evitar liberación doble
		}		 
		row++;
	}
	free(matrix); 	// liberacion ptr matrix
	matrix = NULL; 	// Evitar uso posterior
}