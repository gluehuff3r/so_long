# MLX_PATH = ./minilibx-linux
# MLX = $(MLX_PATH)/libmlx.a


# SRC = test.c hooks.c
# OBJ = $(SRC:.c=.o)
# CFLAGS = -Wall -Wextra -Werror
# LIBS = $(MLX) -lXext -lX11

# LIBFT = /home/haabu-sa/file2/libft2.0
# all: so_long

# so_long: $(OBJ)
# 	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

# clean:
# 	rm -f $(OBJ)

# fclean: clean
# 	rm -f so_long

# re: fclean so_long

# .PHONY: all clean fclean re

NAME = so_long
CC = cc

LIBFT_DIR = /home/haabu-sa/file2/libft2.0/libft2.0
LIBFT = $(LIBFT_DIR)/libft.a

CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)

SRC = test.c hooks.c
OBJ = $(SRC:.c=.o)

MLX_PATH = ./minilibx-linux
MLX = $(MLX_PATH)/libmlx.a
MLX_FLAGS = $(MLX) -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
