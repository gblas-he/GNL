# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/18 14:39:24 by jdiaz-ec          #+#    #+#              #
#    Updated: 2026/04/09 12:09:42 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LIB = get_next_line.a
NAME_EXEC = get_next_line

SRC_LIB = get_next_line.c get_next_line_utils.c
SRC_EXEC = get_next_line.c get_next_line_utils.c main.c

OBJS_LIB := $(SRC_LIB:%.c=%.o)
OBJS_EXEC := $(SRC_EXEC:%.c=%.o)

INCLUDE = get_next_line.h

CC = cc
CCFLAGS = -Wall -Wextra -Werror -g3 -D BUFFER_SIZE=42

AR = ar rcs
RM = rm -f

all: $(NAME_LIB) $(NAME_EXEC)

$(NAME_LIB): $(OBJS_LIB)
	$(AR) $(NAME_LIB) $(OBJS_LIB)

$(NAME_EXEC): $(OBJS_EXEC)
	$(CC) $(CCFLAGS) -o $(NAME_EXEC) $(OBJS_EXEC)

%.o: %.c $(INCLUDE)
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_LIB) $(OBJS_EXEC)

fclean: clean
	$(RM) $(NAME_LIB) $(NAME_EXEC)

re: fclean all

.PHONY: all clean fclean re