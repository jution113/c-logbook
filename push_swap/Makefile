# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/27 12:39:03 by suju              #+#    #+#              #
#    Updated: 2025/11/27 12:39:08 by suju             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC		= cc
CFLAGS		= -Wall -Werror -Wextra
SRC		= push_swap.c \
			stack_util.c \
			parsing/parsing.c \
			parsing/parsing_util.c \
              		operations/push.c \
              		operations/swap.c \
              		operations/rotate.c \
	        	operations/reverse_rotate.c \
              		sort/sort.c \
 	        	sort/sort_move.c \
        		sort/sort_util.c
OBJ		= ${SRC:.c=.o}

INCLUDES	= -I./includes

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
