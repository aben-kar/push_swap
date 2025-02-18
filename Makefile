NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC = cree_stack.c push.c reverse_rotate.c rotate.c swap.c main.c utils2_push_swap.c check_string.c utils_push_swap.c utils1_push_swap.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all