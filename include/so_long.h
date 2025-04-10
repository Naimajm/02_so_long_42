/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:30:57 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/10 22:44:32 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* C LIBRARIES */
#include <stdio.h>  // printf
#include <stdlib.h>	// malloc free

/* OWN LIBRARIES */
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

#include "../MLX42/include/MLX42/MLX42.h"   // file .h MLX42
#include "./MLX42/MLX42.h"		 	// main file .h MLX42  DA ERROR AL COMPILAR

/* GLOBAL VARIABLES */

# define NAME 	"so_long"		// executable name
	
// WINDOW config
# define 	WINDOW_WIDTH  	1920
# define	WINDOW_HEIGHT 	1080
# define 	WINDOW_TITLE  	"alhambra 2077"

// GAME DATA STRUCTURE  -*-------------------------------------------

// TEXTURES STRUCTUR
typedef struct s_textures
{
	mlx_texture_t	*ground;
	mlx_texture_t	*wall;
	mlx_texture_t	*collectable;
	mlx_texture_t	*exit_c;
	//mlx_texture_t	*exit_o;
	mlx_texture_t	*player;
	//mlx_texture_t	*player_up;
	//mlx_texture_t	*player_down;
	//mlx_texture_t	*player_left;
	//mlx_texture_t	*player_right;
	mlx_texture_t	*enemy;
	//mlx_texture_t   *enemy_up;
	//mlx_texture_t   *enemy_down;
	//mlx_texture_t   *enemy_left;
	//mlx_texture_t   *enemy_right;
}	t_textures;

// IMAGES STRUCTUR
typedef struct s_images
{
	mlx_image_t		*ground;
	mlx_image_t		*wall;
	mlx_image_t		*collectable;
	mlx_image_t		*exit_c;
	//mlx_image_t	*exit_o;
	mlx_image_t		*player;
	//mlx_image_t	*player_up;
	//mlx_image_t	*player_down;
	//mlx_image_t	*player_left;
	//mlx_image_t	*player_right;
	mlx_image_t		*enemy;
	//mlx_image_t   *enemy_up;
	//mlx_image_t   *enemy_down;
	//mlx_image_t   *enemy_left;
	//mlx_image_t   *enemy_right;
}	t_images;

// CELL STRUCTUR
typedef struct s_cell
{
	int	ground;
	int	wall;
	int	collectable;
	int	exit;	
	int	player;
	int	enemy;
}	t_cell;

// MAP STRUCTUR -> NEXT NOT USE
typedef struct s_map
{
	char			*map;
	struct s_map	*next;
}	t_map;

// KEY CODE STRUCTUR
typedef struct s_key_press
{
	int	key;
}	t_key_press;

// POSITION STRUCTUR
typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_game
{
	mlx_t			*mlx;			// Connection to the graphic display.
	t_textures		textures;		// Textures of the game.
	t_images		images;			// Images of the game.
	t_cell			cell;			// Object of the game.
	t_map			*map;			// Map of the game.
	
	t_coord			player;			// Position of the player.
	t_coord			enemy;			// Position of the enemy.
	t_coord			size_window;	// Size in pixels of the window.

	char			**status_a_map;	// Matrix of the map.
	char			**status_b_map;	// Matrix of the map.
	char			*path_map;		// Path to the map.	

	int				collec;			// Number of collectibles.
	int				collec_counter;	// Number of collectibles.	
	int				collec_reveived;// Collectibles collected.	

	int				status_game;	// 0 = game, 1 = win, 2 = lose
	int				moves_number;	// Number of moves.
	char			course;			// Direction of the player.
	bool			is_walking;		// Walking or not.
}	t_game;



#endif