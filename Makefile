# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgreater <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/10 14:35:16 by rgreater          #+#    #+#              #
#    Updated: 2021/01/09 20:20:41 by rgreater         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc
FLAGS =		-Wall -Wextra -Werror
HEADER =	ft_printf.h ft_printf_utils.h
NAME =		libftprintf.a
SRCS =		ft_printf.c \
			fmt_process.c \
			itoa.c \
			flags.c \
			parse.c \
			str_utils.c \
			str_format.c \
			write.c

OBJS =		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

%.o:		%.c $(HEADER)
			$(CC) $(FLAGS) -c $<

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
