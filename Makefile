NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -DGL_SILENCE_DEPRECATION -g3 -fsanitize=address
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
SRC = main.c draw.c createfilename.c frame.c keyboard.c get_next_line.c open.c draw_exit.c read_map.c key_move.c next_level.c tester4.c enemy_move.c enemy_movement.c did_loose.c 
HEADERS = so_long.h mlx.h libft.h
OBJ = $(SRC:.c=.o)

MLX_DIR = ./minilibx_opengl
MLX = $(MLX_DIR)/libft.a
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I $(LIBFT_DIR) -I $(MLX_DIR)

all: $(LIBFT) $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(MLX_DIR) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) clean -C $(MLX_DIR)

re: fclean all