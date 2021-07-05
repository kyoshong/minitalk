# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 09:25:26 by hyospark          #+#    #+#              #
#    Updated: 2021/07/04 17:47:42 by hyospark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
CFLAGS = -Wall -Wextra -Werror
SOURCE = client.c \
		itoa.c \
		atoi.c
OUT = client
OBJECT = client.o \
		itoa.o \
		atoi.o
$(NAME): $(OBJECT)
	gcc $(SOURCE) $(CFLAGS) -o $(OUT)
$(OBJECT): $(SOURCE)
	gcc $(CFLAGS) -c $(SOURCE)

all : $(NAME)
clean:
	@rm -f $(OBJECT)
fclean: clean
	@rm -f $(NAME)
	@rm -f $(OUT)
re:	fclean all

.PHONY: all clean fclean re