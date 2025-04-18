/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:55:16 by juagomez          #+#    #+#             */
/*   Updated: 2025/04/18 21:02:52 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

t_map	*initialize_map(t_map *map, char **data_map, char *filename);
int		collect_map_counter(t_map *map);
void	initialize_map_render_flags(t_map *map);
void	initialize_map_positions(t_map *map);

t_map	*load_map(char *filename)
{
	int		fd;
	char	*raw_string_map;
	char	**data_map;
	t_map	*map;

	if (!filename)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_printf(ERROR_OPEN_FILE), NULL);
	raw_string_map = ft_calloc((1280 * 1024), sizeof(char));
	if (!raw_string_map)
		return (close(fd), NULL);
	read(fd, raw_string_map, ((1280 * 1024) - 1));
	close(fd);
	data_map = ft_split(raw_string_map, '\n');
	if (!data_map)
		return (NULL);
	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (free_matrix((void **) data_map, -1), NULL);
	map = initialize_map(map, data_map, filename);
	free(raw_string_map);
	raw_string_map = NULL;
	return (map);
}

t_map	*initialize_map(t_map *map, char **data_map, char *filename)
{
	int	height;
	int	width;

	if (!map || !data_map || !filename)
		return (NULL);
	height = 0;
	while (data_map[height])
		height++;
	width = 0;
	if (data_map[0])
		width = ft_strlen(data_map[0]);
	map->filename = filename;
	map->data = data_map;
	map->width = width;
	map->height = height;
	map->width_pixels = map->width * TILE_SIZE;
	map->height_pixels = map->height * TILE_SIZE;
	map->collect_number = collect_map_counter(map);
	initialize_map_render_flags(map);
	initialize_map_positions(map);
	return (map);
}

int	collect_map_counter(t_map *map)
{
	int	collect_number;
	int	row;
	int	column;

	if (!map)
		return (FAILURE);
	collect_number = 0;
	row = 0;
	while (row < map->height)
	{
		column = 0;
		while (column < map->width)
		{
			if (map->data[row][column] == COLLECT)
				collect_number++;
			column++;
		}
		row++;
	}
	return (collect_number);
}

void	initialize_map_render_flags(t_map *map)
{
	int	row;
	int	column;

	if (!map)
		return ;
	map->render_flag = (bool **) ft_calloc(map->height + 1, sizeof(bool *));
	if (!map->render_flag)
		return ;
	row = 0;
	while (row < map->height)
	{
		map->render_flag[row] = (bool *) ft_calloc(map->width, sizeof(bool));
		if (!map->render_flag[row])
			return ;
		column = 0;
		while (column < map->width)
		{
			map->render_flag[row][column] = true;
			column++;
		}
		row++;
	}
}

void	initialize_map_positions(t_map *map)
{
	int	row;
	int	column;

	if (!map)
		return ;
	row = 0;
	while (row < map->height)
	{
		column = 0;
		while (column < map->width)
		{
			if (map->data[row][column] == INITIAL_POSITION)
			{
				map->player_position.x = column;
				map->player_position.y = row;
			}
			else if (map->data[row][column] == EXIT)
			{
				map->exit_position.x = column;
				map->exit_position.y = row;
			}
			column++;
		}
		row++;
	}
}
