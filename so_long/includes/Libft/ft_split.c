/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagoma <mamagoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:30:58 by mamagoma          #+#    #+#             */
/*   Updated: 2024/11/14 21:37:37 by mamagoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int	i;
	int	flag;
	int	res;

	i = 0;
	flag = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!flag)
			{
				res++;
				flag = 1;
			}
		}
		else
			flag = 0;
		i++;
	}
	return (res);
}

static char	*fill_fonction(const char *s, int start, int end)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	while (start < end)
	{
		res[i++] = s[start++];
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		start;
	int		end;
	int		size;

	i = 0;
	start = 0;
	size = count_word(s, c);
	split = malloc(sizeof(char *) * (size + 1));
	if (!split)
		return (NULL);
	while (i < size)
	{
		while (s[start] == c && s[start])
			start++;
		end = start + 1;
		while (s[end] != c && s[end])
			end++;
		split[i] = fill_fonction(s, start, end);
		start = end + 1;
		i++;
	}
	split[i] = NULL;
	return (split);
}

// int main(void)
// {
//     char **result = ft_split("ThisIsAVeryLongWordAndAnotherOne", 'A');
//     int i = 0;
//     while (result[i])
//     {
//         printf("result[%d]: %s\n", i, result[i]);
//         free(result[i]);
//         i++;
//     }
//     free(result);
//     return 0;
// }
