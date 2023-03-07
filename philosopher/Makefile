# **************************************************************************** #
#                                                                              #
#                                                   if(success){};             #
#    Makefile                                       ██╗  ██╗██████╗            #
#                                                   ██║  ██║╚════██╗           #
#    By: atopalli | github/atrobp                   ███████║ █████╔╝           #
#                                                   ╚════██║██╔═══╝            #
#    Created: 2023/03/04 19:47:56 by atopalli            ██║███████╗           #
#    Updated: 2023/03/06 23:14:47 by atopalli            ╚═╝╚══════╝.qc        #
#                                                                              #
# **************************************************************************** #

# VARS
PROJECT	=	philo
GCC		=	gcc -Wall -Wextra -Werror -pthread
RM		=	rm -f

# SRCS
FILES	=	main.c init.c utils.c philo.c

# COLORS
RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
PURPLE	=	\033[0;35m
CYAN	=	\033[0;36m
WHITE	=	\033[0;37m
RESET	=	\033[0m

# RULES
all:		$(PROJECT)

$(PROJECT): $(FILES)
			@for i in $$(seq 1 20); do \
				printf "\rCompiling $(PROJECT) [$(GREEN)$$((5*i))$(RESET)]"; \
				sleep 0.023456789; \
			done
			@$(GCC) $(FILES) -o $(PROJECT)
			@echo "\r$(GREEN)$(PROJECT) compiled$(RESET)       " || echo "\r$(RED)Build failed$(RESET)          "

clean:
			@if [ -f $(PROJECT) ]; then \
				$(RM) $(PROJECT); \
				echo "$(RED)$(PROJECT) removed$(RESET)"; \
			fi

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re
