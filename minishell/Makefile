# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atopalli <atopalli@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 17:07:30 by atopalli          #+#    #+#              #
#    Updated: 2023/02/16 16:20:56 by atopalli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# EXECUTABLE NAME
NAME		=	minishell

# SRCS FILES
MSFOLDER	=	./src/minishell/
MSFILES		= 	$(MSFOLDER)ft_allocations_funcs.c	\
				$(MSFOLDER)ft_env_funcs.c			\
				$(MSFOLDER)ft_mem_functions.c		\
				$(MSFOLDER)ft_main.c				\
			   	$(MSFOLDER)ft_command_func.c		\

# FLAGS AND OBJECTS FILES
# CFLAGS		=	-Wall -Wextra -Werror
OFILES		= 	$(MSFILES:.c=.o)

# colors
RED			=	\033[0;31m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
BLUE		=	\033[0;34m
PURPLE		=	\033[0;35m
CYAN		=	\033[0;36m
WHITE		=	\033[0;37m
RESET		=	\033[0m

# READLINE LIBRARY
RL_LIB		= 	./include/readline/libreadline.a	\
				./include/readline/libhistory.a		\
				-lreadline -lcurses

# COMPILATION
$(NAME): 		$(OFILES)
	@echo "$(GREEN)Compiling minishell...$(RESET)"
	@$(CC)		$(CFLAGS) $(MSFILES) -o $(NAME) $(RL_LIB)
	@echo "$(GREEN)Minishell compiled!$(RESET)"

all: 			$(NAME)

norm:
	norminette $(MSFILES) ./include/ft_minishell.h

clean:
	$(RM) 		$(OFILES)

fclean: 		clean
	$(RM) 		$(NAME)
	@echo "$(RED)Minishell deleted!$(RESET)"

re: 			fclean all

.PHONY: 		all clean fclean re norm
