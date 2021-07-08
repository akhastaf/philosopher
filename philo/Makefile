# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/05 13:13:37 by akhastaf          #+#    #+#              #
#    Updated: 2021/07/06 16:50:28 by akhastaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc
CFLAG = -Wall -Wextra -Werror
SRC = philo.c ./srcs/*/*.c ./srcs/*.c
NAME = philo
all : $(NAME)

$(NAME): $(SRC)
		@$(C) $(CFLAG) -g $(SRC) -o $(NAME)
debug :
		@$(C) $(CFLAG) $(SRC) -o $(NAME) -g -fsanitize=address
clean : 
		@rm -rf $(NAME) 
fclean :
		@rm -rf $(NAME)
re : fclean all
.PHONY: re fclean clean all