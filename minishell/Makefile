# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 17:07:30 by atopalli          #+#    #+#              #
#    Updated: 2023/02/01 00:18:20 by atopalli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
MSFOLDER	= ./src/minishell/
FLAGS		= -Wall -Wextra -Werror
MSFILES		= $(MSFOLDER)ft_array_creation.c $(MSFOLDER)ft_functions.c $(MSFOLDER)ft_main.c $(MSFOLDER)ft_prompt_stuff.c
OFILES		= $(MSFILES:.c=.o)
RL_LIB		= ./include/readline/libreadline.a ./include/readline/libhistory.a -lreadline -lcurses

$(NAME): $(OFILES)
	$(CC) $(FLAGS) $(MSFILES) -o $(NAME) $(RL_LIB)

all: $(NAME)

norm:
	norminette $(MSFILES) ./include/ft_minishell.h

clean:
	$(RM) $(OFILES)
