# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/18 14:39:24 by jdiaz-ec          #+#    #+#              #
#    Updated: 2026/04/01 21:00:54 by gblas-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

SRC = get_next_line.c get_next_line_utils.c

OBJS := $(SRC:%.c=%.o)
INCLUDE = get_next_line.h

CC = cc

CCFLAGS = -Wall -Wextra -Werror -g3 -D BUFFER_SIZE=100

RM = rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(INCLUDE)
	$(CC) $(CCFLAGS) -o $@ -c $<

.PHONY: clean all fclean re

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all