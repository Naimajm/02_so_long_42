/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:17:25 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/18 00:58:06 by juagomez         ###   ########.fr       */
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

	if (argc != 2)
		return (ft_printf(ERROR_ARGS), FAILURE);
	filename = argv[1];

	ft_printf("------------ ALHAMBRA 2077 -----------\n");

	// PARSEAR MAPA ->   CARGA STRUCT MAPA -------------------------	
	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (ft_printf(ERROR_ALLOCATING_MEM_MAP), FAILURE);					
	if (check_filename_type(filename))	
		return (ft_printf(ERROR_TYPE_FILENAME),FAILURE);	
	
	ft_printf("\n------------- INSERT COIN ------------\n\n");
	printf("loading map ......\n");
	map = load_map(filename, map);	
	printf("LOAD MAP: 		OK\n");
	if (!map)
	{
		clean_map(map);
		return (ft_printf(ERROR_LOADING_MAP), FAILURE);
	}	
	// ---------------------------------------------	

	// CHECK MAPA (CONDICIONES SUBJECT)  ---------
	printf("checking map .....\n");
    if (check_map(map))
	{
		clean_map(map);
		return (ft_printf(ERROR_CHECK_MAP), FAILURE);
	}
	printf("CHECK MAP: 		OK\n");
	// ---------------------------------------------
	
	// CARGA STRUCT GAME -------------------------	
	printf("loading game.....\n");
	game = (t_game *) malloc(sizeof(t_game));	
	if (!game)
	{
		cleanup_game(game);	
		return (ft_printf(ERROR_ALLOCATING_MEM_GAME), FAILURE);	
	}		
	load_game(game, map);				
	printf("LOAD GAME: 		OK\n\n");
    ft_struct_game_print(game); // debug	
	// -------------------------------------------	

	// CARGAR LOOP JUEGO -------------------------	
	ft_printf("\n--------- PUSH START BUTTON ---------\n\n");	
	printf("starting game.....\n");
	start_game(game);
	// ---------------------------------------------

	// SALIDA JUEGO -----------------------------	
	game_over(game);	
	return (SUCCESS);
}
