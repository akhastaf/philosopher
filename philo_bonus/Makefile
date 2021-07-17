# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 17:19:24 by akhastaf          #+#    #+#              #
#    Updated: 2021/07/14 17:20:08 by akhastaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc
CFLAG = -Wall -Wextra -Werror
SRC = philo_bonus.c ./srcs/*/*.c ./srcs/*.c
NAME = philo_bonus
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