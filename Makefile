NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = cree_stack.c push.c reverse_rotate.c rotate.c swap.c main.c my_split.c check_string.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all