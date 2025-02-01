/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagoma <mamagoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:27:30 by mamagoma          #+#    #+#             */
/*   Updated: 2025/02/01 16:16:15 by mamagoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int exit_game(t_data *data)
{
    if (data->vars.lines != NULL)
        free_char_array(data->vars.lines);
    if (data->vars.map != NULL)
        free(data->vars.map);
    if (data->vars.mlx)
    {
        if (data->pics.floor)
            mlx_destroy_image(data->vars.mlx, data->pics.floor);
        if (data->pics.wall)
            mlx_destroy_image(data->vars.mlx, data->pics.wall);
        if (data->pics.character)
            mlx_destroy_image(data->vars.mlx, data->pics.character);
        if (data->pics.collectible)
            mlx_destroy_image(data->vars.mlx, data->pics.collectible);
        if (data->pics.exit)
            mlx_destroy_image(data->vars.mlx, data->pics.exit);
        if (data->vars.win)
            mlx_destroy_window(data->vars.mlx, data->vars.win);
        mlx_destroy_display(data->vars.mlx);
        free(data->vars.mlx);
    }
    free(data);
    return (0);
}

void init_data(t_data *data)
{
    data->vars.mlx = NULL;
    data->vars.win = NULL;
    data->vars.map = NULL;
    data->vars.lines = NULL;
    data->pics.floor = NULL;
    data->pics.wall = NULL;
    data->pics.character = NULL;
    data->pics.collectible = NULL;
    data->pics.exit = NULL;
	data->pos.c_count = 0;
}
