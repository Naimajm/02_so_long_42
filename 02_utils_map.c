/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_utils_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:16:43 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/16 23:43:21 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	flood_fill_map(t_map *map, int position_x, int position_y);
t_map	*copy_struct_map(t_map *map);
int	components_map_counter(t_map *map, char component);

int	check_filename_type(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	// check extension .ber
	if (len < 5 || ft_strncmp(filename + (len - 4), ".ber", 4) != 0)
		return (FAILURE);
	return (SUCCESS);
}

// algoritmo propagacion -> conectar componentes del mapa
void	flood_fill_map(t_map *map, int position_x, int position_y)
{
    // CONDICIONES PARADA PROPAGACION -> (fuera limites mapa, muros o ya marcados)
    if (position_x < 0 || position_x >= map->width || position_y < 0 || position_y >= map->height || map->data[position_y][position_x] == WALL || map->data[position_y][position_x] == 'X')
        return ;

    // MARCADO CELDA ACTUAL
    map->data[position_y][position_x] = 'X';

    // PROPAGACION RECURSIVA (up, down, left, right)
    flood_fill_map(map, position_x - 1, position_y);
    flood_fill_map(map, position_x + 1, position_y);
    flood_fill_map(map, position_x, position_y - 1);
    flood_fill_map(map, position_x, position_y + 1);	
}

// COPIAR ESTRUCTURA MAP -> flood_fill() -> check_accessible_components_map()
/* t_map	*copy_struct_map(t_map *map)
{
    t_map   *copy_map;  
    copy_map = initialize_map(map->data, map->filename);
    return (copy_map);
} */

t_map	*copy_struct_map(t_map *map)
{
    t_map	*new_map;
    int		row;

    new_map = (t_map *) malloc(sizeof(t_map));
    if (!new_map)
        return (NULL);

    // Copiar datos básicos
    new_map->filename = ft_strdup(map->filename);
    new_map->height = map->height;
    new_map->width = map->width;
    new_map->player_position = map->player_position;

    // Copiar data (copia profunda)
    new_map->data = (char **)malloc(sizeof(char *) * new_map->height);
    if (!new_map->data)
        return (clean_map(new_map), NULL);
    row = 0;
    while (row < new_map->height)
    {
        new_map->data[row] = ft_strdup(map->data[row]);
        if (!new_map->data[row])
            return (clean_map(new_map), NULL);
        row++;
    }
    return (new_map);
}

int	components_map_counter(t_map *map, char component)
{
	int component_count;
    int column;
    int row;

	component_count = 0;
    row = 0;
    while (row < map->height)
    {
        column = 0;
        while (column < map->width)
        {
            // CONTAR COMPONENTES
            if (map->data[row][column] == component)
            	component_count++;            
            column++;
        }        
        row++;
    }    
	return (component_count);
}