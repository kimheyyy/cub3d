# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 14:27:40 by seoklee           #+#    #+#              #
#    Updated: 2023/08/07 14:27:41 by seoklee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ./ft_isalnum.c ./ft_isalpha.c ./ft_isdigit.c ./ft_strlcat.c ./ft_strlen.c \
./ft_toupper.c ./ft_isascii.c ./ft_isprint.c ./ft_strlcpy.c ./ft_tolower.c ./ft_memset.c \
./ft_bzero.c ./ft_memcpy.c ./ft_memccpy.c ./ft_memmove.c ./ft_memchr.c ./ft_memcmp.c \
./ft_strchr.c ./ft_strrchr.c ./ft_strncmp.c ./ft_strnstr.c ./ft_strdup.c ./ft_calloc.c \
./ft_atoi.c ./ft_substr.c ./ft_strjoin.c ./ft_strtrim.c ./ft_putchar_fd.c ./ft_putstr_fd.c \
./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_itoa.c ./ft_split.c ./ft_strmapi.c

BSRCS		= ./ft_lstnew.c ./ft_lstadd_front.c ./ft_lstsize.c ./ft_lstlast.c \
./ft_lstadd_back.c ./ft_lstdelone.c ./ft_lstclear.c ./ft_lstiter.c ./ft_lstmap.c

OBJS		= $(SRCS:.c=.o)

BOBJS		= $(BSRCS:.c=.o)

CC			= gcc

CFALGS		= -Wall -Wextra -Werror

RM			= rm -f

NAME		= libft.a

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

bonus:		$(BOBJS) $(OBJS)
			ar rc $(NAME) $(OBJS) $(BOBJS)

%.o:		%.c
			$(CC) $(CFALGS) -c $< -o $@

clean:
			$(RM) $(OBJS) $(BOBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus