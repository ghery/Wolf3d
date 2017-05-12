# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghery <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/31 13:42:12 by ghery             #+#    #+#              #
#    Updated: 2017/02/04 11:15:06 by ghery            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export NAME	=	libft.a

export CC		=	gcc

# export FLAG = -Wall -Wextra -Werror

SRCS = ft_basic.c 

OBJECTS	= $(SRCS:.c=.o)

LIBFT = ./libft/

PRINTF = ./srcs/

all		:	$(NAME)

%.o: %.c
	@$(CC) -o $@ -c $< $(FLAG)

$(NAME) : $(OBJECTS)
			@echo "make all"
			@ar rc $@ $^
			@make -C $(LIBFT)
			@make -C $(PRINTF)
			@ranlib	$@

printf	:	$(NAME)
			@$(CC) $(FLAG) -o $@ main.c libft/libft.a libftprintf.a
clean	:	
			@echo "clean"
			@make -C $(LIBFT) clean
			@make -C $(PRINTF) clean
			@rm -f $(OBJECTS)

redo	:	re printf

fclean	:	clean
			@make -C $(LIBFT) clean
			@make -C $(PRINTF) clean
			@rm -f $(NAME)

re		:
	@make fclean && make all
