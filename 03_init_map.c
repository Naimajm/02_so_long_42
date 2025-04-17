/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:55:16 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/17 22:34:47 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

t_map	*initialize_map(char **data_map, char *filename);
int		collect_map_counter(t_map *map);
void    initialize_map_render_flags(t_map *map);
void    initialize_map_positions(t_map *map);

// CARGAR DATOS MAPA
t_map	*load_map(char *filename)
{
	int	fd;
	char	*raw_string_map;	// string raw input
	char	**data_map; 	// lista lineas mapas	
	t_map	*map;

	// LECTURA ARCHIVO MAPA ---------------------------------
	fd = open(filename, O_RDONLY); // abrir archivo
	// validation
	if (fd == -1)		
	{
		ft_printf(ERROR_OPEN_FILE);
		exit (FAILURE);
	}		
	// RESERVAR STRING DEL ARCHIVO
	// !! calloc vs malloc -> error con malloc al no incorporar con ft_split un terminador nulo¡¡
	raw_string_map = calloc((1280 * 1024), sizeof(char)); // !! calloc vs malloc
	if (!raw_string_map)
		return (close(fd), NULL);

	// LECTURA + ASIGNACION STRING MAPA	
	read(fd, raw_string_map, ((1280 * 1024) - 1)); // ASIGNACION lineas MAPA a variable
	close(fd);
	
	
	// PROCESAMIENTO LINEAS CARACTER en CHAR**
	data_map = ft_split(raw_string_map,'\n'); 	// lista LINEAS
	//filtered_map = filter_empty_lines(data_map);
	free(raw_string_map);
	if (!data_map)
		return(NULL);
	//ft_printf("string_map ->\n%s\n", data_map);
			
	//ft_printf("data_map -> \n");
	//ft_strings_array_print(data_map);
	
	// INICIALIZACION MAPA
	map = initialize_map(data_map, filename); 	
		
	raw_string_map = NULL;		
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
	map->width_pixels	= map->width  * TILE_SIZE;	// total pixels map dimension
	map->height_pixels	= map->height * TILE_SIZE;	// total pixels map dimension

	// contar coleccionables en mapa
	map->collect_number	= collect_map_counter(map);
	
	// inicializacion lista booleanos bool**
    initialize_map_render_flags(map);  

    // inicializacion posicion inicial + posicion salida
    initialize_map_positions(map);   

	// debug
	//ft_printf("data_map initialize_map-> \n");
	//ft_strings_array_print(data_map);
	//ft_printf("map initialize_map-> \n");
	//ft_struct_map_print(map);
	return (map);	
}

int    collect_map_counter(t_map *map)
{
	int collect_number;
    int position_x;
    int position_y;

	collect_number = 0;
    position_y = 0;
    // ciclo recorrido de todas posiciones x por cada linea
    while (position_y < map->height)
    {
        position_x = 0;
        while (position_x < map->width)
        {
            // CONTAR COLECCIONABLES
            if (map->data[position_y][position_x] == COLLECT)
            	collect_number++;            
            position_x++;
        }        
        position_y++;
    }    
	return (collect_number);
}

// inicializar lista booleanos por cada celda
void  initialize_map_render_flags(t_map *map) 
{    
    int position_x;
	int position_y;

    position_y = 0;    
    // reserva lista bool ** flags
    map->render_flag = (bool **) calloc(sizeof(bool *), (map->width + 1));
    // validation
    if (!map->render_flag)
        return ;
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
	//map->render_flag[map->height] = NULL;
}

void    initialize_map_positions(t_map *map)
{
    int position_x;
    int position_y;

    position_y = 0;
    // ciclo recorrido de todas posiciones x por cada linea
    while (position_y < map->height)
    {
        position_x = 0;
        while (position_x < map->width)
        {
            // MARCAR POSICION INICIAL JUGADOR 'P'
            if (map->data[position_y][position_x] == INITIAL_POSITION)
            {
                map->player_position.x	= position_x; 
                map->player_position.y	= position_y;
            }
            // MARCAR POSICION SALIDA 'E'
            else if (map->data[position_y][position_x] == EXIT)
            {
                map->exit_position.x	= position_x; 
                map->exit_position.y	= position_y;
            }
            position_x++;
        }        
        position_y++;
    }    
}
