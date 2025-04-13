/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:30:57 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/13 14:05:28 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* C LIBRARIES */
#include <stdio.h>  // printf
#include <stdlib.h>	// malloc free
#include <fcntl.h>	// archivos open 

/* OWN LIBRARIES */
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"  // ft_printf

#include "../MLX42/include/MLX42/MLX42.h"   // file .h MLX42

/* GLOBAL VARIABLES ----------------------------------------- */ 

#define NAME		"so_long"		// executable name
#define TILE_SIZE	64				// Size of the tiles in pixels.

#define SUCCESS	0
#define	FAILURE	1
	
// WINDOW config
#define	WINDOW_WIDTH  	1920
#define	WINDOW_HEIGHT 	1080
#define	WINDOW_TITLE  	"alhambra 2077"

// ERRORS MESSAGES 

#define ERROR_ARGS_1	"Error: enter a map file\n"
#define ERROR_ARGS_2	"Error: too many arguments\n"

#define ERROR_OPEN_FILE	"Error: opening file\n"

// MAP ELEMENTS

#define INITIAL_POSITION	'P'
#define	EXIT				'E'

// GAME DATA STRUCTURE  --------------------------------------------

// POSITION STRUCTUR
typedef struct s_coord
{
	int	x;
	int	y;
}			t_coord;

// MAP STRUCTUR
typedef struct s_map
{
	char	*filename;
	char	**data;
	bool	**update_flags;
	int		width;
	int		height;
	int		width_pixels;
	int		height_pixels;
	int		player_n;	
	int		exit_n;
	int		collect_n;
	t_coord	player_position;
	t_coord	exit_position;
	
}		t_map;

// GAME STRUCTUR
typedef struct s_game
{
	mlx_t		*mlx;			// Connection to the graphic display.
	t_map		*map;			// Map of the game.

	mlx_image_t	*img_ground;
	mlx_image_t	*img_wall;

	mlx_image_t	*img_player_down;
	mlx_image_t	*img_player_up;			
	mlx_image_t	*img_player_left;	
	mlx_image_t	*img_player_right;	
	
	/* mlx_image_t	*img_enemy_up;	
	mlx_image_t	*img_enemy_down;	
	mlx_image_t	*img_enemy_left;	
	mlx_image_t	*img_enemy_right; */
	
	mlx_image_t	*img_collect;
	mlx_image_t	*img_exit_open;
	mlx_image_t	*img_exit_closed;

	int			move_count;
	//mlx_image_t	*wmoves;
	int			frame_count;
}	t_game;

// ft_loop.c   -> GESTION INICIALIZACION + CARGA LOOP JUEGO --------------------------------


// init_game.c -> GESTION INICIALIZACION + CARGA ESTRUCTURA GAME -----------------------------

void    load_game(t_game *game, t_map *map);


// init_mapping.c -> GESTION ARCHIVO MAPA, CONFIGURACION , CARGA MAPA -----------------------

/** 
* @brief Lee archivo mapa, procesa y guarda la informacion y la transforma en estructura 't_map' para cargar mapa.
* @param filename char*: nombre archivo mapa.
* @returns t_map * -> puntero a estructura mapa configurada.
*/
t_map	*load_map(char *filename);

/** 
* @brief Función auxiliar para inicializar 't_map' mapa. Calcula dimensiones y asigna los valores de la estructura del mapa.
* @param data_map char **: lista strings con la definición de lineas del mapa.
* @param filename char*: nombre archivo mapa.
* @returns t_map * -> puntero a estructura mapa inicializada.
*/
t_map	*initialize_map(char **data_map, char *filename);

void    initialize_map_flags(t_map *map);

void    initialize_map_positions(t_map *map);

// utils.c -> UTILIDADES ------------------------------

void    ft_struct_game_print(t_game *game);

void    ft_struct_map_print(t_map *map);

void	ft_strings_array_print(char **array);

void	ft_matrix_bools_print(t_map *map);



#endif