/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:17:25 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/11 14:31:01 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h" // ft_printf

t_game	*ft_initialize_struct_game(t_game *game);

// GENERATE MAP
t_map	*load_map(char *filename)
{
	int	file_descriptor;

	//char	*str_map;	// string input
	//char	**data_map; // lista lineas mapas
	t_map	*map;

	// abrir archivo
	file_descriptor = open(filename, O_RDONLY);
	// validation
	if (file_descriptor == -1)
	{
		ft_printf(ERROR_OPEN_FILE);
		return (NULL);
	}
	map = NULL;


	return (map);
}

// INICIALIZAR VALORES STRUCTURA GAME 
t_game	*ft_initialize_struct_game(t_game *game)
{
	game->mlx = NULL;			
	game->map = NULL;		

	game->img_ground = NULL;
	game->img_wall = NULL;	
	game->img_player = NULL;	
	game->img_player_up = NULL;	
	game->img_player_down = NULL;	
	game->img_player_left = NULL;	
	game->img_player_right = NULL;	
	game->img_collect = NULL;
	game->img_exit = NULL;

	game->move_count = 0;
	game->wmoves = NULL;
	game->frame_count = 0;
	return (game);
}

// MAIN ---------------------------------------------------------
// -----------------------------------------------------------

int	main(int argc, char **argv)
{
	t_map	*map;
	//t_game	*game;

	// ARGS VALIDATION
	if (argc < 2)
		return (ft_printf(ERROR_ARGS_1));
	else if (argc > 2)
		return (ft_printf(ERROR_ARGS_2));
	
	// inicializacion map 
	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (FAILURE);
	//map = load_map(argv[1]);
	map = NULL;	
	ft_printf("%s", argv[1]);

	return (SUCCESS);
}

/* // Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
} */

/* int main(void)
{    
	// MLX allows you to define its core behaviour before startup.
	//mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, true);
	if (!mlx)
		ft_error();		
		
	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);

	// close MLX
	mlx_terminate(mlx);
    ft_printf("Adios\n");
    return (0);
} */

/* #include <string.h>	// memset
#define BPP sizeof(int32_t)

int32_t	main(void)
{
    mlx_t* mlx = mlx_init(256, 256, "MLX42", true);
    if (!mlx)
        exit(EXIT_FAILURE);

    mlx_image_t* img = mlx_new_image(mlx, 128, 128);

    // Set the channels of each pixel in our image to the maximum byte value of 255. 
    memset(img->pixels, 255, img->width * img->height * BPP);

    mlx_image_to_window(mlx, img, 0, 0);

    // Run the main loop and terminate on quit.  
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
} */