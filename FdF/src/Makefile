# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/29 15:21:20 by suju              #+#    #+#              #
#    Updated: 2025/11/29 15:21:21 by suju             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
CC		= cc
CFLAGS		= -Wall -Wextra -Werror
RM		= rm -f

MLX_DIR     	= ./minilibx-linux
LIBFT_DIR   	= ./libft
INCLUDES	= -I./includes -I$(LIBFT_DIR) -I$(MLX_DIR)

LIBFT       	= $(LIBFT_DIR)/libft.a
MLX         	= $(MLX_DIR)/libmlx.a

LDFLAGS     	= -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -L$(LIBFT_DIR) -lft

SRCS		= 
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re