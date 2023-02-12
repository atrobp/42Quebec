# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atopalli <atopalli@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 15:05:30 by atopalli          #+#    #+#              #
#    Updated: 2023/02/11 22:59:22 by atopalli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = push_swap
FILES  = ft_main.c ft_validate.c ft_decision_maker.c ft_operations.c ft_small_stack.c ft_mid_stack.c ft_big_stack.c
FLAGS  = -Wall -Wextra -Werror
FILESO = $(FILES:.c=.o)

$(NAME): $(FILESO)
	$(CC) $(FLAGS) $(CFLAGS) $(FILES) -o $(NAME)

all: $(NAME)

bonus: $(BONUSFO)
	$(CC) $(BONUSF) -o $(BONUS)

clean:
	$(RM) $(FILESO) $(BONUSFO)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all
