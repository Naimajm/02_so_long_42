/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:17:25 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/16 12:08:32 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h" // ft_printf, libft, MLX42

int	check_filename_type(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	// check extension .ber
	if (len < 5 || ft_strncmp(filename + (len - 4), ".ber", 4) != 0)
		return (FAILURE);
	return (SUCCESS);
}

int	check_map(t_map *map)
{
	// COMPILACION FUNCIONES AUX CHECK SEGUN SUBJECT	
	if (check_rectangular_map(map))
		return (ft_printf(ERROR_CHECK_RECTANGULAR_MAP), FAILURE);
	//printf("check_rectangular_map: 	OK\n");
	if (check_closed_map(map))
		return (ft_printf(ERROR_CHECK_CLOSED_MAP), FAILURE);
	//printf("check_closed_map: 		OK\n");
	if (check_components_map(map))
		return (ft_printf(ERROR_CHECK_COMPONENTS_MAP), FAILURE);
	//printf("check_components_map: 	OK\n");
	
	// CAMINO ACCESIBLE

	printf("check_map: 		 OK\n");
	return (SUCCESS);	
}

void	game_over(t_game *game)
{	
	ft_printf("------------- GAME OVER -------------\n");
	if (!game)
		return ;
	// contador tiempo antes de cierre
	game->frame_count = -25;
	while (game->frame_count < 0)
		game->frame_count++;

	mlx_close_window(game->mlx);	
	// LIMPIEZA JUEGO
	cleanup_game(game);	
}

// MAIN ---------------------------------------------------------
// -----------------------------------------------------------

int	main(int argc, char **argv)
{
	char	*filename;
	t_map	*map;
	t_game	*game;

	// ARGS VALIDATION ------------------------
	if (argc < 2)
		return (ft_printf(ERROR_ARGS_1), FAILURE);
	else if (argc > 2)
		return (ft_printf(ERROR_ARGS_2), FAILURE);	
	filename = argv[1];

	// PARSEAR MAPA ->   CARGA STRUCT MAPA -------------------------
	// ---------------------------------------------
	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (ft_printf(ERROR_ALLOCATING_MEM_MAP), FAILURE);		
	// CHECK EXTENSION ARCHIVO + RUTA -----------------------
	if (check_filename_type(filename))
		return (ft_printf(ERROR_TYPE_FILENAME), FAILURE);
		
	ft_printf("------------- INSERT COIN -------------\n");
	map = load_map(filename);	
	// CHECK MAPA (CONDICIONES SUBJECT)  ---------
    if (check_map(map))
	{
		clean_map(map);
		return (ft_printf(ERROR_CHECK_MAP), FAILURE);
	}
	ft_struct_map_print(map);  // debug impresion valores mapa
	printf("load_map: OK\n");
	
	// CARGA STRUCT GAME -------------------------
	// ---------------------------------------------
	// reserva + validacion
	game = (t_game *) malloc(sizeof(t_game));
	if (!game)
		return (ft_printf(ERROR_ALLOCATING_MEM_GAME), FAILURE);	
	//printf("load game inicio");
	load_game(game, map);		// inicializar struct game + cargar game
	printf("load_game: OK\n");
    ft_struct_game_print(game); // debug	

	// CARGAR LOOP JUEGO -------------------------
	// ---------------------------------------------
	ft_printf("------------- PUSH START BUTTON -------------\n");
	start_game(game);

	// SALIDA JUEGO -----------------------------
	game_over(game);
	return (SUCCESS);
}
