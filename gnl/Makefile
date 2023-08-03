SRCS		=	get_next_line.c

OBJS		= $(SRCS:.c=.o)

CC			= gcc

CFALGS		= -Wall -Wextra -Werror

RM			= rm -f

NAME		= libgnl.a

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

%.o:		%.c
			$(CC) $(CFALGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re