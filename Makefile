# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 21:49:34 by oessamdi          #+#    #+#              #
#    Updated: 2022/04/25 08:34:24 by oessamdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

server = server
client = client

CC = gcc
CFLAG = -Wall -Werror -Wextra

client_src = ft_printf.c ft_atoi.c client.c
server_src = ft_printf.c server.c

client_obj = $(client_src:.c=.o)
server_obj = $(server_src:.c=.o)

$(server) : $(server_obj)
	@$(CC) $(CFLAG) $(server_obj) -o $(server)
	@echo "\033[1;32mServer is ready !"
$(client) : $(client_obj) 
	@$(CC) $(CFLAG) $(client_obj) -o $(client)
	@echo "\033[1;32mClient is ready !"

all :  $(client) $(server)

.c.o :
		@$(CC) $(CFLAG) -c $<
clean :
	@rm -rf *.o
	@echo "Removed all the .o files"
	
fclean :
	@rm -rf *.o
	@rm -rf client server
	@echo "Removed all executbles"
	
re : fclean all

.PHONY: all clean fclean re
