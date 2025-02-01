/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagoma <mamagoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:43:35 by mamagoma          #+#    #+#             */
/*   Updated: 2025/02/01 16:14:28 by mamagoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

Picture	define_img(t_data *data)
{
	data->pics.floor = mlx_xpm_file_to_image(data->vars.mlx, "includes/picture/floor.xpm",
			&data->pics.img_width, &data->pics.img_height);
	if (!data->pics.floor)
		return (data->pics);
	data->pics.character = mlx_xpm_file_to_image(data->vars.mlx, "includes/picture/avatar.xpm",
			&data->pics.img_width, &data->pics.img_height);
	if (!data->pics.character)
		return (data->pics);
	data->pics.exit = mlx_xpm_file_to_image(data->vars.mlx, "includes/picture/exit.xpm",
			&data->pics.img_width, &data->pics.img_height);
	if (!data->pics.exit)
		return (data->pics);
	data->pics.collectible = mlx_xpm_file_to_image(data->vars.mlx, "includes/picture/collectible.xpm",
			&data->pics.img_width, &data->pics.img_height);
	if (!data->pics.collectible)
		return (data->pics);
	data->pics.wall = mlx_xpm_file_to_image(data->vars.mlx, "includes/picture/wall.xpm",
			&data->pics.img_width, &data->pics.img_height);
	if (!data->pics.wall)
		return (data->pics);
	return (data->pics);
}

void	init_for_put_image(for_put_image *data_img)
{
	data_img->x = 0;
	data_img->y = 0;
	data_img->win_x = 0;
	data_img->win_y = 0;
}

static void	end_fonction_put_image(for_put_image *data_img)
{
	data_img->x = 0;
	data_img->win_x = 0;
	data_img->y++;
	data_img->win_y += 64;
}

static void put_image_2(t_data *data, for_put_image *data_img)
{
	while (data->vars.lines[data_img->y])
	{
		while (data->vars.lines[data_img->y][data_img->x])
		{
			if (data->vars.lines[data_img->y][data_img->x] == '1')
				mlx_put_image_to_window(data->vars.mlx, data->vars.win, data->pics.wall, data_img->win_x, data_img->win_y);
			else if (data->vars.lines[data_img->y][data_img->x] == '0')
				mlx_put_image_to_window(data->vars.mlx, data->vars.win, data->pics.floor, data_img->win_x, data_img->win_y);
			else if (data->vars.lines[data_img->y][data_img->x] == 'P')
				mlx_put_image_to_window(data->vars.mlx, data->vars.win, data->pics.floor, data_img->win_x, data_img->win_y);
			else if (data->vars.lines[data_img->y][data_img->x] == 'C')
				mlx_put_image_to_window(data->vars.mlx, data->vars.win, data->pics.collectible, data_img->win_x, data_img->win_y);
			else if (data->vars.lines[data_img->y][data_img->x] == 'E')
				mlx_put_image_to_window(data->vars.mlx, data->vars.win, data->pics.exit, data_img->win_x, data_img->win_y);
			data_img->win_x += 64;
			data_img->x++;
		}
		end_fonction_put_image(data_img);
	}
	mlx_put_image_to_window(data->vars.mlx, data->vars.win, data->pics.character, data->pos.x * 64, data->pos.y * 64);
}

int	put_image(t_data *data)
{
	init_for_put_image(&data->put_image);
	put_image_2(data, &data->put_image);
	return (0);
}

int	head_of_making(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->vars.lines[y])
		y++;
	x = ft_strlen(data->vars.lines[0]);
	if (!data->vars.mlx)
		ft_printf("Erreur d'innitialisation de mlx.\n");
	data->vars.win = mlx_new_window(data->vars.mlx, x * 64, y * 64, "SO_LONG");
	if (!data->vars.win)
		return (1);
	data->pics = define_img(data);
	if (!data->pics.character || !data->pics.floor || !data->pics.exit || !data->pics.collectible
		|| !data->pics.wall || !data->vars.win || !data->vars.mlx)
	{
		ft_printf("Erreur de creation de la map.\n");
		return (1);
	}
	player_pos(data->vars.lines, &data->pos);
	put_image(data);
	mlx_key_hook(data->vars.win, hook_handler, data);
	mlx_hook(data->vars.win, DestroyNotify, StructureNotifyMask, close_cross, data);
	mlx_loop(data->vars.mlx);
	return (0);
}
