/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:17:25 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/13 17:51:00 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h" // ft_printf



// MAIN ---------------------------------------------------------
// -----------------------------------------------------------

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	//ft_printf("nombre mapa -> %s\n", argv[1]);

	// ARGS VALIDATION ------------------------
	if (argc < 2)
		return (ft_printf(ERROR_ARGS_1), FAILURE);
	else if (argc > 2)
		return (ft_printf(ERROR_ARGS_2), FAILURE);		

	// CARGA STRUCT MAPA -------------------------
	// ---------------------------------------------
	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (FAILURE);

	map = load_map(argv[1]);
	// CHECK MAPA (CONDICIONES SUBJECT)  ---------
    /* if (!map || !check_map(map))
		return (ft_free_exit(data_map, map), NULL); */
	ft_struct_map_print(map);  // debug impresion valores mapa
	
	// CARGA STRUCT GAME -------------------------
	// ---------------------------------------------
	// reserva + validacion
	game = (t_game *) malloc(sizeof(t_game));
	/* if (!game)
		return (cleanup(game), EXIT_FAILURE); */

	load_game(game, map);		// inicializar struct game + cargar game
    ft_struct_game_print(game); // debug
	
	// CARGAR LOOP JUEGO -------------------------
	// ---------------------------------------------
	
	mlx_loop(game->mlx);

	// SALIDA JUEGO -----------------------------
	

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