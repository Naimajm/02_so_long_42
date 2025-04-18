/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:32:59 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/18 20:00:31 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int		charge_textures(t_game *game);
t_game	*initialize_struct_game(t_game *game);

t_game	*load_game(t_map *map)
{	
	t_game	*game;

	if (!map)
		return (NULL);
	game = (t_game *) malloc(sizeof(t_game));
	if (!game)
		return (ft_printf(ERROR_MEM_GAME), NULL);
	initialize_struct_game(game);
	game->mlx = mlx_init(map->width_pixels,
			map->height_pixels, WINDOW_TITLE, true);
	if (!game->mlx)
		return (cleanup_game(game), NULL);
	game->map = map;
	charge_textures(game);
	return (game);
}

int	charge_textures(t_game *game)
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

t_game	*initialize_struct_game(t_game *game)
{
	if (!game)
		return (NULL);
	game->mlx = NULL;
	game->map = NULL;
	game->img_ground = NULL;
	game->img_wall = NULL;
	game->img_player = NULL;
	game->img_collect = NULL;
	game->img_exit = NULL;
	game->move_count = 0;
	game->frame_count = 0;
	game->exit_success = false;
	game->loop_is_running = true;
	return (game);
}
