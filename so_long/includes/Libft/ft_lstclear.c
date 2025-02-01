/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagoma <mamagoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:42:11 by mamagoma          #+#    #+#             */
/*   Updated: 2024/11/14 21:33:10 by mamagoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tempo;

	if (*lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		tempo = (*lst)-> next;
		del((*lst)-> content);
		free(*lst);
		*lst = tempo;
	}
	*lst = NULL;
}
