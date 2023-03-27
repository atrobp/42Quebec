NAME	:=	megaphone
CC		:=	c++ -std=c++98 -Wall -Wextra -Werror

$(NAME): $(NAME).cpp
	$(CC) $(NAME).cpp -o $(NAME)

all: $(NAME)

clean:
	@if [ -f $(NAME) ]; then \
    	rm -r $(NAME); \
	fi

fclean: clean

re: fclean all

.PHONY: all clean fclean re
