/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagoma <mamagoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:00:26 by mamagoma          #+#    #+#             */
/*   Updated: 2024/11/11 11:09:25 by mamagoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

//int main()
//{
//    char test[20] = "Black hello";

//    printf("avant test = %s\n", test);

//    ft_bzero(test, 5);  // Remplacer les 5 premiers caractères par des zéros

//    printf("apres test = ");

//    // Affichage de chaque caractère en hexadécimal
//    for (int i = 0; i < 20; i++) {
//        printf("\\x%02x ", (unsigned char)test[i]);
//    }
//    printf("\n");

//    return 0;
//}
