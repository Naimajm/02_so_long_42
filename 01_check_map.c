/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:00:37 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/16 20:34:06 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	check_accessible_components_map(t_map *map);
int	check_components_map(t_map *map);
int check_rectangular_map(t_map *map);
int	check_closed_map(t_map *map);

int	check_map(t_map *map)
{
	// COMPILACION FUNCIONES AUX CHECK SEGUN SUBJECT	
	if (check_rectangular_map(map))
		return (ft_printf(ERROR_CHECK_RECTANGULAR_MAP), FAILURE);
	if (check_closed_map(map))
		return (ft_printf(ERROR_CHECK_CLOSED_MAP), FAILURE);
	if (check_components_map(map))
		return (ft_printf(ERROR_CHECK_COMPONENTS_MAP), FAILURE);
	if (check_accessible_components_map(map))
		return (ft_printf(ERROR_CHECK_NOT_ACCESS_MAP), FAILURE);
	printf("check_map: 		 OK\n");
	return (SUCCESS);	
}

// CHECK CAMINO ACCESIBLE (METODO INUNDACION -> flood fill) -----------------------
int	check_accessible_components_map(t_map *map)
{
	char	**tmp_map;
	

	
	

	
}

// CHECK COMPONENTES -----------------------
int	check_components_map(t_map *map)
{
	int	initial_pos_count;
	int	exit_count;
	int	ground_count;
	int	wall_count;

	initial_pos_count 	= components_map_counter(map, INITIAL_POSITION);
	exit_count 			= components_map_counter(map, EXIT);
	ground_count 		= components_map_counter(map, GROUND);
	wall_count 			= components_map_counter(map, WALL);
	// SOLO 5 COMPONENTES (0, 1, P, E, C)
	if ((initial_pos_count + exit_count + ground_count + wall_count + map->collect_number) < (map->width * map->height))	
		return (FAILURE);	
	
	// COMPONENTES DUPLICADOS
	if (initial_pos_count > 1 || exit_count > 1)
		return (FAILURE);	

	// EXISTEN COMPONENTES MINIMOS (E = 1, P = 1, C > 0)
	if (map->collect_number == 0 || initial_pos_count == 0 || exit_count == 0)
		return (FAILURE);	
	return (SUCCESS);
}

// CHECK MAPA RECTANGULAR  -----------------------
int check_rectangular_map(t_map *map)
{
	int row;

	row = 0;	
	// factor forma -> len filas iguales
	while (row < map->height)
	{
		if (ft_strlen(map->data[row]) != (unsigned int) map->width)
			return (FAILURE);
		row++;
	}	
	return (SUCCESS);	
}

// CHECK MAPA CERRADO -----------------------
int	check_closed_map(t_map *map)
{
	int row;
	int column;
	
	row = 0;
	// ciclo filas
	while (row < map->height)
	{
		column = 0;	
		//  ciclo columnas
		while (column < map->width)
		{
			// 1º fila +ultima fila -> num muros == anchura
			if (map->data[0][column] != WALL || map->data[map->height - 1][column] != WALL)
				return (FAILURE);

			// resto filas -> 1 elem + ultimo (x = 0 + x = width) == Wall
			if (map->data[row][0] != WALL || map->data[row][map->width - 1] != WALL)
				return (FAILURE);
			column++;
		}		
		row++;
	}		
	return (SUCCESS);
}





