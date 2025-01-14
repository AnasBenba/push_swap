CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = instructions.c list_func.c push_swap.c
OBJ = $(SRC: .c=.o)
NAME = push_swap

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean