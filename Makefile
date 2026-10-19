# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/15 12:42:30 by aalrofat          #+#    #+#              #
#    Updated: 2025/12/18 12:14:38 by aalrofat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = so_long.c map.c map_check.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c image.c\
		draw_map.c key_and_close_hook.c validate_path.c check_map_format.c
OBJ = $(SRC:.c=.o)
FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
MLX_D = minilibx-linux
MLX = $(MLX_D)/libmlx.a
INCLUDE = -I . -I $(MLX_D) -I get_next_line -I $(FT_PRINTF_DIR) 
MLX_LIBS = -L $(MLX_D) -lmlx -lXext -lX11
NAME = so_long

all : $(MLX) $(FT_PRINTF) $(NAME)

$(FT_PRINTF) :
	make -C $(FT_PRINTF_DIR)

$(MLX) :
	make -C $(MLX_D)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF) $(MLX_LIBS) -o $(NAME)

clean :
	rm -f $(OBJ)
	make -C $(FT_PRINTF_DIR) clean
	make -C $(MLX_D) clean

fclean : clean
	rm -f $(NAME)
	make -C $(FT_PRINTF_DIR) fclean

re : fclean all

.PHONY : all clean fclean re
 
