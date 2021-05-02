# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvuente <mvuente@student.21-school.ru      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/27 10:03:43 by mvuente           #+#    #+#              #
#    Updated: 2020/05/27 12:53:17 by mvuente          ###   ########.fr        #
#                                                                              #
# **************************************************************************** 

NAME = libft.a

SRC = ft_isdigit.c ft_strchr.c ft_strlen.c ft_strrchr.c ft_itoa.c ft_memset.c \
		ft_strjoin.c ft_memcpy.c ft_strdup.c ft_calloc.c ft_bzero.c \
		ft_strlcpy.c

OBJ = $(SRC:.c=.o)

H = libft.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $?
	ranlib $(NAME)

%.o: %.c $(H)
	gcc -Wall -Wextra -Werror -c $< -o $@ -I.

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all