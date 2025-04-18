/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:55:16 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/17 23:35:07 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

t_map	*initialize_map(t_map *map, char **data_map, char *filename);
int		collect_map_counter(t_map *map);
void    initialize_map_render_flags(t_map *map);
void    initialize_map_positions(t_map *map);

// CARGAR DATOS MAPA
t_map	*load_map(char *filename, t_map *map)
{
	int	fd;
	char	*raw_string_map;	// string raw input
	char	**data_map; 	// lista lineas mapas

	// LECTURA ARCHIVO MAPA ---------------------------------
	fd = open(filename, O_RDONLY); // abrir archivo
	if (fd == -1)		
	{
		ft_printf(ERROR_OPEN_FILE);
		exit (FAILURE);
	}		
	// RESERVAR STRING DEL ARCHIVO
	// !! calloc vs malloc -> error con malloc al no incorporar con ft_split un terminador nulo¡¡
	raw_string_map = calloc((1280 * 1024), sizeof(char));
	if (!raw_string_map)
		return (close(fd), NULL);

	// LECTURA + ASIGNACION STRING MAPA	
	read(fd, raw_string_map, ((1280 * 1024) - 1)); // ASIGNACION lineas MAPA a variable
	close(fd);
		
	// PROCESAMIENTO LINEAS CARACTER en CHAR**
	data_map = ft_split(raw_string_map,'\n'); 	// lista LINEAS	
	if (!data_map)
		return(NULL);	
	
	// INICIALIZACION MAPA
	map = initialize_map(map, data_map, filename); 	
		
	free(raw_string_map);
	raw_string_map = NULL;		
	return (map);
}

t_map	*initialize_map(t_map *map, char **data_map, char *filename)
{
	int	height; 	
	int width;

	height 	= 0;
	width 	= 0;
	if (!data_map || !filename)
		return (NULL);
	
	// conocer altura map (height)
	while (data_map[height])
		height++;

	// conocer anchura map (width)
	width = ft_strlen(data_map[0]);

	// asignacion variables
	map->filename 		= filename;
	map->data			= data_map;	
	map->width			= width;
	map->height			= height;
	map->width_pixels	= map->width  * TILE_SIZE;	// total pixels map dimension
	map->height_pixels	= map->height * TILE_SIZE;	// total pixels map dimension

	// contar coleccionables en mapa
	map->collect_number	= collect_map_counter(map);
	
	// inicializacion lista booleanos bool**
    initialize_map_render_flags(map);  

    // inicializacion posicion inicial + posicion salida
    initialize_map_positions(map);   

	//ft_struct_map_print(map); // debug
	return (map);	
}

int    collect_map_counter(t_map *map)
{
	int collect_number;    
    int row;
	int column;

	collect_number = 0;
    row = 0;
    // ciclo recorrido de todas posiciones x por cada linea
    while (row < map->height)
    {
        column = 0;
        while (column < map->width)
        {
            // CONTAR COLECCIONABLES
            if (map->data[row][column] == COLLECT)
            	collect_number++;            
            column++;
        }        
        row++;
    }    
	return (collect_number);
}

// inicializar lista booleanos por cada celda
void  initialize_map_render_flags(t_map *map) 
{    
    int position_x;
	int position_y;       

    // reserva lista bool ** flags
    map->render_flag = (bool **) calloc(sizeof(bool *), (map->width + 1));
    if (!map->render_flag)
		return ;

	position_y = 0; 
    while (position_y < map->height)
    {        
        position_x = 0;

        // reserva lista bool * flags por cada linea mapa
		map->render_flag[position_y] = (bool *) calloc(sizeof(bool), map->width);

        while (position_x < map->width)
        {
            map->render_flag[position_y][position_x] = true;  // por defecto -> requiere 'renderizar celda'
            position_x++;
        }
        position_y++;
    }    
}

void    initialize_map_positions(t_map *map)
{
	int row;
    int column;    

    row = 0;
    // ciclo recorrido de todas posiciones x por cada linea
    while (row < map->height)
    {
        column = 0;
        while (column < map->width)
        {
            // MARCAR POSICION INICIAL JUGADOR 'P'
            if (map->data[row][column] == INITIAL_POSITION)
            {
                map->player_position.x	= column; 
                map->player_position.y	= row;
            }
            // MARCAR POSICION SALIDA 'E'
            else if (map->data[row][column] == EXIT)
            {
                map->exit_position.x	= column; 
                map->exit_position.y	= row;
            }
            column++;
        }        
        row++;
    }    
}
