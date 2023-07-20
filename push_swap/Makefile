# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabdurai <dabdurai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 12:58:02 by dabdurai          #+#    #+#              #
#    Updated: 2023/02/14 16:07:23 by dabdurai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wextra -Wall -g
SRC = ./src/push_swap.c ./src/instructions.c ./src/instructions2.c ./src/ft_push1.c \
	  ./src/instructions3.c ./src/check.c ./src/push_swap_utils3.c ./src/push_swap_utils2.c \
	  ./src/push_swap_utils.c ./src/sort_functions.c


SRC_BONUS = ./bonus/checker_utils.c ./bonus/checker_utils2.c ./bonus/checker.c \
			./bonus/instructions_checker2.c ./bonus/instructions_checker3.c \
			./bonus/instructions_checker.c ./gnl/get_next_line.c \
			./gnl/get_next_line_utils.c


OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

NAME = push_swap
NAME_BONUS = checker

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME)
	clear
	@echo "\033[32mDone\033[0m"


bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	@make -C ./libft
	$(CC) $(CFLAGS) $(OBJ_BONUS) -Llibft -lft -o $(NAME_BONUS)

clean:
	@make -C ./libft clean
	@rm -rf $(OBJ) $(OBJ_BONUS)
	clear
	@echo "\033[31mBinary Removed !\033[0m"
	
fclean: clean
	@make -C ./libft fclean
	@rm -rf $(NAME) $(NAME_BONUS)
	clear
	@echo "\033[31mBinary Removed !\033[0m"

re: fclean all