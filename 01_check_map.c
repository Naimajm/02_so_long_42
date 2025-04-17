/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:00:37 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/17 21:20:59 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

//int	ft_strlen_aux(char *str);

int	check_accessible_map(t_map *map);
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
	/* if (check_accessible_map(map))
		return (ft_printf(ERROR_CHECK_NOT_ACCESS_MAP), FAILURE); */
	return (SUCCESS);	
}

// CHECK CAMINO ACCESIBLE (METODO INUNDACION -> flood fill) -----------------------
/* int	check_accessible_map(t_map *map)
{
	int	row;
	int	column;
	t_map	*tmp_map;

	//tmp_map = initialize_map(map->data, map->filename);
	tmp_map = copy_struct_map(map);
	//ft_struct_map_print(tmp_map);
	if (!tmp_map || !tmp_map->data)
		return (FAILURE);
	
	// verificacion posicion player dentro limites
	if (tmp_map->player_position.x < 0 || tmp_map->player_position.y < 0 ||
		tmp_map->player_position.x >= tmp_map->width || tmp_map->player_position.y >= tmp_map->height)
		return (clean_map(tmp_map), FAILURE);

	// rellena 'X' en toda celda accesible
	flood_fill_map(tmp_map, tmp_map->player_position.x, tmp_map->player_position.y);

	//ft_struct_map_print(tmp_map);
	row = 0;
	while (row < tmp_map->height)
	{
		column = 0;
		while (column < tmp_map->width)
		{
			// busca cualquier componente que no haya sido marcado como 'X' -> no accesible
			if (tmp_map->data[row][column] == INITIAL_POSITION || tmp_map->data[row][column] == EXIT || tmp_map->data[row][column] == COLLECT)
				return (clean_map(tmp_map), FAILURE);
			column++;
		}
		row++;
	}
	//  liberar copia mapa
	clean_map(tmp_map);	
	return (SUCCESS);
} */

int	check_accessible_map(t_map *map)
{
	int		y;
	int		x;
	char	**aux;

	aux = copy_struct_map(map);
	if (!aux)
		return (0);
	flood_fill_map(map,  map->player_position.x, map->player_position.y);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (aux[y][x] == 'E' || aux[y][x] == 'C' || aux[y][x] == 'P')
				return (free_matrix((void **)aux, y), 0);
		}
	}
	free_matrix((void **)aux, map->height);
	return (1);
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
/* int check_rectangular_map(t_map *map)
{
	int row;

	row = 0;	
	// factor forma -> len filas iguales
	while (row < map->height)
	{
		ft_printf("Fila %d: len=%d (esperado %d) [%s]\n", row, ft_strlen(map->data[row]), map->width, map->data[row]);
		if (ft_strlen(map->data[row]) != (unsigned int) map->width)
			return (FAILURE);
		row++;
	}	
	return (SUCCESS);	
} */

int check_rectangular_map(t_map *map)
{
	int		index;

	index = 0;
	while (map->data[index])
	{
		ft_printf("Fila %d: len=%d (esperado %d) [%s]\n", index, ft_strlen(map->data[index]), map->width, map->data[index]);
		if (ft_strlen(map->data[0]) != ft_strlen(map->data[index]))
			return (FAILURE);
		index++;
	}
	return (SUCCESS);
}

// debug
/* int	ft_strlen_aux(char *str)
{
	int	count;
	count = 0;
	while (str[count])
	{
		count++;
	}	
	return (count);
} */



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





