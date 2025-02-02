/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagoma <mamagoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:58:46 by mamagoma          #+#    #+#             */
/*   Updated: 2025/02/01 21:29:25 by mamagoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_ber_file(char *filename)
{
	size_t	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	return (len > 4 && ft_strncmp(&filename[len - 4], ".ber", 4) != 0);
}

int	only_one_exit(char *map)
{
	if (count_char_occurrences(map, 'E') != 1)
		return (1);
	return (0);
}

int	only_one_spawn(char *map)
{
	if (count_char_occurrences(map, 'P') != 1)
		return (1);
	return (0);
}

int	is_there_collectible(char *map)
{
	return (count_char_occurrences(map, 'C'));
}

int	only_valid_caracters(char *map)
{
	if (contain_only(map) == 1)
		return (1);
	return (0);
}
