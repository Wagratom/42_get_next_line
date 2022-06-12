/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bankai <bankai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:09:40 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/12 11:28:09 by bankai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#endif
