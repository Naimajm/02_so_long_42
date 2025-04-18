/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:00:37 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/18 10:45:36 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	check_accessible_map(t_map *map);
int	check_components_map(t_map *map);
int	check_rectangular_map(t_map *map);
int	check_closed_map(t_map *map);

int	check_map(t_map *map)
{
	if (check_rectangular_map(map))
		return (ft_printf(ERROR_CHECK_RECTANGULAR_MAP), FAILURE);
	if (check_closed_map(map))
		return (ft_printf(ERROR_CHECK_CLOSED_MAP), FAILURE);
	if (check_components_map(map))
		return (ft_printf(ERROR_CHECK_COMPONENTS_MAP), FAILURE);
	if (check_accessible_map(map))
		return (ft_printf(ERROR_CHECK_NOT_ACCESS_MAP), FAILURE);
	return (SUCCESS);
}

int	check_accessible_map(t_map *map)
{
	int		row;
	int		column;
	t_map	*tmp;

	tmp = copy_struct_map(map);
	if (!tmp || !tmp->data)
		return (FAILURE);
	flood_fill_map(tmp, tmp->player_position.x, tmp->player_position.y);
	row = 0;
	while (row < tmp->height)
	{
		column = 0;
		while (column < tmp->width)
		{
			if (tmp->data[row][column] == INITIAL_POSITION
				|| tmp->data[row][column] == EXIT
				|| tmp->data[row][column] == COLLECT)
				return (clean_map(tmp), FAILURE);
			column++;
		}
		row++;
	}
	clean_map(tmp);
	return (SUCCESS);
}

int	check_components_map(t_map *map)
{
	int	initial_pos_count;
	int	exit_count;
	int	ground_count;
	int	wall_count;

	initial_pos_count = components_map_counter(map, INITIAL_POSITION);
	exit_count = components_map_counter(map, EXIT);
	ground_count = components_map_counter(map, GROUND);
	wall_count = components_map_counter(map, WALL);
	if ((initial_pos_count + exit_count + ground_count + wall_count \
		+ map->collect_number) < (map->width * map->height))
		return (FAILURE);
	if (initial_pos_count > 1 || exit_count > 1)
		return (FAILURE);
	if (map->collect_number == 0 || initial_pos_count == 0 || exit_count == 0)
		return (FAILURE);
	return (SUCCESS);
}

int	check_rectangular_map(t_map *map)
{
	int		index;

	index = 0;
	while (map->data[index])
	{
		if (ft_strlen(map->data[0]) != ft_strlen(map->data[index]))
			return (FAILURE);
		index++;
	}
	return (SUCCESS);
}

int	check_closed_map(t_map *map)
{
	int	row;
	int	column;

	row = 0;
	while (row < map->height)
	{
		column = 0;
		while (column < map->width)
		{
			if (map->data[0][column] != WALL \
				|| map->data[map->height - 1][column] != WALL)
				return (FAILURE);
			if (map->data[row][0] != WALL \
				|| map->data[row][map->width - 1] != WALL)
				return (FAILURE);
			column++;
		}
		row++;
	}
	return (SUCCESS);
}
