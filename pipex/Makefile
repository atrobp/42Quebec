# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 12:25:27 by atopalli          #+#    #+#              #
#    Updated: 2022/12/28 13:21:36 by atopalli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = pipex
FILES = ft_pipex.c ft_main.c
FLAGS = -Wall -Wextra -Werror
OBJS  = $(FILES:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(FILES) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re: fclean all
