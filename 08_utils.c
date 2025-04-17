/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:20:02 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/17 22:05:28 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void    ft_struct_map_print(t_map *map);
void	ft_strings_array_print(char **array);
void	ft_matrix_bools_print(t_map *map);

// DEBUG -> IMPRIMIR ESTRUCTURA GAME
void    ft_struct_game_print(t_game *game)
{
	if (!game)
		return ;
	// impresion variables estructura map
	ft_printf("** STRUCT GAME----------------: \n");
	ft_printf("mlx: %i\n", game->mlx);
	ft_printf("map: \n");	
	ft_struct_map_print(game->map);

	ft_printf("img_ground: %i\n", game->img_ground);
	ft_printf("img_wall: %i\n", game->img_wall);
	ft_printf("img_player: %i\n", game->img_player);
	ft_printf("img_collect: %i\n", game->img_collect);
	ft_printf("img_exit: %i\n", game->img_exit);

	ft_printf("move_count: %i\n", game->move_count);
	ft_printf("frame_count: %i\n", game->frame_count);
	ft_printf("exit_success: %i\n", game->exit_success);
	ft_printf("\n");
}

// DEBUG -> IMPRIMIR ESTRUCTURA MAP
void    ft_struct_map_print(t_map *map)
{
	// impresion variables estructura map
	ft_printf("** STRUCT MAP----------------: \n");
	ft_printf("filename: %s\n", map->filename);
	ft_printf("data: \n");
	ft_strings_array_print(map->data);
	

	ft_printf("width x height: (%i, %i)\n", map->width, map->height);
	ft_printf("width_pixels x height_pixels: (%i, %i)\n", map->width_pixels, map->height_pixels);
	ft_matrix_bools_print(map);
	ft_printf("collect_number: %i\n", map->collect_number);

	ft_printf("player_position (x, y): (%i, %i)\n", map->player_position.x, map->player_position.y);
	ft_printf("exit_position (x, y): (%i, %i)\n", map->exit_position.x, map->exit_position.y);
	ft_printf("-------\n");
}

// DEBUG -> IMPRIMIR LISTA STRINGS -> char **
void	ft_strings_array_print(char **array)
{
    if (array == NULL)
    	return ;

    int index = 0;
    while (array[index]) {
        ft_printf("%s\n", array[index]);
        index++;
    }
}

// DEBUG -> IMPRIMIR LISTA BOOLEANOS (bool **)
void	ft_matrix_bools_print(t_map *map)
{
	int index_row;
	int index_column;
	bool	**bools_list;
	// validation
    if (!map)
		return ;

	index_row = 0;
	bools_list = map->render_flag;
    ft_printf("map->render_flags (%d x %d):\n", map->width ,map->height);    
    while (index_row < map->height) {
        if (bools_list[index_row] == NULL) {
            printf("Row %d is NULL\n", index_row);
            index_row++;
            continue;
        }
        index_column = 0;
        while (index_column < map->width) {
            printf("%d", bools_list[index_row][index_column]);
            index_column++;
        }
        printf("\n");
        index_row++;
    }
}