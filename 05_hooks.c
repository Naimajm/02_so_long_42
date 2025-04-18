/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 23:51:29 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/18 18:56:33 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	ft_loop_hook(void *param);
void	close_window_handler(t_game *game);
void	key_handler(t_game *game);
void	update_player_movement(t_game *game, t_coord old_pos, t_coord new_pos);

void	start_game(t_game *game)
{
	game->frame_count = -100;
	while (game->frame_count < 0)
		game->frame_count++;
	mlx_loop_hook(game->mlx, ft_loop_hook, game);
	mlx_loop(game->mlx);
}

void	ft_loop_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (!game)
		return ;
	while (game->frame_count < 50)
		game->frame_count++;
	game->frame_count = 0;
	if (!game->loop_is_running)
		return ;
	key_handler(game);
	close_window_handler(game);
	render_map(game);
}

void	close_window_handler(t_game *game)
{
	if (!game || !game->mlx || !game->loop_is_running)
		return ;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}

void	key_handler(t_game *game)
{
	t_coord	old_position;
	t_coord	new_position;

	if (!game || !game->map || !game->loop_is_running)
		return ;
	old_position = game->map->player_position;
	new_position = old_position;
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

void	update_player_movement(t_game *game, t_coord old_pos, t_coord new_pos)
{
	if (!game)
		return ;
	if (game->map->data[new_pos.y][new_pos.x] != WALL
		&& (game->map->data[new_pos.y][new_pos.x] == EXIT
			&& game->exit_success == false) == 0)
	{
		if (new_pos.x != old_pos.x || new_pos.y != old_pos.y)
		{
			if (game->map->data[new_pos.y][new_pos.x] == COLLECT)
			{
				game->map->data[new_pos.y][new_pos.x] = GROUND;
				game->map->collect_number--;
				if (game->map->collect_number == 0)
					game->exit_success = true;
			}
			game->map->player_position = new_pos;
			game->move_count++;
			ft_printf("Number of movements: %d\n", game->move_count);
			game->map->render_flag[old_pos.y][old_pos.x] = true;
			game->map->render_flag[new_pos.y][new_pos.x] = true;
			if (game->map->data[new_pos.y][new_pos.x] == EXIT
				&& game->exit_success)
				mlx_close_window(game->mlx);
		}
	}
}
