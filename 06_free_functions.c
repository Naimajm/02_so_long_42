/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_free_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:00:41 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/15 23:14:24 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	free_textures(t_game *game);
void	clean_map(t_map *map);
void	free_matrix(void **matrix, int height);

void	cleanup_game(t_game *game)
{
	if (!game)
	return ;
	// liberacion struct map
	if (game->map)
		clean_map(game->map);		
	// liberacion texturas 
	free_textures(game);
	// mlx42 terminacion juego
	mlx_terminate(game->mlx);		
	// liberacion struct game
	free(game);
}

void	free_textures(t_game *game)
{
	if (game->img_ground)
		mlx_delete_image(game->mlx, game->img_ground);
	if (game->img_wall)
		mlx_delete_image(game->mlx, game->img_wall);
	if (game->img_player)
		mlx_delete_image(game->mlx, game->img_player);
	if (game->img_collect)
		mlx_delete_image(game->mlx, game->img_collect);
	if (game->img_exit)
		mlx_delete_image(game->mlx, game->img_exit);
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