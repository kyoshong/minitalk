# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 09:25:26 by hyospark          #+#    #+#              #
#    Updated: 2021/07/02 17:16:22 by hyospark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
CFLAGS = -Wall -Wextra -Werror
SOURCE = main.c \
		utils.c
OUT = server
OBJECT = main.o \
		utils.o

$(NAME): $(OBJECT)
	ar	rcs $(NAME) $(OBJECT)
	gcc $(MAIN) $(CFLAGS) $(LIB) -o $(OUT)
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
