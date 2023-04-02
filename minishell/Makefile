# **************************************************************************** #
#                                                                              #
#                                                   if(success){};             #
#    Makefile                                       ██╗  ██╗██████╗            #
#                                                   ██║  ██║╚════██╗           #
#    By: atopalli | github/atrobp                   ███████║ █████╔╝           #
#                                                   ╚════██║██╔═══╝            #
#    Created: 2023/03/30 20:57:48 by atopalli            ██║███████╗           #
#    Updated: 2023/04/02 10:33:34 by atopalli            ╚═╝╚══════╝.qc        #
#                                                                              #
# **************************************************************************** #

# Vars

PROJECT	:=	minishell
FLAGS	:=	-Wall -Werror -Wextra -Iinclude/
CC		:=	gcc $(FLAGS)
TARGET	:=	bin/$(PROJECT)

# Files folder

SRC		:=	src/
UTILS	:=	utils/

# Srcs files

# FILES	:=	$(SRC)main.c $(SRC)envp.c $(SRC)parsecmd.c $(SRC)getenv.c $(SRC)builtins.c $(SRC)execve.c $(SRC)createpath.c $(SRC)trimquotes.c
# FILES	+=	$(UTILS)strdup.c $(UTILS)split.c $(UTILS)strlen.c $(UTILS)write.c $(UTILS)strncmp.c
FILES	:=	$(SRC)main.c $(SRC)starting.c $(SRC)parsing.c $(SRC)executing.c

# Utils files

FILES	+=	$(UTILS)split.c $(UTILS)strdup.c $(UTILS)strlen.c \
			$(UTILS)strncmp.c $(UTILS)alloc.c $(UTILS)strccpy.c $(UTILS)signals.c 

# Readline

RLPATH	:=	 $(whereis libreadline.a) $(whereis libhistory.a)
RLINE	:=	 -lreadline $(RLPATH)

# Colors

RED		:=	\033[0;31m
GREEN	:=	\033[0;32m
YELLOW	:=	\033[0;33m
BLUE	:=	\033[0;34m
PURPLE	:=	\033[0;35m
CYAN	:=	\033[0;36m
WHITE	:=	\033[0;37m
RESET	:=	\033[0m

# Rules

all: $(TARGET) myprint

$(TARGET): $(FILES) 
	@$(CC) -o $@ $(FILES) $(RLINE)
	$(call compiling,$(FILES))
	@echo "$(GREEN)$(PROJECT) created$(RESET)"

clean:
	@if [ -f $(TARGET) ]; then \
		rm -rf bin/$(PROJECT); \
		echo "$(RED)$(PROJECT) deleted$(RESET)"; \
	fi

fclean: clean

re: fclean all

.PHONY: all clean fclean re myprint










# Compiling function

compiling = \
	@echo "Compiling"; \
	for i in $1; do \
		echo "$(CYAN)$$i$(RESET)"; \
		sleep 0.09; \
	done


#  amazing ascii art

myprint:
	@printf "\n\n"
	@printf "Welcome to\n"
	@printf "$(RED)%57s\n"		 "#####     #    #     #  #####  #     # ####### #       #"
	@printf "$(GREEN)%-66s\n"	"#     #   # #    #   #  #     # #     # #       #       #" 
	@printf "$(YELLOW)%-66s\n"	"#        #   #    # #   #       #     # #       #       #" 
	@printf "$(BLUE)%-66s\n"	"#  #### #     #    #     #####  ####### #####   #       #" 
	@printf "$(PURPLE)%-66s\n"	"#     # #######    #          # #     # #       #       #" 
	@printf "$(CYAN)%-66s\n"	"#     # #     #    #    #     # #     # #       #       #" 
	@printf "$(WHITE)%63s\n"	 "#####  #     #    #     #####  #     # ####### ####### #######"
	@printf "$(RED)%63s" "made with love <3"
	@printf "\n"
