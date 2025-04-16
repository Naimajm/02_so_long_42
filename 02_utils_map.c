/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_utils_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:16:43 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/16 20:33:07 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

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

void	flood_fill(t_map *map, char **map_data, int y, int x)
{

	
}

// COPIAR ESTRUCTURA MAP -> flood_fill() -> check_accessible_components_map()
t_map	*copy_struct_map(t_map *map)
{


}

int	components_map_counter(t_map *map, char component)
{
	int component_count;
    int position_x;
    int position_y;

	component_count = 0;
    position_y = 0;
    while (position_y < map->height)
    {
        position_x = 0;
        while (position_x < map->width)
        {
            // CONTAR COMPONENTES
            if (map->data[position_y][position_x] == component)
            	component_count++;            
            position_x++;
        }        
        position_y++;
    }    
	return (component_count);
}