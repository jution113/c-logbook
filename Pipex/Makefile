# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/09 01:03:04 by suju              #+#    #+#              #
#    Updated: 2025/08/09 22:04:50 by suju             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
CC		= cc
CFLAGS		= -Wall -Werror -Wextra
SRC		= srcs/pipex.c srcs/utils.c
OBJ		= ${SRC:.c=.o}

HEADER_DIR	= includes
HEADER_FLAGS	= -I$(HEADER_DIR)

LIBFT_DIR	= Libft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER_FLAGS) -c $< -o $@ -I $(LIBFT_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
