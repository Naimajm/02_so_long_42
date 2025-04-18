/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_utils_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:16:43 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/18 11:05:36 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	flood_fill_map(t_map *map, int position_x, int position_y);
t_map	*copy_struct_map(t_map *map);
int		components_map_counter(t_map *map, char component);

int	check_filename_type(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5 || ft_strncmp(filename + (len - 4), ".ber", 4) != 0)
		return (FAILURE);
	return (SUCCESS);
}

void	flood_fill_map(t_map *map, int position_x, int position_y)
{
	if (position_x < 0 || position_x >= map->width
		|| position_y < 0 || position_y >= map->height
		|| map->data[position_y][position_x] == WALL
		|| map->data[position_y][position_x] == 'X')
		return ;
	map->data[position_y][position_x] = 'X';
	flood_fill_map(map, position_x - 1, position_y);
	flood_fill_map(map, position_x + 1, position_y);
	flood_fill_map(map, position_x, position_y - 1);
	flood_fill_map(map, position_x, position_y + 1);
}

t_map	*copy_struct_map(t_map *map)
{
	t_map	*tmp;
	int		row;

	tmp = (t_map *) malloc(sizeof(t_map));
	if (!tmp)
		return (NULL);
	tmp->filename = NULL;
	tmp->height = map->height;
	tmp->width = map->width;
	tmp->player_position = map->player_position;
	tmp->render_flag = NULL;
	tmp->data = (char **) malloc(sizeof(char *) * (tmp->height + 1));
	if (!tmp->data)
		return (clean_map(tmp), NULL);
	row = 0;
	while (row < tmp->height)
	{
		tmp->data[row] = ft_strdup(map->data[row]);
		if (!tmp->data[row])
			return (clean_map(tmp), NULL);
		row++;
	}
	tmp->data[map->height] = NULL;
	return (tmp);
}

int	components_map_counter(t_map *map, char component)
{
	int	component_count;
	int	column;
	int	row;

	component_count = 0;
	row = 0;
	while (row < map->height)
	{
		column = 0;
		while (column < map->width)
		{
			if (map->data[row][column] == component)
				component_count++;
			column++;
		}
		row++;
	}
	return (component_count);
}
