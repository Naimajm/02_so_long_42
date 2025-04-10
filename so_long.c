/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:17:25 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/10 22:53:04 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>  // printf


#include "./include/so_long.h" // ft_printf

static int	ft_map(t_game **game);
static t_game	*ft_initizalize_game(t_game *game);

// GENERATE MAP
int	ft_start_map(char *path_map)
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1); // RESERVA MEMORIA
	// VALIDATION
	if (!game)
		return (1); // FAILURE
	
	// INICIALIZAR VALORES DEL JUEGO
	game = ft_initizalize_game(game);

	game->path_map = path_map;	// asignar ruta mapa
	 
	return (0);  // SUCCESS
}

static int	ft_map(t_game **game)
{
	t_game	*tmp_game;

	tmp_game = *game;

	//tmp_game->map = ft_init_map(tmp_game);
	// VALIDATION MAP
	if (!tmp_game->map)
	{
		free(tmp_game);
		return (1);
	}
		 

}

// INICIALIZAR VALORES DEL JUEGO
static t_game	*ft_initizalize_game(t_game *game)
{
	game->mlx 			= NULL;
	
	// MAP VARIABLES
	game->map			= NULL;
	game->status_a_map 	= NULL;
	game->status_b_map 	= 0;
	game->path_map 		= NULL;

	//  COORDENADAS POSICION PLAYER, ENEMY + WINDOW
	game->player.x		= 0;
	game->player.y		= 0;
	game->enemy.x		= 0;
	game->enemy.y		= 0;
	game->size_window.x	= 0;
	game->size_window.y = 0;

	// collectibles VARIABLES
	game->collec		= 0;
	game->collec_counter = 0;
	game->collec_reveived = 0;

	game->status_game	= 0;
	return (game);
}

int main(void)
{    
	void	*mlx_connection; 
	void	*mlx_window; 
	

	mlx_connection = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, true); // inicializar biblioteca MLX42
	// VALIDATION
	if (!mlx_connection)
	{
		ft_printf("Error al inicializar MLX42\n");
		return (1);
	}
	// WINDOW CREATION	
	mlx_window = mlx_new_window(mlx_connection, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	// VALIDATION 
	if (!mlx_window)
	{
		mlx_terminate(mlx_connection);
		free(mlx_connection);
		return (1);
	}
		
		
	//mlx_loop(mlx_connection);



	// close MLX
	mlx_terminate(mlx_connection);
	free(mlx_connection);
    ft_printf("Adios\n");
    return (0);
}