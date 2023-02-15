NAME	=	phonebook
FLAGS	=	-Wall -Wextra -Werror
SRC		= 	PhoneBook.cpp
CC		=	c++ -std=c++98 $(FLAGS)	-o $(NAME) $(SRC)

$(NAME):	$(SRC)
	@$(CC)
	@echo "\033[0;32m[ ✔ ]\033[0m $(NAME) compiled!"

all:		$(NAME)

clean:
	@rm -f $(NAME)
	@echo "\033[0;31m[ ✔ ]\033[0m $(NAME) cleaned!"

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re
