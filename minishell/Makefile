# **************************************************************************** #
#                                                                              #
#                                                   if(success){};             #
#    Makefile                                       ██╗  ██╗██████╗            #
#                                                   ██║  ██║╚════██╗           #
#    By: atopalli | github/atrobp                   ███████║ █████╔╝           #
#                                                   ╚════██║██╔═══╝            #
#    Created: 2023/03/30 20:57:48 by atopalli            ██║███████╗           #
#    Updated: 2023/04/04 10:39:29 by atopalli            ╚═╝╚══════╝.qc        #
#                                                                              #
# **************************************************************************** #

# Vars

PROJECT	:=	minishell
FLAGS	:=	-Wall -Werror -Wextra -Iinclude/
CC		:=	gcc $(FLAGS)
TARGET	:=	bin/$(PROJECT)

# Files folder

SRC		:=	src/
PARSE	:=	utils/parsing/
LIB		:=	utils/libft/

# Srcs files

FILES	:=	$(SRC)main.c $(SRC)starting.c $(SRC)parsing.c $(SRC)executing.c

# Parse files

FILES	+= $(PARSE)cmds.c $(PARSE)token.c

# Lib files

FILES	+=	$(LIB)split.c $(LIB)strdup.c $(LIB)strlen.c $(LIB)strncmp.c \
			$(LIB)alloc.c $(LIB)strccpy.c $(LIB)signals.c $(LIB)free.c \
			

# Readline

RLPATH	:=	 $(whereis libreadline.a) $(whereis libhistory.a)
RLINE	:=	 -lreadline $(RLPATH)

# Rules

all: $(TARGET)

$(TARGET): $(FILES) 
	@$(CC) -o $@ $(FILES) $(RLINE)
	$(call compiling,$(FILES))
	@echo "$(GREEN)$(PROJECT) created$(RESET)"
	@$(MAKE) -s myprint

clean:
	@if [ -f $(TARGET) ]; then \
		rm -rf bin/$(PROJECT); \
		echo "$(RED)$(PROJECT) deleted$(RESET)"; \
	fi

fclean: clean

re: fclean all

.phony: all clean fclean re myprint








# Colors

RED		:=	\033[1;31m
GREEN	:=	\033[1;32m
YELLOW	:=	\033[1;33m
BLUE	:=	\033[1;34m
PURPLE	:=	\033[1;35m
CYAN	:=	\033[1;36m
WHITE	:=	\033[1;37m
RESET	:=	\033[0m


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
	@printf "$(WHITE)Welcome to\n"
	@printf "$(RED)%57s\n"		"╔═══╗╔═══╗╔╗  ╔╗╔═══╗╔╗ ╔╗╔═══╗╔╗   ╔╗"
	@printf "$(YELLOW)%-66s\n"	"║╔═╗║║╔═╗║║╚╗╔╝║║╔═╗║║║ ║║║╔══╝║║   ║║" 
	@printf "$(YELLOW)%-66s\n"	"║║ ╚╝║║ ║║╚╗╚╝╔╝║╚══╗║╚═╝║║╚══╗║║   ║║" 
	@printf "$(GREEN)%-66s\n"	"║║╔═╗║╚═╝║ ╚╗╔╝ ╚══╗║║╔═╗║║╔══╝║║ ╔╗║║ ╔╗" 
	@printf "$(BLUE)%-66s\n"	"║╚╩═║║╔═╗║  ║║  ║╚═╝║║║ ║║║╚══╗║╚═╝║║╚═╝║" 
	@printf "$(PURPLE)%-66s\n"	"╚═══╝╚╝ ╚╝  ╚╝  ╚═══╝╚╝ ╚╝╚═══╝╚═══╝╚═══╝" 
	@printf "$(WHITE)%41s" "made with love <3"
	@printf "\n"
