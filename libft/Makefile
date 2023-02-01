NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I -nostartfiles
RM = rm -f

MAN = $(shell find . -name "*.c")
MANOBJS = $(MAN:.c=.o)

$(NAME): $(MANOBJS)
	ar rcs $(NAME) $(MANOBJS)

all: $(NAME)

clean:
	$(RM) $(MANOBJS)

fclean: clean
	$(RM) *.so *.out *.a

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(MAN)
	gcc -nostartfiles -shared -o libft.so $(MANOBJS)
