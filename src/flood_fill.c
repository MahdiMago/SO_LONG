/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagoma <mamagoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:37:01 by mamagoma          #+#    #+#             */
/*   Updated: 2025/02/02 15:03:23 by mamagoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	calcul_x(char **lines)
{
	int	x;

	if (!lines || !lines[0])
		return (0);
	x = 0;
	while (lines[0][x])
		x++;
	return (x);
}

static int	calcul_y(char **lines)
{
	int	y;

	if (!lines)
		return (0);
	y = 0;
	while (lines[y])
		y++;
	return (y);
}

void	player_pos(char **lines, t_position *pos)
{
	int	x;
	int	y;

	y = 0;
	while (lines[y])
	{
		x = 0;
		while (lines[y][x])
		{
			if (lines[y][x] == 'P')
			{
				pos->x = x;
				pos->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static int	flood_fill(char **map, int pos_x, int pos_y, t_data *data)
{
	if (pos_x < 0 || pos_x >= data->mapinfo.x_max
		|| pos_y < 0 || pos_y >= data->mapinfo.y_max)
		return (0);
	if (map[pos_y][pos_x] == '1' || map[pos_y][pos_x] == '2')
		return (0);
	if (map[pos_y][pos_x] == 'C')
		data->mapinfo.count_collectibles++;
	if (map[pos_y][pos_x] == 'E')
		data->mapinfo.check_exit = 1;
	map[pos_y][pos_x] = '2';
	flood_fill(map, pos_x + 1, pos_y, data);
	flood_fill(map, pos_x - 1, pos_y, data);
	flood_fill(map, pos_x, pos_y - 1, data);
	flood_fill(map, pos_x, pos_y + 1, data);
	if (data->mapinfo.count_collectibles == 0 || data->mapinfo.check_exit != 1)
		return (0);
	return (1);
}

int	main_check_map(char **lines, char *map, t_data *data)
{
	t_position	pos;

	data->mapinfo.count_collectibles = 0;
	data->mapinfo.check_exit = 0;
	data->mapinfo.x_max = calcul_x(lines);
	data->mapinfo.y_max = calcul_y(lines);
	player_pos(lines, &pos);
	if (flood_fill(lines, pos.x, pos.y, data) == 0
		|| is_there_collectible(map) != data->mapinfo.count_collectibles)
	{
		ft_printf("Map invalid\n");
		return (1);
	}
	return (0);
}
