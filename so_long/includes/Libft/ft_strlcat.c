/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagoma <mamagoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:19:18 by mamagoma          #+#    #+#             */
/*   Updated: 2024/11/16 13:39:29 by mamagoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size <= len_dest)
	{
		return (size + len_src);
	}
	while (src[i] && len_dest + 1 < size)
	{
		dest[len_dest++] = src[i++];
	}
	dest[len_dest] = '\0';
	return (ft_strlen(src + i) + len_dest);
}

// int	main(void)
// {
// 	char dest[] = "Mahdi";
// 	const char src[] = "GoLa";

// 	printf("%zu", ft_strlcat(dest, src, 10));
// 	// ft_strlcat(dest, src, 3);
// 	printf("\n%s", dest);
// }
