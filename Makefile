CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

NAME		=	cub3d

SRCS_DIR	=	./srcs/
INCS_DIR	=	./includes/
MLX_DIR		=	./mlx/

SRCS		=	$(SRCS_DIR)main.c
OBJS		=	$(SRCS:.c=.o)

MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) -L $(MLX_DIR) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $? -o $@


clean:
	make clean -C $(MLX_DIR)
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re