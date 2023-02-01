# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 22:42:07 by atopalli          #+#    #+#              #
#    Updated: 2022/08/11 20:47:02 by atopalli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

MANDATORY = ft_printf.c
MANDATORY_OBJ = $(MANDATORY:.c=.o)

$(NAME): $(MANDATORY_OBJ)
	ar rcs $(NAME) $(MANDATORY_OBJ)
all: $(NAME)
clean:
	$(RM) $(MANDATORY_OBJ)
fclean: clean
	$(RM) *.out *.a
re: flcean all
