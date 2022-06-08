/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bankai <bankai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:08:06 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/07 20:59:36 by bankai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check(char *str, int *index, int flg)
{
	char		*temp;

	if (!flg)
	{
		temp = str;
		str = ft_strdup(&temp[*index + 1]);
		free(temp);
		return (str);
	}
	else if (flg == 1)
	{
		*index = 0;
		while (str[*index])
		{
			if (str[*index] == '\n')
				return ("sucess");
			*index += 1;
		}
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tot_str;
	size_t	tot_size;

	tot_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	tot_str = (char *) malloc(tot_size);
	if (!tot_str)
		return (NULL);
	ft_strlcpy(tot_str, s1, ft_strlen(s1) +1);
	ft_strlcat(tot_str, (char *)s2, tot_size);
	return (tot_str);
}

int	cat_line(int fd, char	**buffer, int *index)
{
	char	*buffer2;
	char	*temp;
	int		numb;

	if (!*buffer || !*buffer[0])
		return (1);
	while (1)
	{
		buffer2 = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		numb = read(fd, buffer2, BUFFER_SIZE);
		if (numb <= 0)
		{
			free(buffer2);
			return (1);
		}
		buffer2[numb] = '\0';
		temp = *buffer;
		*buffer = ft_strjoin(temp, buffer2);
		free(temp);
		free(buffer2);
		if (check(*buffer, index, 1))
			return (0);
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	static int	index;
	static int	end;
	int			numb;

	if (end == 1 || fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (index)
		buffer = check(buffer, &index, 0);
	if (buffer == NULL)
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (*buffer && check(buffer, &index, 1))
		return (ft_substr(buffer, 0, (index + 1)));
	if (*buffer)
	{
		end = cat_line(fd, &buffer, &index);
		if (end)
			return (buffer);
		return (ft_substr(buffer, 0, (index + 1)));
	}
	numb = read(fd, buffer, BUFFER_SIZE);
	if (numb <= 0)
		return (NULL);
	buffer[numb] = '\0';
	get_next_line(fd);
	return (NULL);
}
