/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contain_only.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagoma <mamagoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:19:11 by mamagoma          #+#    #+#             */
/*   Updated: 2025/01/21 18:46:56 by mamagoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	contain_only(char *str)
{
	int		i;
	int		j;
	char	*autorised;

	autorised = "10PEC\n";
	i = 0;
	while (str[i])
	{
		j = 0;
		while (autorised[j])
		{
			if (str[i] == autorised[j])
				break ;
			j++;
		}
		if (!autorised[j])
			return (1);
		i++;
	}
	return (0);
}
