/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_free_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:00:41 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/18 19:03:51 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	cleanup_game(t_game *game);
void	clean_images(t_game *game);
void	clean_map(t_map *map);
void	free_matrix(void **matrix, int height);

void	game_over(t_game *game)
{
	if (!game)
		return ;
	game->loop_is_running = false;
	game->frame_count = -100;
	while (game->frame_count < 0)
		game->frame_count++;
	if (game->mlx)
	{
		mlx_close_window(game->mlx);
		cleanup_game(game);
		mlx_terminate(game->mlx);
	}
	free(game);
}

void	cleanup_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		clean_map(game->map);
	clean_images(game);
}

void	clean_images(t_game *game)
{
	if (game->texture_ground)
		mlx_delete_texture(game->texture_ground);
	if (game->texture_wall)
		mlx_delete_texture(game->texture_wall);
	if (game->texture_player)
		mlx_delete_texture(game->texture_player);
	if (game->texture_collect)
		mlx_delete_texture(game->texture_collect);
	if (game->texture_exit)
		mlx_delete_texture(game->texture_exit);
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
	{
		free_matrix((void **) map->data, map->height);
		map->data = NULL;
	}
	if (map->render_flag)
	{
		free_matrix((void **) map->render_flag, map->height);
		map->render_flag = NULL;
	}
	free(map);
}

void	free_matrix(void **matrix, int height)
{
	int	row;

	if (!matrix || height <= 0)
		return ;
	row = 0;
	while (row < height)
	{
		if (matrix[row])
		{
			free(matrix[row]);
			matrix[row] = NULL;
		}
		row++;
	}
	free(matrix);
	matrix = NULL;
}
