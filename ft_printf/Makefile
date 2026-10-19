# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/10 11:54:01 by aalrofat          #+#    #+#              #
#    Updated: 2025/09/13 11:54:09 by aalrofat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c print_char.c print_string.c print_num.c print_unsignednum.c print_pointer.c print_num_lhexa.c \
		print_num_uphexa.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
