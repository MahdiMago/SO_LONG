/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagoma <mamagoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:28:18 by mamagoma          #+#    #+#             */
/*   Updated: 2025/02/02 14:58:06 by mamagoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_the_map_rectangular(char *map)
{
	int		i;
	char	**lines;

	i = 0;
	lines = ft_split(map, '\n');
	if (!lines)
		return (0);
	while (lines[i])
	{
		if (ft_strlen(lines[i]) != ft_strlen(lines[0]))
		{
			free_char_array(lines);
			return (1);
		}
		i++;
	}
	free_char_array(lines);
	return (0);
}

int	is_the_map_enclosed(char *map)
{
	char	**lines;
	int		i;
	int		len;

	lines = ft_split(map, '\n');
	if (!lines)
		return (1);
	len = ft_strlen(lines[0]) - 1;
	i = 0;
	while (lines[i])
	{
		if (lines[i][0] != '1' && lines[i][len] != '1')
		{
			free_char_array(lines);
			return (1);
		}
		i++;
	}
	if (ft_only_char(lines[i - 1], '1') != 0
		|| ft_only_char(lines[0], '1') != 0)
	{
		free_char_array(lines);
		return (1);
	}
	return (free_char_array(lines), 0);
}

void	init_for_put_image(t_put_image *data_img)
{
	data_img->x = 0;
	data_img->y = 0;
	data_img->win_x = 0;
	data_img->win_y = 0;
}

void	end_fonction_put_image(t_put_image *data_img)
{
	data_img->x = 0;
	data_img->win_x = 0;
	data_img->y++;
	data_img->win_y += 64;
}
