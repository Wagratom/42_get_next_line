# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 19:52:03 by wwallas-          #+#    #+#              #
#    Updated: 2022/06/05 04:16:30 by wwallas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_SOURCS		=	get_next_line.c get_next_line_ultils.c

H_SORCS			=	get_next_line.h

OBJS			=	$(C_SOURCS:.c=.o)

CC 				=	cc
CFLAGS			+= 	-Wall -Wextra -Werror -D BUFFER_SIZE=42

RM				=	rm -f
NAME			=	a
		
.c.o:
		$(CC) $(CFLAGS) $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(H_SORCS)
		ar rcs $@ $^

all:	$(NAME);

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re: fclean all

.PHONEY:  .c.o all clean fclean re