/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagoma <mamagoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:05:45 by mamagoma          #+#    #+#             */
/*   Updated: 2024/11/14 21:03:37 by mamagoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	if (s1 > s2)
	{
		s1 += n;
		s2 += n;
		while (n--)
		{
			*--s1 = *--s2;
		}
	}
	else
	{
		while (n--)
		{
			*s1++ = *s2++;
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	char s3[] = "hellooo";
// 	char s4[] = "Saluuttt";
// 	printf("avant memmove : %s\n", s3);
// 	ft_memmove(s3, s4, 4);
// 	printf("apres memmove : %s\n", s3);

// 	return (0);
// }
