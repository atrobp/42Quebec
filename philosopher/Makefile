# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atopalli <atopalli@42.quebec.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 12:03:13 by atopalli          #+#    #+#              #
#    Updated: 2023/02/15 13:02:31 by atopalli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
FLAGS	=	-Wall -Wextra -Werror
GCC		=	gcc $(FLAGS) -pthread -o $(NAME)

SRC		=	ft_main.c	\
			ft_philo.c	\

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m

$(NAME): $(SRC)
	@echo "$(YELLOW)Compiling... philosopher$(NC)"
	@$(GCC) $(SRC)
	@echo "$(GREEN)Compilation done!$(NC)"

all: $(NAME)

clean:
	@rm -f $(NAME)
	@echo "$(RED)Clean done!$(NC)"

fclean: clean

re: fclean all

.PHONY: all clean fclean re
