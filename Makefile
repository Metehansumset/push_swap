NAME = push_swap

SRC = main.c error.c free.c check_arguements.c init_stack.c actions.c radix_sort.c \
		sort_three.c small_sort.c

LIB = libft/libft.a

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

$(LIB):
	@make -C libft/

clean:
	@make -C libft/ clean
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(LIB)

norm:
	norminette $(SRC) push_swap.h

re: fclean all