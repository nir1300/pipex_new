# Define variables
NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Paths to libft and includes
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I $(LIBFT_DIR) -I .

# Source files
SRC = main.c helpers.c
B_SRC = main_bonus.c helpers_bonus.c

OBJ = $(SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)

# Compilation rules
all: $(LIBFT_BONUS) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -g -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(OBJ) $(B_OBJ)
	$(CC) $(CFLAGS) $(B_OBJ) -g -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -g -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ) $(B_OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
