/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:30:57 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/18 21:09:10 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"  		
# include "../MLX42/include/MLX42/MLX42.h"

# define NAME		"so_long"		
# define TILE_SIZE	64

# define SUCCESS	0
# define FAILURE	1	
# define WINDOW_WIDTH  	1920
# define WINDOW_HEIGHT 	1080
# define WINDOW_TITLE  	"alhambra 2077"

# define ERROR_ARGS		"Error\n error number arguments\n"
# define ERROR_TYPE_FILENAME	"Error\n Invalid extension file\n"

# define ERROR_MEM_GAME	"Error\n Allocating game memory\n"

# define ERROR_OPEN_FILE	"Error\n opening file\n"
# define ERROR_LOADING_MAP	"Error\n does not load map\n"

# define ERROR_CHECK_MAP				"Error\n Check conditions map\n"
# define ERROR_CHECK_NOT_ACCESS_MAP	"Error\n components not accessible\n"
# define ERROR_CHECK_COMPONENTS_MAP	"Error\n Invalid components\n"
# define ERROR_CHECK_RECTANGULAR_MAP	"Error\n non-rectangular map\n"
# define ERROR_CHECK_CLOSED_MAP		"Error\n unclosed map\n"

# define GROUND				'0'
# define WALL				'1'
# define INITIAL_POSITION	'P'
# define EXIT				'E'
# define COLLECT			'C'

typedef struct s_coord
{
	int	x;
	int	y;
}			t_coord;

typedef struct s_map
{
	char	*filename;
	char	**data;
	bool	**render_flag;
	int		width;
	int		height;
	int		width_pixels;
	int		height_pixels;
	int		collect_number;
	t_coord	player_position;
	t_coord	exit_position;	
}		t_map;

typedef struct s_game
{
	mlx_t			*mlx;	
	t_map			*map;	
	mlx_texture_t	*texture_ground;
	mlx_texture_t	*texture_wall;
	mlx_texture_t	*texture_player;
	mlx_texture_t	*texture_collect;
	mlx_texture_t	*texture_exit;

	mlx_image_t		*img_ground;
	mlx_image_t		*img_wall;
	mlx_image_t		*img_player;	
	mlx_image_t		*img_collect;
	mlx_image_t		*img_exit;	

	int				move_count;	
	int				frame_count;
	bool			exit_success;	
	bool			loop_is_running;
}	t_game;

int		check_map(t_map *map);
int		check_accessible_map(t_map *map);
int		check_components_map(t_map *map);
int		check_rectangular_map(t_map *map);
int		check_closed_map(t_map *map);

int		check_filename_type(char *filename);
void	flood_fill_map(t_map *map, int position_x, int position_y);
t_map	*copy_struct_map(t_map *map);
int		components_map_counter(t_map *map, char component);

t_map	*load_map(char *filename);
t_map	*initialize_map(t_map *map, char **data_map, char *filename);
int		collect_map_counter(t_map *map);
void	initialize_map_render_flags(t_map *map);
void	initialize_map_positions(t_map *map);

t_game	*load_game(t_map *map);
int		load_textures(t_game *game);
t_game	*initialize_struct_game(t_game *game);

void	start_game(t_game *game);
void	ft_loop_hook(void *param);
void	close_window_handler(t_game *game);
void	key_handler(t_game *game);
void	update_player_movement(t_game *game, t_coord old_pos, t_coord new_pos);

void	render_map(t_game *game);
void	render_tile(t_game *game, int position_y, int position_x);

void	game_over(t_game *game);
void	cleanup_game(t_game *game);
void	clean_images(t_game *game);
void	clean_map(t_map *map);
void	free_matrix(void **matrix, int height);

void	ft_struct_game_print(t_game *game);
void	ft_struct_map_print(t_map *map);
void	ft_strings_array_print(char **array);
void	ft_matrix_bools_print(t_map *map);

#endif