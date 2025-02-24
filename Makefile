NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c pushing_stack_b_utils.c sort_stack_a_utils.c stack_init.c parser.c push.c reverse_rotate.c rotate.c swap.c sort_five.c push_swap_utils.c push_swap_helpers.c push_swap_extra.c sort_utils.c main.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all