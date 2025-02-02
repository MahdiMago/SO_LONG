/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_char_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagoma <mamagoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:06:04 by mamagoma          #+#    #+#             */
/*   Updated: 2025/02/02 15:06:01 by mamagoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_char_array(char **array)
{
	int	i;

	i = 0;
	if (array != NULL)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}
