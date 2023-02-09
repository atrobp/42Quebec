# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 17:07:30 by atopalli          #+#    #+#              #
#    Updated: 2023/02/09 15:16:03 by atopalli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
MSFOLDER	=	./src/minishell/
CFLAGS		=	-Wall -Wextra -Werror
MSFILES		=  $(MSFOLDER)ft_allocations_funcs.c	$(MSFOLDER)ft_env_funcs.c	\
			   $(MSFOLDER)ft_mem_functions.c		$(MSFOLDER)ft_main.c		\
			   $(MSFOLDER)ft_command_func.c

OFILES		= 	$(MSFILES:.c=.o)
RL_LIB		= 	./include/readline/libreadline.a	./include/readline/libhistory.a -lreadline -lcurses

$(NAME): 		$(OFILES)
	$(CC)		$(CFLAGS) $(MSFILES) -o $(NAME) $(RL_LIB)

all: 			$(NAME)

norm:
	norminette $(MSFILES) ./include/ft_minishell.h

clean:
	$(RM) 		$(OFILES)

fclean: 		clean
	$(RM) 		$(NAME)

re: 			fclean all

.PHONY: 		all clean fclean re norm
