/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagoma <mamagoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:11:34 by mamagoma          #+#    #+#             */
/*   Updated: 2025/02/01 21:37:31 by mamagoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_cross(t_data *data)
{
	exit_game(data);
	exit (0);
	return (0);
}

int	hook_handler(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		exit_game(data);
		exit (0);
	}
	if (keycode == 119)
		avatar_move(data, &data->vars, &data->pos, 1);
	else if (keycode == 115)
		avatar_move(data, &data->vars, &data->pos, 2);
	else if (keycode == 100)
		avatar_move(data, &data->vars, &data->pos, 3);
	else if (keycode == 97)
		avatar_move(data, &data->vars, &data->pos, 4);
	return (0);
}
