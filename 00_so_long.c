/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:17:25 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/18 19:59:42 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	main(int argc, char **argv)
{
	char	*filename;
	t_map	*map;
	t_game	*game;

	map = NULL;
	game = NULL;
	if (argc != 2)
		return (ft_printf(ERROR_ARGS), FAILURE);
	filename = argv[1];
	if (check_filename_type(filename))
		return (ft_printf(ERROR_TYPE_FILENAME), FAILURE);
	map = load_map(filename);
	if (!map)
		return (clean_map(map), ft_printf(ERROR_LOADING_MAP), FAILURE);
	if (check_map(map))
		return (clean_map(map), ft_printf(ERROR_CHECK_MAP), FAILURE);
	game = load_game(map);
	if (!game)
		return (cleanup_game(game), ft_printf(ERROR_MEM_GAME), FAILURE);	
	start_game(game);
	game_over(game);
	return (SUCCESS);
}
