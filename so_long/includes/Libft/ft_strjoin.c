/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagoma <mamagoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:49:45 by mamagoma          #+#    #+#             */
/*   Updated: 2024/11/11 19:23:50 by mamagoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*resultat;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	resultat = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (resultat == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		resultat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		resultat[i++] = s2[j++];
	resultat[i] = '\0';
	return (resultat);
}

// int	main(void)
// {
// 	const char *s1 = "Mahdi Niveau ";
// 	const char *s2 = "Moyen ou haut niveau ?";

// 	printf("resultat = %s\n", ft_strjoin(s1, s2));

// 	return 0;
// }
