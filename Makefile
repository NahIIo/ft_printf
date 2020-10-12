# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/05 17:18:08 by Julian            #+#    #+#              #
#    Updated: 2020/03/10 10:19:55 by jchauvet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_HEADERS = ./

DIR_SRCS = ./

DIR_LIBFT = ./libft/

LIBFT = libft.a

NAME = libftprintf.a

SRC	= ft_printf.c

OUT = a.out

MAIN = main.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJ)
				make -C $(DIR_LIBFT)
				cp $(DIR_LIBFT)$(LIBFT) ./$(NAME)
				ar rc $(NAME) $(OBJ)
				/bin/rm -f $(LIBFT)
				ranlib $(NAME)

%.o: %.c
				gcc $(FLAG) -c $< -o $@

clean:
				/bin/rm -f $(OBJ)
				make clean -C ./libft/

fclean:			clean
				/bin/rm -f $(OUT)
				/bin/rm -f $(NAME)
				make fclean -C ./libft/

re:				fclean all

.PHONY:			re fclean clean all
