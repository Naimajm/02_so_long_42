/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:30:57 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/16 01:24:36 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* C LIBRARIES */
#include <stdio.h>  // printf
#include <stdlib.h>	// malloc free
#include <fcntl.h>	// archivos open, close

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

#define ERROR_ARGS_1	"Error\n Enter a map file\n"
#define ERROR_ARGS_2	"Error\n Too many arguments\n"

#define ERROR_ALLOCATING_MEM_MAP	"Error\n Allocating map memory\n"
#define ERROR_ALLOCATING_MEM_GAME	"Error\n Allocating game memory\n"

#define ERROR_OPEN_FILE	"Error\n opening file\n"

#define ERROR_CHECK_MAP				"Error\n Check conditions map\n"
#define ERROR_CHECK_COMPONENTS_MAP	"Error\n Invalid components\n"
#define ERROR_CHECK_RECTANGULAR_MAP	"Error\n non-rectangular map\n"
#define ERROR_CHECK_CLOSED_MAP		"Error\n unclosed map\n"

// MAP ELEMENTS

#define	GROUND				'0'
#define	WALL				'1'
#define INITIAL_POSITION	'P'
#define	EXIT				'E'
#define	COLLECT				'C'

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
	bool	**render_flag;		// indicador para renderizar celda o no (true -> renderizar tile)
	int		width;
	int		height;
	int		width_pixels;
	int		height_pixels;
	int		collect_number;
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
	mlx_image_t	*img_player;	
	mlx_image_t	*img_collect;
	mlx_image_t	*img_exit;	

	int			move_count;	
	int			frame_count;
	bool		exit_success;	
}	t_game;

// so_long.c ----------------- MAIN ---------------------

int	check_map(t_map *map);
void	game_over(t_game *game);

// 02_check_map.c -------------------------------------

int	check_components_map(t_map *map);
int check_rectangular_map(t_map *map);
int	check_closed_map(t_map *map);
int	components_map_counter(t_map *map, char component);

// 04_render.c -------------------------------------

void    render_map(t_game *game);
void    render_tile(t_game *game, int position_y, int position_x);

// 03_ft_hooks.c   -> GESTION INICIALIZACION + CARGA LOOP JUEGO ---------------------------

void    start_game(t_game *game);
void    ft_loop_hook(void *param);
void    close_window_handler(t_game *game);
void    key_handler(t_game *game);
//static void    update_player_movement(t_game *game, t_coord old_position, t_coord new_position);

// init_game.c -> GESTION INICIALIZACION + CARGA ESTRUCTURA GAME -----------------------------

void    load_game(t_game *game, t_map *map);

int charge_textures(t_game *game);
t_game	*initialize_struct_game(t_game *game);

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

int		collect_map_count(t_map *map);

void    initialize_map_render_flags(t_map *map);

void    initialize_map_positions(t_map *map);

// 05_free_functions.c  -> liberacion memoria, leaks y cierre ------------------------------

void	cleanup_game(t_game *game);
void	free_textures(t_game *game);
void	clean_map(t_map *map);
void	free_matrix(void **matrix, int height);

// utils.c -> UTILIDADES ------------------------------

void    ft_struct_game_print(t_game *game);

void    ft_struct_map_print(t_map *map);

void	ft_strings_array_print(char **array);

void	ft_matrix_bools_print(t_map *map);



#endif