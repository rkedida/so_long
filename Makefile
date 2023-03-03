# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 23:22:24 by rkedida           #+#    #+#              #
#    Updated: 2023/03/03 23:34:27 by rkedida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

SRC				=	$(SRC_DIR)/main.c\
					$(SRC_DIR)/parsing.c\
					$(SRC_DIR)/error.c\
					

SRC_DIR			=	./src
MAPS_DIR		=	./maps
INC_DIR			=	./includes
TEXTURES_DIR	=	./textures
MLX_DIR			=	./libs/mlx
LIBFT_DIR		=	./libs/libft
GNL_DIR			=	./libs/get_next_line
FTPRINTF_DIR	=	./libs/ft_printf
OBJ_DIR			=	./obj

HEADERS			=	$(INC_DIR)/so_long.h\
					$(LIBFT_DIR)/libft.h\
					$(GNl_DIR)/get_next_line.h\
					$(FTPRINTF_DIR)/ft_printf.h

INCLUDES		=	-I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(FTPRINTF_DIR)

OBJ				=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

# MLX_LIB			=	$(MLX_DIR)/libmlx.a -framework OpenGL -framework AppKit
MLX_LIB			=	-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
LIBFT_LIB		=	$(LIBFT_DIR)/libft.a
GNL_LIB			=	$(GNL_DIR)/get_next_line.a
FTPRINTF_LIB	=	$(FTPRINTF_DIR)/libftprintf.a


all: libs_init $(OBJ_DIR) $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
 
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) $(LIBFT_LIB) $(GNL_LIB) $(FTPRINTF_LIB) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

libs_init:
	@make -C $(MLX_DIR) > /dev/null 2>&1
	@make -C $(LIBFT_DIR) > /dev/null 2>&1
	@make -C $(GNL_DIR) > /dev/null 2>&1
	@make -C $(FTPRINTF_DIR) > /dev/null 2>&1

clean:
	-@$(RM) $(OBJ)
	@make clean -C $(MLX_DIR)
	@make clean -C $(LIBFT_DIR) --silent
	@make clean -C $(GNL_DIR) --silent
	@make clean -C $(FTPRINTF_DIR) --silent

fclean: clean
	-@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR) --silent
	@make fclean -C $(GNL_DIR) --silent
	@make fclean -C $(FTPRINTF_DIR) --silent

re: fclean all

.PHONY: re, fclean, clean, all