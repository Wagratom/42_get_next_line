/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bankai <bankai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 03:33:23 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/07 21:50:22 by bankai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_dest;
	size_t	s_src;
	size_t	i;

	s_dest = ft_strlen(dst);
	if (size <= s_dest)
		return (ft_strlen(src) + size);
	size -= s_dest + 1;
	i = -1;
	while (++i < size && src[i])
		dst[s_dest + i] = src[i];
	dst[s_dest + i] = '\0';
	s_src = ft_strlen(src);
	return (s_src + s_dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	s_src;
	size_t	count;

	count = -1;
	s_src = ft_strlen(src);
	if (!size || !src)
		return (s_src);
	while (src[++count] && count < size -1)
		dst[count] = src[count];
	dst[count] = '\0';
	return (s_src);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_str;
	unsigned int	end_str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	end_str = ft_strlen(&s[start]);
	if (end_str <= len)
		sub_str = (char *) malloc(end_str + 1);
	else
		sub_str = (char *) malloc (len + 1);
	if (sub_str == NULL)
		return (NULL);
	ft_strlcpy(sub_str, &s[start], len + 1);
	return (sub_str);
}

char	*ft_strdup(const char *s)
{
	char	*cpy;
	char	*src;
	size_t	i;

	src = (char *)s;
	cpy = (char *) malloc(ft_strlen(s) + 1);
	if (cpy == NULL)
		return (NULL);
	i = -1;
	while (src[++i])
		cpy[i] = src[i];
	cpy[i] = '\0';
	return (cpy);
}
