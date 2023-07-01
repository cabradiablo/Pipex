SRC = 	main.c 		\

OBJ = $(SRC:%.c=%.o)

####COMPILER
CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror 

CFLAGS += -fsanitize=address -g3

####NAME
NAME = pipex

####LIBS
INC_DIR = Libft
INC = -I $(INC_DIR)

####LINKER

LDFLAGS = -LLibft -lft

LDFLAGS += -g3 -fsanitize=address

####RULES

all: $(NAME)

$(NAME): $(OBJ)
	make -sC $(INC_DIR)
	$(CC) $(OBJ) $(LDFLAGS)  -o $(NAME)

clean:
	@rm  -f $(OBJ) || true
	make fclean -sC ./Libft || true

fclean: clean
	rm -rf $(NAME)

bonus: all
	-D BONUS=1

re: fclean all

.PHONY: all clean fclean re

