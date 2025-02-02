/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avatar_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagoma <mamagoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:00:09 by mamagoma          #+#    #+#             */
/*   Updated: 2025/02/02 15:03:08 by mamagoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	avatar_move(t_data *data, t_vars *vars, t_position *pos, int direction)
{
	if (!data || !vars || !pos || !vars->lines)
		return (-1);
	if (direction == 1 || direction == 2)
		avatar_move_vertical(data, direction);
	else if (direction == 3 || direction == 4)
		avatar_move_horizontal(data, direction);
	if (vars->lines[pos->y][pos->x] == 'E'
		&& data->mapinfo.count_collectibles == pos->c_count)
	{
		ft_printf("!!!!!!!!!	SUCCESS	!!!!!!!!!\n");
		exit_game(data);
		close_window(&data->vars);
	}
	if (vars->test != data->pos.move_count)
	{
		++vars->test;
		ft_printf("Counter of movements: %d\n", vars->test);
	}
	put_image(data);
	return (0);
}

void	avatar_move_vertical(t_data *data, int direction)
{
	int		new_y;

	if (direction == 1)
		new_y = data->pos.y - 1;
	else
		new_y = data->pos.y + 1;
	if (data->vars.lines[new_y][data->pos.x] != '1')
	{
		if (data->vars.lines[new_y][data->pos.x] == 'C')
		{
			data->vars.lines[new_y][data->pos.x] = '0';
			data->pos.c_count++;
		}
		data->pos.move_count++;
		data->pos.y = new_y;
	}
}

void	avatar_move_horizontal(t_data *data, int direction)
{
	int		new_x;

	if (direction == 3)
		new_x = data->pos.x + 1;
	else
		new_x = data->pos.x - 1;
	if (data->vars.lines[data->pos.y][new_x] != '1')
	{
		if (data->vars.lines[data->pos.y][new_x] == 'C')
		{
			data->vars.lines[data->pos.y][new_x] = '0';
			data->pos.c_count++;
		}
		data->pos.move_count++;
		data->pos.x = new_x;
	}
}
