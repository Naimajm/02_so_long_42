/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:17:25 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/16 20:35:53 by juagomez         ###   ########.fr       */
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
	//ft_struct_map_print(map);  // debug impresion valores mapa
	printf("load_map: 		OK\n");
	
	// CARGA STRUCT GAME -------------------------
	// ---------------------------------------------
	// reserva + validacion
	game = (t_game *) malloc(sizeof(t_game));
	if (!game)
		return (ft_printf(ERROR_ALLOCATING_MEM_GAME), FAILURE);	
	//printf("load game inicio");
	load_game(game, map);		// inicializar struct game + cargar game
	printf("load_game: 		OK\n");
    ft_struct_game_print(game); // debug	

	// CARGAR LOOP JUEGO -------------------------
	// ---------------------------------------------
	ft_printf("------------- PUSH START BUTTON -------------\n");
	start_game(game);

	// SALIDA JUEGO -----------------------------
	game_over(game);
	return (SUCCESS);
}
