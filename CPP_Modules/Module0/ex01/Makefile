NAME	=	phonebook
CC		=	c++ -std=c++98
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

SRCS	= 	PhoneBook.cpp

$(NAME):	$(SRCS)
	$(CC) 	$(FLAGS) $(SRCS) -o $(NAME)

all:		$(NAME)

clean:
	$(RM) $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re
