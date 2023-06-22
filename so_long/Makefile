# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabdurai <dabdurai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 02:24:03 by dabdurai          #+#    #+#              #
#    Updated: 2023/02/23 05:49:25 by dabdurai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders -g3 

SOURCE := main/*.c
GETNEXTLINE := get_next_line/*.c
LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/

all:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)
	clear

clean:
		rm -rf $(NAME)
fclean: clean
		make clean -C $(MINILIBX)
		rm -rf $(NAME)

re: fclean all