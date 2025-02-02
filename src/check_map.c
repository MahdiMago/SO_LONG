/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagoma <mamagoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:43:03 by mamagoma          #+#    #+#             */
/*   Updated: 2025/02/01 21:06:01 by mamagoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*read_map(const char *filename)
{
	int		fd;
	char	*map;

	map = NULL;
	if (filename == NULL)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file\n");
		return (NULL);
	}
	map = read_map_lines(fd, map);
	close(fd);
	return (map);
}

char	*read_map_lines(int fd, char *map)
{
	char	*line;
	char	*temp;

	line = get_next_line(fd);
	if (line != NULL)
	{
		map = line;
		while (1)
		{
			line = get_next_line(fd);
			if (line == NULL)
				break ;
			temp = map;
			map = ft_strjoin(temp, line);
			free(temp);
			free(line);
		}
	}
	return (map);
}

char	*verif_map(int argc, char **argv)
{
	char	*map;

	if (argc != 2)
	{
		ft_printf("Please provide exactly one argument\n");
		return (NULL);
	}
	if (is_ber_file(argv[1]))
	{
		ft_printf("The file is not a '.ber'\n");
		return (NULL);
	}
	map = read_map(argv[1]);
	if (!map)
	{
		ft_printf("No map detected or file is empty\n");
		return (NULL);
	}
	return (map);
}

int	check_file(int argc, char **argv)
{
	char	*map;

	map = verif_map(argc, argv);
	if (!map)
		return (0);
	if (is_the_map_rectangular(map) || is_the_map_enclosed(map)
		|| only_one_exit(map) || only_one_spawn(map)
		|| !is_there_collectible(map) || only_valid_caracters(map))
	{
		if (is_the_map_rectangular(map) || only_valid_caracters(map))
			return (0);
		if (is_the_map_enclosed(map))
			ft_printf("The map is not enclosed by '1'\n");
		else if (only_one_exit(map))
			ft_printf("Verify the Exit\n");
		else if (only_one_spawn(map))
			ft_printf("The map has more than one spawn point\n");
		else if (!is_there_collectible(map))
			ft_printf("The map does not contain any collectibles\n");
		free(map);
		return (0);
	}
	free(map);
	return (1);
}

int	head_of_check(int argc, char **argv, t_data *data)
{
	char	*map;
	char	**lines;

	map = verif_map(argc, argv);
	if (!map)
		return (1);
	lines = ft_split(map, '\n');
	if (!lines)
		return (1);
	if ((check_file(argc, argv) == 1)
		&& (main_check_map(lines, map, data) == 0))
	{
		ft_printf("Map is valid\n");
		free(map);
		free_char_array(lines);
		return (0);
	}
	else
	{
		free(map);
		free_char_array(lines);
		return (1);
	}
	return (0);
}
