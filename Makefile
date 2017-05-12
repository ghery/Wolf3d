# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghery <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/02 17:11:57 by ghery             #+#    #+#              #
#    Updated: 2017/01/15 11:13:30 by ghery            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

FLAG = -Wall -Wextra -Werror

SRC = wolf.c ray.c key.c draw.c rest.c map.c

O_FILE = wolf.o ray.o key.o draw.o rest.o map.o

INC = wolf.h

MLX = -lmlx -lm -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(O_FILE)
	@make -C libft
	@gcc  $(FLAG) $(MLX) -Llibft -lft -I $(INC) -o $(NAME) main.c $(O_FILE)

%.o: %.c
	@gcc $(FLAG) -c $< -I $(INC)

clean:
	rm -rf $(O_FILE) main.o

fclean: clean
	rm -rf $(NAME)
	@make -C libft/ fclean

re: clean fclean all

.PHONY: all clean fclean re
