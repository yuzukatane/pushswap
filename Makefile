NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
CC = gcc
SRCS = main.c push_swap.c utils.c
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	$(CC) $(SRCS) $(LIBFT) -o $(NAME)

clean:
	make -C $(LIBFT_DIR) clean

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

.PHONY: all clean fclean re
