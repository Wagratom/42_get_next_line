/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bankai <bankai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:08:06 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/08 01:47:43 by bankai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*check_and_avanc(char *str, int *index, int flg)
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
		while (str[*index])
		{
			if (str[*index] == '\n')
				return ("sucess");
			*index += 1;
		}
	}
	return (NULL);
}

int	first_line(int fd, char **buffer, int *index);
int	complete_line(int fd, char **buffer, int *index);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			index;

	index = 0;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer == NULL)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
	}
	if (first_line(fd, &buffer, &index))
	{
		line = ft_substr(buffer, 0, (index + 1));
		buffer = check_and_avanc(buffer, &index, 0);
		return (line);
	}
	return (buffer);
}

int	first_line(int fd, char **buffer, int *index)
{
	char	temp;
	int		numb;

	printf("****CHEGUEI BUFFER***** = %s\n\n", *buffer);
	if (**buffer)
	{
		printf("entrei line 83\n");
		return (complete_line(fd, buffer, index));
	}
	numb = read(fd, *buffer, BUFFER_SIZE);
	if (numb <= 0)
	{
		buffer = NULL;
		return (0);
	}
	buffer[numb] = '\0';
	return (complete_line(fd, buffer, index));
}

int	complete_line(int fd, char **buffer, int *index)
{
	char	*buffer2;
	char	*temp;
	int		n_letter;

	if (check_and_avanc(*buffer, index, 1))
		return (1);
	printf("----line 127\n\n");
	while (1)
	{
		buffer2 = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer2)
		{
			buffer = NULL;
			return (0);
		}
		n_letter = read(fd, buffer2, BUFFER_SIZE);
		if (n_letter <= 0)
		{
			printf("-------------line 122\n");
			return(0);
		}
		buffer2[n_letter] = '\0';
		temp = *buffer;
		*buffer = ft_strjoin(*buffer, buffer2);
		free(temp);
		free(buffer2);
		if (check_and_avanc(*buffer, index, 1))
			return (1);
	}
}
int main(void)
{
	char	*s;
	int fd;

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
}

/* Embora o inglês George Orwell seja conhecido sobretudo por ter escrito dois clássicos da literatura, 1984 e A Revolução dos Bichos, a história de sua vida também é digna de uma grande narrativa. É essa a proposta de 1903: Orwell, biografia em quadrinhos roteirizada por Pierre Christin e desenhada por Sébastien Verdier, artista que também ilustra a edição de 1984 da DarkSide® Books.
George Orwell nasceu em Motihari, na Índia, no ano de 1903, como Eric Arthur Blair, mas ainda bebê mudou-se com a mãe para o interior da Inglaterra. No começo da juventude, estudou no prestigioso Eton College, colégio de elite onde foi aluno de Aldous Huxley. Mais tarde, viveu em vários países, e de formas diversas. Foi policial na Birmânia, cozinheiro em Paris, mendigo em Londres, acompanhou operários das minas de carvão em Wigan Pier, no norte da Inglaterra, e adotou o pseudônimo George Orwell para assinar as obras inspiradas em sua experiência de vida singular.
Durante a Guerra Civil Espanhola, entrou no campo de batalha contra os fascistas na Catalunha e quase morreu após levar um tiro na garganta; durante a Segunda Guerra Mundial, não conseguiu se alistar como soldado, e permaneceu em Londres, onde presenciou diversos bombardeios perpetrados pelos nazistas; sofreu terrivelmente com os sintomas da tuberculose. Enquanto fazia isso tudo, escreveu inúmeros ensaios, artigos, cartas, memórias, e obras ficcionais, que, em conjunto, compõem uma crítica feroz da sociedade de sua época e definem toda uma mentalidade política.
Para dar conta de narrar em quadrinhos uma história tão rica e complexa, o roteirista Pierre Christin e o artista visual Sébastien Verdier se munem de uma gigantesca pesquisa histórica e literária a respeito da obra do biografado. Assim, eles mergulharam em cartas, ensaios, diários, artigos, notícias, relatos históricos, fotografias, filmes, e principalmente na obra orwelliana, para reconstituírem não apenas os fatos mais conhecidos de sua vida e época, como também detalhes mais intimistas que o aproximam de qualquer um de nós.
Em 1903: Orwell, além dos grandes feitos do autor, descobrimos também sua afinidade pela jardinagem, seu apreço pelos pubs, a adoção do filho e as condições em que escreveu alguns de seus livros. Vários desses momentos são recheados por citações do próprio biografado, como afirma Christin no posfácio: “Por não querer parafrasear o texto de Orwell, eu o incluí sob a forma de texto datilografado sempre que possível”.
A obra conta também com ilustrações de convidados de peso: Juanjo Guarnido, Enki Bilal, Manu Larcenet, Blutch e André Juillard. Esse retrato íntimo e definitivo de um dos maiores escritores de todos os tempos é o complemento perfeito para amplificar a experiência de
 */
