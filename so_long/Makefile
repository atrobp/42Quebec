# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/25 10:32:49 by atopalli          #+#    #+#              #
#    Updated: 2023/01/26 10:32:51 by atopalli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = so_long
FLAGS  = -Wall -Werror -Wextra
FILES  = ft_main.c ft_mini_gnl.c ft_game.c ft_hook_imgs.c
OFILES = $(FILES:.c=.o)

$(NAME): $(OFILES)
	$(CC) $(FLAGS) $(FILES) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OFILES)

fclean:
	$(RM) $(OFILES) $(NAME)

norm:
	norminette $(FILES) ft_so_long.h

re: fclean all

.phony: so_long all clean fclean norm re
