NAME	=	Account
FLAGS	=	-Wall -Wextra -Werror -std=c++98
FLAGS	=	-std=c++98
CC		=	c++ $(FLAGS)

SRC		=	tests.cpp Account.cpp

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) -o $(NAME) $(SRC)
	@echo "\033[0;32m[ ✔ ]\033[0m $(NAME) compiled"

# clean

clean:
	@if [ -f $(NAME) ]; then	\
		rm -f $(NAME); 			\
		echo "\033[0;31m[ ✔ ]\033[0m $(NAME) cleaned!"; \
	fi


fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all clean re
