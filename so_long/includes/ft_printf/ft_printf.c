/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagoma <mamagoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:39:12 by mamagoma          #+#    #+#             */
/*   Updated: 2024/11/21 21:06:49 by mamagoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_com(const char *str, int i, va_list args)
{
	int	count;

	count = 0;
	if (str[i] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (str[i] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (str[i] == 'u')
		count += ft_uputnbr(va_arg(args, unsigned int));
	else if (str[i] == 'x' || str[i] == 'X')
		count += ft_puthex(va_arg(args, unsigned int), str[i] == 'X');
	else if (str[i] == '%')
		count += ft_putchar('%');
	else if (str[i] == 'p')
		count += ft_putptr(va_arg(args, void *));
	return (count);
}

static int	ft_write_and_verif(va_list args, const char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			count += ft_print_com(str, i, args);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	if (!str)
		return (-1);
	va_start(args, str);
	count = ft_write_and_verif(args, str);
	return (count);
}

// int main(int ac, char **av)
// {
// 	int c = 65237890;

// 	if (ac == 2)
// 		ft_printf("%zd");
// 	return (0);
// }
