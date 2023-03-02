# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 23:22:24 by rkedida           #+#    #+#              #
#    Updated: 2023/03/02 15:33:40 by rkedida          ###   ########.fr        #
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
MLX_DIR			=	./mlx
OBJ_DIR			=	./obj

HEADERS			=	$(INC_DIR)/so_long.h\

INCLUDES		=	-I$(INC_DIR) -I$(MLX_DIR)

OBJ				=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

MLX_LIB			=	-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit


all: mlx_init $(OBJ_DIR) $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
 
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

mlx_init:
	@make -C $(MLX_DIR) --silent

clean:
	-@$(RM) $(OBJ)
	@make clean -C $(MLX_DIR) --silent

fclean: clean
	-@$(RM) $(NAME) --silent

re: fclean all

.PHONY: re, fclean, clean, all