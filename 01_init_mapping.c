/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_init_mapping.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:55:16 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/13 14:07:53 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

t_map	*initialize_map(char **data_map, char *filename);
void    initialize_map_flags(t_map *map);
void    initialize_map_positions(t_map *map);

// CARGAR DATOS MAPA
t_map	*load_map(char *filename)
{
	int	file_descriptor;

	char	*raw_string_map;	// string raw input
	char	**data_map; 	// lista lineas mapas
	t_map	*map;

	// LECTURA ARCHIVO MAPA ---------------------------------
	file_descriptor = open(filename, O_RDONLY); // abrir archivo
	// validation
	if (file_descriptor == -1)
	{
		ft_printf(ERROR_OPEN_FILE);
		return (NULL);
	}
	// RESERVAR STRING DEL ARCHIVO
	raw_string_map = (char *) malloc(sizeof(char) * (1280 * 1024)); // max resolucion (1280 × 1024 píxeles)
	if (!raw_string_map)
	{
		close(file_descriptor);
		return(NULL);
	}
	// LECTURA + ASIGNACION STRING MAPA		
	read(file_descriptor, raw_string_map, ((1280 * 1024) - 1));	// ASIGNACION STRING MAPA a variable
	close(file_descriptor);
	//ft_printf("string_map ->\n%s\n", string_map);
	
	// PROCESAMIENTO LINEAS CARACTER en CHAR**
	data_map = ft_split(raw_string_map,'\n'); 	// lista LINEAS
	if (!data_map)
		return(NULL);	
	free(raw_string_map);	
	//ft_printf("data_map -> \n");
	//ft_strings_array_print(data_map);
	
	// INICIALIZACION MAPA
	map = initialize_map(data_map, filename);    
	return (map);
}

t_map	*initialize_map(char **data_map, char *filename)
{
	t_map	*map;
	int	height; 	
	int width;

	height 	= 0;
	width 	= 0;
	// validation input
	if (!data_map || !filename)
		return (NULL);
	
	// conocer altura map (height)
	while (data_map[height])
		height++;
	// conocer anchura map (width)
	width = ft_strlen(data_map[0]);

	// reserva mem + validacion
	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	
	// asignacion variables estructura map
	map->filename 		= filename;
	map->data			= data_map;	

	map->width			= width;
	map->height			= height;
	map->width_pixels	= width  * TILE_SIZE;	// total pixels map dimension
	map->height_pixels	= height * TILE_SIZE;	// total pixels map dimension

	map->player_n		= 0;	
	map->exit_n			= 0;
	map->collect_n		= 0;
	
	// inicializacion lista booleanos bool**
    initialize_map_flags(map);  

    // inicializacion posicion inicial + posicion salida
    initialize_map_positions(map);    
	return (map);	
}

// inicializar lista booleanos por cada celda
void  initialize_map_flags(t_map *map) 
{
    int index_height;
    int index_width;

    index_height = 0;
    
    // reserva lista bool ** flags
    map->update_flags = (bool **) malloc(map->height * sizeof(bool *));
    // validation
    if (!map->update_flags)
        return ;
    while (index_height < map->height)
    {        
        index_width = 0;
        // reserva lista bool * flags por cada linea mapa
        map->update_flags[index_height] = (bool *) malloc(sizeof(bool) * map->width);
        while (index_width < map->width)
        {
            map->update_flags[index_height][index_width] = true;  // por defecto
            index_width++;
        }
        index_height++;
    }    
}

void    initialize_map_positions(t_map *map)
{
    int index_width;
    int index_height;

    index_height = 0;
    // ciclo recorrido de todas posiciones x por cada linea
    while (index_height < map->height)
    {
        index_width = 0;
        while (index_width < map->width)
        {
            //ft_printf("map->data[%i][%i] -> %c\n", index_height, index_width, map->data[index_height][index_width]);
            // MARCAR POSICION INICIAL JUGADOR 'P'
            if (map->data[index_height][index_width] == INITIAL_POSITION)
            {
                map->player_position.x	= index_width; 
                map->player_position.y	= index_height;
            }
            // MARCAR POSICION SALIDA 'E'
            else if (map->data[index_height][index_width] == EXIT)
            {
                map->exit_position.x	= index_width; 
                map->exit_position.y	= index_height;
            }
            index_width++;
        }        
        index_height++;
    }    
}