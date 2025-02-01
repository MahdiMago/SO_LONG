/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagoma <mamagoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:31:56 by mamagoma          #+#    #+#             */
/*   Updated: 2024/11/12 17:54:12 by mamagoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	slen;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start + len > slen)
	{
		if (start < slen)
			len = ft_strlen(s + start);
		else
			len = 0;
	}
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	while (len--)
		cpy[i++] = s[start++];
	cpy[i] = 0;
	return (cpy);
}

// int	main()
// {
// 	char const s[] = "Mahdi niveau moyen";
// 	unsigned int start = 6;
// 	size_t len = 6;

// 	printf("test : %s", ft_substr(s, start, len));

// 	return (0);
// }
