/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:00:37 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/22 22:24:35 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	check_accessible_map(t_map *map);
int	check_components_map(t_map *map);
int	check_rectangular_map(t_map *map);
int	check_closed_map(t_map *map);

int	check_map(t_map *map)
{
	if (!map)
		return (FAILURE);
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
	int		r;
	int		col;
	t_map	*tmp;

	if (!map)
		return (FAILURE);
	tmp = copy_struct_map(map);
	if (!tmp || !tmp->data)
		return (FAILURE);
	flood_fill_map(tmp, tmp->player_position.x, tmp->player_position.y);
	r = 0;
	while (r < tmp->height)
	{
		col = 0;
		while (col < tmp->width)
		{
			if (tmp->data[r][col] == INITIAL_POSITION
				|| tmp->data[r][col] == EXIT || tmp->data[r][col] == COLLECT)
				return (clean_map(tmp), FAILURE);
			col++;
		}
		r++;
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

	if (!map)
		return (FAILURE);
	initial_pos_count = components_map_counter(map, INITIAL_POSITION);
	exit_count = components_map_counter(map, EXIT);
	ground_count = components_map_counter(map, GROUND);
	wall_count = components_map_counter(map, WALL);
	if ((initial_pos_count + exit_count + ground_count + wall_count
			+ map->collect_number) < (map->width * map->height))
		return (FAILURE);
	if (map->collect_number == 0 || initial_pos_count != 1 || exit_count != 1)
		return (FAILURE);
	return (SUCCESS);
}

int	check_rectangular_map(t_map *map)
{
	int		index;
	size_t	len;

	if (!map)
		return (FAILURE);
	index = 0;
	len = ft_strlen(map->data[0]);
	while (map->data[index])
	{
		if (len != ft_strlen(map->data[index]))
			return (FAILURE);
		index++;
	}
	return (SUCCESS);
}

int	check_closed_map(t_map *map)
{
	int	row;
	int	column;

	if (!map)
		return (FAILURE);
	column = 0;
	while (column < map->width)
	{
		if (map->data[0][column] != WALL
			|| map->data[map->height - 1][column] != WALL)
			return (FAILURE);
		column++;
	}
	row = 0;
	while (row < map->height)
	{
		if (map->data[row][0] != WALL
			|| map->data[row][map->width - 1] != WALL)
			return (FAILURE);
		row++;
	}
	return (SUCCESS);
}
