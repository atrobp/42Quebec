FILES	=	megaphone.cpp
NAME	=	megaphone
CC		=	c++ -std=c++98
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

$(NAME): $(FILES)
	$(CC) $(FLAGS) $(FILES) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
