/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:06:41 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/18 21:58:29 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	render_tile(t_game *game, int position_y, int position_x);

void	render_map(t_game *game)
{
	int	row;
	int	column;

	if (!game || !game->map || !game->mlx)
		return ;
	row = 0;
	while (row < game->map->height)
	{
		column = 0;
		while (column < game->map->width)
		{
			if (game->map->render_flag[row][column] == true)
			{
				render_tile(game, row, column);
				game->map->render_flag[row][column] = false;
			}
			column++;
		}
		row++;
	}
	if (game->img_player)
		mlx_image_to_window(game->mlx, game->img_player,
			game->map->player_position.x * TILE_SIZE,
			game->map->player_position.y * TILE_SIZE);
}

void	render_tile(t_game *game, int position_y, int position_x)
{
	char		tile_type;
	mlx_image_t	*tmp_img;

	tile_type = game->map->data[position_y][position_x];
	if (tile_type == WALL)
		tmp_img = game->img_wall;
	else if (tile_type == COLLECT)
		tmp_img = game->img_collect;
	else if (tile_type == EXIT)
		tmp_img = game->img_exit;
	else
		tmp_img = game->img_ground;
	mlx_image_to_window(game->mlx, tmp_img,
		position_x * TILE_SIZE, position_y * TILE_SIZE);
}
