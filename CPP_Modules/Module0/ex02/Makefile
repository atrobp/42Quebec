NAME	=	Account
FLAGS	=	-Wall -Wextra -Werror
SRC		=	Account.cpp \
			Account.class.cpp \
			main.cpp
CC		=	c++ -std=c++98 $(FLAGS) -o $(NAME) $(SRC)

all: $(NAME)

# compile with colors

$(NAME):
	@$(CC)
	@echo "\033[0;32m[ ✔ ]\033[0m $(NAME) compiled"

# clean

clean:
	@rm -f $(NAME)
	@echo "\033[0;31m[ ✔ ]\033[0m $(NAME) cleaned"

# recompile

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all clean re
