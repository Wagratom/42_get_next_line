#include "get_next_line.h"

char	*read_file(int fd, char**buffer, int *index);
char	*filter_line(int fd, char **buffer, int *index);
char	*return_line(int fd, char **buffer, int *index);

char	*free_(char	**buffer, char **buffer2)
{
	if (buffer != NULL)
		free(*buffer);
	if (buffer2 != NULL)
		free(*buffer2);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			index;

	index = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char) *(BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	return (read_file(fd, &buffer, &index));
}

char	*read_file(int fd, char**buffer, int *index)
{
	char	*buffer2;
	char	*temp;
	int		n_let;

	if (**buffer == 0)
	{
		buffer2 = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer2)
			return (NULL);
		n_let = read(fd, buffer2, BUFFER_SIZE);
		if (n_let <= 0)
			return (free_(buffer, &buffer2));
		buffer2[n_let] = '\0';
		temp = *buffer;
		*buffer = ft_strjoin(*buffer, buffer2);
		free_(&temp, &buffer2);
	}
	return (filter_line(fd, buffer, index));
}

char	*filter_line(int fd, char **buffer, int *index)
{
	char	*temp;

	if (return_line(fd, buffer, index))
	{
		temp = ft_substr(*buffer, 0, (*index + 1));
		*buffer = check_line_and_up(*buffer, index, 0);
	}
	else
	{
		temp = ft_strdup(*buffer);
		free(*buffer);
	}
	return (temp);
}

char	*return_line(int fd, char **buffer, int *index)
{
	char	*buffer2;
	char	*temp;
	int		n_let;

	while (1)
	{
		if (check_line_and_up(*buffer, index, 1))
			return ("sucess");
		buffer2 = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer2)
			return (NULL);
		n_let = read(fd, buffer2, BUFFER_SIZE);
		if (n_let <= 0)
			return (free_(&buffer2, NULL));
		buffer2[n_let] = '\0';
		temp = *buffer;
		*buffer = ft_strjoin(*buffer, buffer2);
		free_(&temp, &buffer2);
	}
}
/*
int	main(void)
{
	char	*s;
	int		fd;

	fd = open("texto", O_RDONLY);
	s = get_next_line (fd);
	printf("s = %s\n", s);
	free(s);

	s = get_next_line (fd);
	printf("s = %s\n", s);
	free(s);

	s = get_next_line (fd);
	printf("s = %s\n", s);
	free(s);

	s = get_next_line (fd);
	printf("s = %s\n", s);
	free(s);

	s = get_next_line (fd);
	printf("s = %s\n", s);
	free(s);

	s = get_next_line (fd);
	printf("s = %s\n", s);
	free(s);

	s = get_next_line (fd);
	printf("s = %s\n", s);
	free(s);

	s = get_next_line (fd);
	printf("s = %s\n", s);
	free(s);

	close(fd);
	return (0);
} */
