NAME	:=	phonebook
FLAGS	:=	-Wall -Wextra -Werror
CC		:=	c++ -std=c++98 $(FLAGS)

SRC		:= 	PhoneBook.cpp

$(NAME):	$(SRC)
	@$(CC) -o $(NAME) $(SRC)
	@echo "\033[0;32m[ ✔ ]\033[0m $(NAME) compiled!"

all:		$(NAME)

clean:
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		echo "\033[0;31m[ ✔ ]\033[0m $(NAME) cleaned!"; \
	fi

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re
