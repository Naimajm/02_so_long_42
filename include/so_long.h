/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:30:57 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/11 14:27:56 by juagomez         ###   ########.fr       */
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
#include "../ft_printf/ft_printf.h"

#include "../MLX42/include/MLX42/MLX42.h"   // file .h MLX42

/* GLOBAL VARIABLES ----------------------------------------- */ 

#define NAME	"so_long"		// executable name

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

// GAME DATA STRUCTURE  -*-------------------------------------------

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
	int		width_px;
	int		height_px;
	int		player_n;
	t_coord	player_position;
	int		exit_n;
	t_coord	exit_position;
	int		collect_n;
}		t_map;

// GAME STRUCTUR
typedef struct s_game
{
	mlx_t		*mlx;			// Connection to the graphic display.
	t_map		*map;			// Map of the game.

	mlx_image_t	*img_ground;
	mlx_image_t	*img_wall;	
	mlx_image_t	*img_player;	
	mlx_image_t	*img_player_up;	
	mlx_image_t	*img_player_down;	
	mlx_image_t	*img_player_left;	
	mlx_image_t	*img_player_right;	
	mlx_image_t	*img_collect;
	mlx_image_t	*img_exit;

	int			move_count;
	mlx_image_t	*wmoves;
	int			frame_count;
}	t_game;



#endif