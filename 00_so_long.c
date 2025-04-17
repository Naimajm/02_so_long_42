/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:17:25 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/17 20:20:53 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h" // ft_printf, libft, MLX42

// MAIN ---------------------------------------------------------
// -----------------------------------------------------------

int	main(int argc, char **argv)
{
	char	*filename;
	t_map	*map;
	t_game	*game;

	map = NULL;
	game = NULL;
	// ARGS VALIDATION ------------------------
	if (argc < 2)
		return (ft_printf(ERROR_ARGS_1), FAILURE);
	else if (argc > 2)
		return (ft_printf(ERROR_ARGS_2), FAILURE);	
	filename = argv[1];

	// PARSEAR MAPA ->   CARGA STRUCT MAPA -------------------------
	// ---------------------------------------------
	ft_printf("------------ ALHAMBRA 2077 -----------\n");
	//map = (t_map *) malloc(sizeof(t_map));
	/* map = malloc(sizeof(t_map));
	if (!map)
	{
		//free(map);
		return (ft_printf(ERROR_ALLOCATING_MEM_MAP), FAILURE);
	}	 */			
	// CHECK EXTENSION ARCHIVO + RUTA -----------------------
	if (check_filename_type(filename))
	{
		free(map);
		//clean_map(map);		
		return (ft_printf(ERROR_TYPE_FILENAME),FAILURE);
	}		
	ft_printf("------------- INSERT COIN ------------\n");
	printf("loading map ......\n");
	map = load_map(filename);	
	printf("LOAD MAP: 		OK\n");
	if (!map)
	{
		//free(map);
		clean_map(map);
		return (ft_printf(ERROR_LOADING_MAP), FAILURE);
	}		
	//ft_struct_map_print(map);

	// CHECK MAPA (CONDICIONES SUBJECT)  ---------
	printf("checking map .....\n");
    if (check_map(map))
	{
		clean_map(map);
		return (ft_printf(ERROR_CHECK_MAP), FAILURE);
	}
	printf("CHECK MAP: 		OK\n");
	//ft_struct_map_print(map);  // debug impresion valores mapa
	
	// CARGA STRUCT GAME -------------------------
	// ---------------------------------------------
	// reserva + validacion
	printf("loading game.....\n");

	game = (t_game *) malloc(sizeof(t_game));
	if (!game)
	{
		//free(map);
		//clean_map(map);	
		cleanup_game(game);	
		return (ft_printf(ERROR_ALLOCATING_MEM_GAME), FAILURE);	
	}		
	load_game(game, map);		// inicializar struct game + cargar game
	printf("LOAD GAME: 		OK\n");
    //ft_struct_game_print(game); // debug	

	// CARGAR LOOP JUEGO -------------------------
	// ---------------------------------------------
	ft_printf("--------- PUSH START BUTTON ---------\n");
	printf("starting game.....\n");
	start_game(game);

	// SALIDA JUEGO -----------------------------	
	//cleanup_game(game);
	//mlx_close_window(game->mlx);
	
	game_over(game);
	return (SUCCESS);
}
