# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/08 20:52:44 by alepinto          #+#    #+#              #
#    Updated: 2023/10/29 15:50:35 by alepinto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	main.c 					\
		pipex.c					\
		fd.c					\
		child.c					\
		execve.c				\
		error.c					\
		utils_lib.c				\
		get_next_line.c			\
		get_next_line_utils.c	\

OBJ = $(SRC:%.c=%.o)

####COMPILER
CC = gcc -g3
CFLAGS = -I ./ -Wall -Wextra -Werror 

CFLAGS +=  -fsanitize=address

####NAME
NAME = pipex



####RULES

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ) || true

fclean: clean
	$(RM) $(NAME)

bonus:: CFLAGS += -D BONUS=1
bonus: re

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re

