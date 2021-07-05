# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 12:07:25 by hyospark          #+#    #+#              #
#    Updated: 2021/07/05 23:51:12 by hyospark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CFLAGS = -Wall -Wextra -Werror
SERVER_SOURCE = servers/server.c \
				servers/utils.c
CLIENT_SOURCE = clients/client.c \
				clients/atoi.c \
				clients/itoa.c
SERVER_OUT = server
CLIENT_OUT = client
SERVER_OBJECT = server.o \
				utils.o
CLIENT_OBJECT = client.o \
				atoi.o \
				itoa.o

$(NAME): $(SERVER_OBJECT) $(CLIENT_OBJECT)
$(SERVER_OBJECT): $(SERVER_SOURCE)
	gcc $(CFLAGS) -c $(SERVER_SOURCE)
	gcc $(SERVER_SOURCE) $(CFLAGS) -o $(SERVER_OUT)
$(CLIENT_OBJECT): $(CLIENT_SOURCE)
	gcc $(CFLAGS) -c $(CLIENT_SOURCE)
	gcc $(CLIENT_SOURCE) $(CFLAGS) -o $(CLIENT_OUT)
all : $(NAME)
clean:
	@rm -f $(CLIENT_OBJECT) $(SERVER_OBJECT)
fclean: clean
	@rm -f $(NAME)
	@rm -f $(SERVER_OUT) $(CLIENT_OUT)
re:	fclean all

.PHONY: all clean fclean re
