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

NAME = libftprintf.a
LIBFT = libft.a

SRC =   ft_printf.c prcnt_counter.c prcnt_printer.c ft_parser.c \
		handler.c c_handler.c initial.c my_putstr.c ft_unsign_itoa.c \
		ft_unsign_hextoa.c s_handler.c di_handler.c u_handler.c \
		hex_handler.c p_handler.c flag_parser.c width_parser.c spec_parser.c \
		precision_parser.c basic_printer.c string_construct.c \
		ft_long_hextoa.c prcnt_handler.c string_construct_string.c \
		multiputstr.c string_construct_char.c neg_precision.c

SRC_LIB_DIR = libft/

OBJ = $(SRC:.c=.o)

PRINT_H = ft_printf.h
LIB_H = libft.h

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(SRC_LIB_DIR)
	cp $(SRC_LIB_DIR)$(LIBFT) .
	mv $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME) 

%.o: %.c  $(PRINT_H) $(LIB_H)
	gcc -Wall -Wextra -Werror -c $< -o $@ -I .

clean:
	rm -f $(OBJ)
	@make -C $(SRC_LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(SRC_LIB_DIR) fclean

re: fclean all