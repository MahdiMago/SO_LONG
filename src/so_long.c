/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagoma <mamagoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:50:26 by mamagoma          #+#    #+#             */
/*   Updated: 2025/02/01 16:16:38 by mamagoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**copy_lines_of_map(char *map)
{
	char	**lines;

	lines = ft_split(map, '\n');
	if (!lines)
		ft_printf("Error in copy of lines.");
	return (lines);
}

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	all_file_verif(t_data *data, int  argc, char **argv)
{
	if (head_of_check(argc, argv, data) == 1)
	{
		ft_printf("Error !\n");
		return (0);
	}
	data->vars.map = verif_map(argc, argv);
	if (!data->vars.map)
	{
		ft_printf("Map is NULL\n");
		return (0);
	}
	data->vars.lines = copy_lines_of_map(data->vars.map);
	if (!data->vars.lines)
		return(0);
	data->pos.move_count = 0;
	data->vars.test = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		ft_printf("Error: Memory allocation failed\n");
		return (1);
	}
	init_data(data);
	if (all_file_verif(data, argc, argv) == 0)
	{
		free(data);
		return (0);
	}
	else
		ft_printf("All tests passed !\n");
	data->vars.mlx = mlx_init();
	if (!data->vars.mlx)
	{
		printf("Erreur d'initialisation de data->vars.\n");
		return 1;
	}
	head_of_making(data);
	return (0);
}
