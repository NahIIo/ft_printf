# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/10 10:19:31 by jchauvet          #+#    #+#              #
#    Updated: 2020/03/10 10:19:33 by jchauvet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c\
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memset.c\
	ft_putchar_fd.c ft_putendl_fd.c ft_puthexa_fd.c ft_puthexa_cap_fd.c ft_puthexa_pointer_fd.c\
	ft_putint_fd.c ft_putuint_fd.c ft_putstr_fd.c ft_split.c\
	ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
	ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c\
		ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

OBJ = $(SRC:.c=.o)

OBJBONUS = $(BONUS:.c=.o)

FLAG = -Wall -Wextra -Werror

OPTION = -c

all: $(NAME)

$(NAME):		$(OBJ)
				ar rc $(NAME) $(OBJ)
				ranlib $(NAME)

bonus :			$(OBJ) $(OBJBONUS)
				ar rc $(NAME) $(OBJ) $(OBJBONUS)
				ranlib $(NAME)

%.o: %.c
				gcc $(FLAG) -c $< -o $@

clean:
				/bin/rm -f $(OBJ) $(OBJBONUS)

fclean: clean
				/bin/rm -f $(NAME)

re: fclean all
