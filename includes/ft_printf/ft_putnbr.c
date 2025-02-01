/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagoma <mamagoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:11:07 by mamagoma          #+#    #+#             */
/*   Updated: 2024/11/18 23:11:18 by mamagoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count = ft_putstr("-2147483648");
		return (count);
	}
	else
	{
		if (n < 0)
		{
			count += ft_putchar('-');
			n = -n;
		}
		if (n >= 10)
		{
			count += ft_putnbr(n / 10);
		}
		count += ft_putchar(n % 10 + '0');
	}
	return (count);
}
