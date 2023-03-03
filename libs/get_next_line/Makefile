# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 12:27:08 by rkedida           #+#    #+#              #
#    Updated: 2023/03/03 16:50:59 by rkedida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRCS=	get_next_line.c\
		get_next_line_utils.c\

BONUSSRC =	get_next_line_bonus.c\
			get_next_line_utils_bonus.c

OBJS=$(SRCS:.c=.o)
BONUSOBJS=$(BONUSSRC:.c=.o)

CC = cc
CFLAG = -Wall -Wextra -Werror -D BUFFER_SIZE=1024

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus : $(BONUSOBJS) $(OBJS)
	ar rc $(NAME) $(BONUSOBJS) $(OBJ)
	
%.o : %.c
	$(CC) $(CFLAG) -c $^ -o $@
clean:
	rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
