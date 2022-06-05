/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bankai <bankai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:08:06 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/04 23:37:45 by bankai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tot_str;
	size_t	tot_size;

	tot_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	tot_str = (char *) malloc(tot_size);
	ft_strlcpy(tot_str, s1, ft_strlen(s1) +1);
	ft_strlcat(tot_str, (char *)s2, tot_size);
	return (tot_str);
}

int	ft_strchr_edit(const char *str, int c)
{
	unsigned char	*temp;
	int				count;

	temp = (unsigned char *)str;
	c = (char)c;
	count = 0;
	while (temp[count])
	{
		if (temp[count] == c)
			return (count);
		count++;
	}
	return (0);
}

char	*check_quebra(char *str)
{
	int check;

	check = ft_strchr_edit(str, '\n');
	if (check)
		return (ft_substr(str, 0, check));
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			size_letter;

	size_letter = 1;
	if (buffer)
	{
		line = check_quebra(buffer);
		if (line)
			return (line);
	}
	buffer = (char *)malloc(BUFFER_SIZE);
	size_letter = read(fd, buffer, BUFFER_SIZE);
	return (NULL);
}

int main (int argc, char *argv[])
{
	int	fd;
	char *f = (char *)malloc(250);

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	read(fd, f, 50);
	while (f)
	{
		printf("f = %d\n", *f);
		f++;
	}
}




/* Embora o inglês George Orwell seja conhecido sobretudo por ter escrito dois clássicos da literatura, 1984 e A Revolução dos Bichos, a história de sua vida também é digna de uma grande narrativa. É essa a proposta de 1903: Orwell, biografia em quadrinhos roteirizada por Pierre Christin e desenhada por Sébastien Verdier, artista que também ilustra a edição de 1984 da DarkSide® Books.
George Orwell nasceu em Motihari, na Índia, no ano de 1903, como Eric Arthur Blair, mas ainda bebê mudou-se com a mãe para o interior da Inglaterra. No começo da juventude, estudou no prestigioso Eton College, colégio de elite onde foi aluno de Aldous Huxley. Mais tarde, viveu em vários países, e de formas diversas. Foi policial na Birmânia, cozinheiro em Paris, mendigo em Londres, acompanhou operários das minas de carvão em Wigan Pier, no norte da Inglaterra, e adotou o pseudônimo George Orwell para assinar as obras inspiradas em sua experiência de vida singular.
Durante a Guerra Civil Espanhola, entrou no campo de batalha contra os fascistas na Catalunha e quase morreu após levar um tiro na garganta; durante a Segunda Guerra Mundial, não conseguiu se alistar como soldado, e permaneceu em Londres, onde presenciou diversos bombardeios perpetrados pelos nazistas; sofreu terrivelmente com os sintomas da tuberculose. Enquanto fazia isso tudo, escreveu inúmeros ensaios, artigos, cartas, memórias, e obras ficcionais, que, em conjunto, compõem uma crítica feroz da sociedade de sua época e definem toda uma mentalidade política.
Para dar conta de narrar em quadrinhos uma história tão rica e complexa, o roteirista Pierre Christin e o artista visual Sébastien Verdier se munem de uma gigantesca pesquisa histórica e literária a respeito da obra do biografado. Assim, eles mergulharam em cartas, ensaios, diários, artigos, notícias, relatos históricos, fotografias, filmes, e principalmente na obra orwelliana, para reconstituírem não apenas os fatos mais conhecidos de sua vida e época, como também detalhes mais intimistas que o aproximam de qualquer um de nós.
Em 1903: Orwell, além dos grandes feitos do autor, descobrimos também sua afinidade pela jardinagem, seu apreço pelos pubs, a adoção do filho e as condições em que escreveu alguns de seus livros. Vários desses momentos são recheados por citações do próprio biografado, como afirma Christin no posfácio: “Por não querer parafrasear o texto de Orwell, eu o incluí sob a forma de texto datilografado sempre que possível”.
A obra conta também com ilustrações de convidados de peso: Juanjo Guarnido, Enki Bilal, Manu Larcenet, Blutch e André Juillard. Esse retrato íntimo e definitivo de um dos maiores escritores de todos os tempos é o complemento perfeito para amplificar a experiência de  */
