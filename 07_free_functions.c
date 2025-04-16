/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_free_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:00:41 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/17 00:38:59 by juagomez         ###   ########.fr       */
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
		return ;
	// contador tiempo antes de cierre
	game->frame_count = -25;
	while (game->frame_count < 0)
		game->frame_count++;

	if (game->mlx)
	{	
		ft_printf("closing window		...\n");
		mlx_close_window(game->mlx);
		ft_printf("closing window		OK\n");
	}			
	// LIMPIEZA JUEGO
	ft_printf("cleaning game		...\n");
	cleanup_game(game);	
	ft_printf("cleaning game:		OK\n");
}

void	cleanup_game(t_game *game)
{
	if (!game)
		return ;
	// liberacion struct map
	if (game->map)
	{
		ft_printf(" cleaning  map		...\n");
		clean_map(game->map);	
		game->map = NULL; // Evitar liberación doble
		ft_printf(" cleaning  map:		OK\n");
	}
			
	// liberacion texturas 
	ft_printf(" cleaning  images	...\n");
	clean_images(game);
	ft_printf(" cleaning  images:	OK\n");
	// mlx42 terminacion juego
	if (game->mlx)
	{
		mlx_terminate(game->mlx);	
		game->mlx = NULL; // Evitar liberación doble
	}			
	// liberacion struct game
	free(game);
	game = NULL;	// Evitar uso posterior	
}

void	clean_images(t_game *game)
{	
	if (game->img_ground)
		mlx_delete_image(game->mlx, game->img_ground);
	game->img_ground = NULL;
	if (game->img_wall)
		mlx_delete_image(game->mlx, game->img_wall);
	game->img_wall = NULL;
	if (game->img_player)
		mlx_delete_image(game->mlx, game->img_player);
	game->img_player = NULL;
	if (game->img_collect)
		mlx_delete_image(game->mlx, game->img_collect);
	game->img_collect = NULL;
	if (game->img_exit)
		mlx_delete_image(game->mlx, game->img_exit);
	game->img_exit = NULL;	
}

void	clean_map(t_map *map)
{	
	if (!map)
		return ;
	if (map->data)	
	{
		free_matrix((void **)map->data, map->height);	// liberar filas data + ptr data
		map->data = NULL; // Evitar liberación doble
	}
	
	if (map->render_flag)
	{
		free_matrix((void **)map->render_flag, map->height); // liberar filas render_flag + ptr render_flag
		map->render_flag = NULL; // Evitar liberación doble
	}	
	free(map);		
	map = NULL; // Evitar uso posterior	
}

void	free_matrix(void **matrix, int height)
{
	int row;

	if (!matrix)
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