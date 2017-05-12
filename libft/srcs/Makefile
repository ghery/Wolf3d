# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghery <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/31 13:59:55 by ghery             #+#    #+#              #
#    Updated: 2016/05/31 14:53:57 by ghery            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_itemgc.c	ft_printf.c ft_printf2.c ft_items.c ft_itemc.c\
			ft_itemdi.c ft_itemscglobal.c ft_special.c ft_itemdiglobal.c\
			ft_itemx_part_one.c ft_itemx_part_two.c ft_itemx_part_three.c\
			ft_itemx_part_four.c  ft_itemo_part_one.c ft_itemo_part_two.c\
			ft_itemo_part_four.c  ft_itemgx_part_one.c ft_itemgx_part_two.c\
			ft_itemgx_part_three.c ft_itemgx_part_four.c ft_itemp.c\
			ft_itemu_part_one.c ft_itemu_part_two.c ft_itemu_part_four.c\
			ft_itemdi_part_one.c ft_itemdi_part_two.c ft_itemdi_part_four.c\
			ft_itemgs.c wchar.c wchar_next.c ft_itemb_part_one.c ft_format1.c\
			ft_itemb_part_two.c ft_itemb_part_four.c ft_diese.c ft_format2.c

OBJECTS	= $(SRCS:.c=.o)

FLAG	=	-Wall -Wextra -Werror  

all		:	$(OBJECTS)
			@ar r ../$(NAME) $^

%.o: %.c
	@gcc -o $@ -c $< $(FLAG)

clean	:	
			@rm -f $(OBJECTS)

re		:
	@make clean && make all
