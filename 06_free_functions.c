/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_free_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:00:41 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/16 13:18:39 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	free_images(t_game *game);
void	clean_map(t_map *map);
void	free_matrix(void **matrix, int height);

void	cleanup_game(t_game *game)
{
	if (!game)
	return ;
	// liberacion struct map
	if (game->map)
	{
		clean_map(game->map);	
		game->map = NULL; // Evitar liberación doble
	}
			
	// liberacion texturas 
	free_images(game);
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

void	free_images(t_game *game)
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
		free_matrix((void **)map->data, map->height);	// liberar filas data + ptr data
	if (map->render_flag)
		free_matrix((void **)map->render_flag, map->height); // liberar filas render_flag + ptr render_flag
	free(map);		
	//exit (FAILURE);
}

void	free_matrix(void **matrix, int height)
{
	int row;

	if (!matrix)
		return ;
	row = 0;
	while (row < height)
	{
		free(matrix[row]); // liberacion filas
		row++;
	}
	free(matrix); // liberacion ptr matrix
}