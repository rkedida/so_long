# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 23:22:24 by rkedida           #+#    #+#              #
#    Updated: 2023/02/26 23:24:37 by rkedida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 

SRC			= 

HEADERS		= 

OBJ			= $(SRC:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	-@$(RM) $(OBJ)

fclean: clean
	-@$(RM) $(NAME)

re: clean all

.PHONY: re, fclean, clean, all