#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

char	*read_file(int fd, char **backup);

int	check_line(char **str)
{
	int	i;

	i = -1;
	while ((*str)[++i])
	{
		if ((*str)[i] == '\n')
			return (1);
	}
	return (0);
}

char	*find_line(char	**str)
{
	char	*temp;
	char	*line;
	int		i;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i])
		i++;
	temp = (*str);
	line = ft_substr(temp, 0, (i + 1));
	if (!temp[i + 1])
	{
		free(*str);
		(*str) = NULL;
	}
	else
	{
		(*str) = ft_strdup(&temp[i + 1]);
		free(temp);
	}
	return (line);
}

char	*check_backup(char **backup, char **buffer)
{
	char	*line;

	if (!(*backup)[0])
	{
		free(*backup);
		free(*buffer);
		return (NULL);
	}
	line = ft_strdup(*backup);
	free(*backup);
	(*backup) = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	int			i;

	i = -1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!backup)
	{
		backup = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!backup)
			return (NULL);
		while (i++ < BUFFER_SIZE)
			backup[i] = 0;
	}
	return (read_file(fd, &backup));
}

char	*read_file(int fd, char **backup)
{
	char	*buffer;
	char	*temp;
	int		n_let;

	while (1)
	{
		if (check_line(backup))
			return (find_line(backup));
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		n_let = read(fd, buffer, BUFFER_SIZE);
		if (n_let == -1)
			return (NULL);
		if (n_let == 0)
			return (check_backup(backup, &buffer));
		buffer[n_let] = '\0';
		temp = (*backup);
		*backup = ft_strjoin(*backup, buffer);
		free(temp);
		free(buffer);
	}
	return (NULL);
}

/*
int	main(void)
{
	int		fd;
	char	*s;

	fd = open("texto", O_RDONLY);
	s = get_next_line(fd);
	printf("s = %s\n", s);
	free(s);

	s = get_next_line(fd);
	printf("s = %s\n", s);
	free(s);

	s = get_next_line(fd);
	printf("s = %s\n", s);
	free(s);

	s = get_next_line(fd);
	printf("s = %s\n", s);
	free(s);

	s = get_next_line(fd);
	printf("s = %s\n", s);
	free(s);

	s = get_next_line(fd);
	printf("s = %s\n", s);
	free(s);

	s = get_next_line(fd);
	printf("s = %s\n", s);
	free(s);

	s = get_next_line(fd);
	printf("s = %s\n", s);
	free(s);

	s = get_next_line(fd);
	printf("s = %s\n", s);
	free(s);

	s = get_next_line(fd);
	printf("s = %s\n", s);
	free(s);

	s = get_next_line(fd);
	printf("s = %s\n", s);
	free(s);
	close(fd);
}
 */
