/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagoma <mamagoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:55:12 by mamagoma          #+#    #+#             */
/*   Updated: 2024/12/22 21:55:04 by mamagoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen_g(const char *str);
char	*ft_strdup_g(const char *str);
char	*ft_strjoin_g(const char *s1, const char *s2);
char	*ft_substr_g(const char *str, int start, int len);
int		ft_strchr_g(const char *str, char c);

#endif
