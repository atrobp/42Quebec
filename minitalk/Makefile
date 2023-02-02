# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 20:04:48 by atopalli          #+#    #+#              #
#    Updated: 2022/10/06 09:54:17 by atopalli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SERVERNAME = server
SERVERFILES = server.c
SERVER_OBJ = $(SERVERFILES:.c=.o)

CLIENTNAME = client
CLIENTFILES = client.c
CLIENT_OBJ = $(CLIENTFILES:.c=.o)


all: $(CLIENTNAME) $(SERVERNAME)

$(SERVERNAME): $(SERVER_OBJ)
$(CLIENTNAME): $(CLIENT_OBJ)

clean:
	$(RM) $(CLIENT_OBJ) $(SERVER_OBJ)

fclean: clean
	$(RM) $(SERVERNAME) $(CLIENTNAME)

re: fclean all

.phony: fclean all clean re server client