/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagoma <mamagoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:03:16 by mamagoma          #+#    #+#             */
/*   Updated: 2024/11/12 20:25:41 by mamagoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*clean;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	if (s1[start] != 0)
	{
		while (s1[end] && ft_strchr(set, s1[end]))
			end--;
	}
	clean = ft_substr(s1, start, end - start + 1);
	return (clean);
}

//  int	main(void)
//  {
//  	char const *s1 = " / /*/*   Mahdi niveau haut/  // * /* / / ";
//  	char const *set = "/ *";
//  	printf("test : %s", ft_strtrim(s1, set));
//  }
