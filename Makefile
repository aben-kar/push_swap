NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = cree_stack.c push.c reverse_rotate.c rotate.c swap.c main.c utils2_push_swap.c check_string.c utils_push_swap.c utils1_push_swap.c sort_five_number.c utils_sort_five_number.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all