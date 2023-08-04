CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

NAME		=	cub3d

SRCS_DIR	=	./srcs/
INCS_DIR	=	./includes/
MLX_DIR		=	./mlx/
LIB_DIR		=	./libft/
GNL_DIR		=	./gnl/

SRCS		=	$(SRCS_DIR)main.c \
				$(SRCS_DIR)init_game.c \
				$(SRCS_DIR)exit.c \
				$(SRCS_DIR)key_hook.c \
				$(SRCS_DIR)calculate.c \
				$(SRCS_DIR)draw.c \
				$(SRCS_DIR)utils.c
OBJS		=	$(SRCS:.c=.o)

MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $? -o $@

$(NAME): $(OBJS)
	make bonus -C $(LIB_DIR)
	make -C $(GNL_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L $(MLX_DIR) $(MLX_FLAGS) -L $(GNL_DIR) -lgnl -L $(LIB_DIR) -lft

clean:
	make clean -C $(LIB_DIR)
	make clean -C $(GNL_DIR)
	make clean -C $(MLX_DIR)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIB_DIR)
	make fclean -C $(GNL_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re