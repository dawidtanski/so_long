# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 10:26:52 by dtanski           #+#    #+#              #
#    Updated: 2024/11/22 11:19:32 by dtanski          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_DIR	=./srcs
INC_DIR	=./include

LIBFT_DIR = ./lib/libft
LIBFT = ./lib/libft/libft.a

MLX_DIR = ./lib/minilibx-linux

CC = gcc
DEPFLAGS = -MP -MD
CFLAGS = -Wall -Wextra -Werror -g $(DEPFLAGS)

INC			=	-I ./inc -I $(LIBFT_DIR) -I $(MLX_DIR)
LIB			=	-L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx_Linux -lX11 -lXext -lm -lz -lbsd

SRC			= 	$(wildcard $(SRC_DIR)/*.c)
OBJ			=	$(SRC:.c=.o)

#TEXT COLORSS
GREEN		=	\033[0;32m
RED 		=	\033[0;31m
YELLOW		=	\033[0;33m
RESET		=	\033[0m

all: $(NAME)

$(NAME):$(LIBFT) $(OBJ)
		@echo "$(RED)[ .. ] Compiling Mandatory..$(RESET)"
		@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIB) -o $@
		@echo "$(GREEN)[ OK ]$(RESET) $(YELLOW)Mandatory Ready!$(RESET)"

$(OBJ): $(SRC_DIR)/%.o: $(SRC_DIR)/%.c
		@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(MLX):
		@echo "$(RED)[ .. ] | Compiling minilibx..$(RESET)"
		@make -C $(MLX_DIR)
		@echo "$(GREEN)[ OK ]$(RESET)|$(YELLOW)Minilibx ready!$(RESET)"

$(LIBFT):
		@echo "$(RED)[ .. ] Compiling Libft..$(RESET)"
		@make -C $(LIBFT_DIR)
		@echo "$(GREEN)[ OK ]$(RESET) $(YELLOW)Libft ready!$(RESET)"

clean: 
		@make clean -C $(LIBFT_DIR)
		@rm -rf $(OBJ)
		@rm -rf $(SRC_DIR)/*.d
		@echo "Object files removed"

fclean: clean
		@make -s $@ -C $(LIBFT_DIR)
		@rm -rf $(NAME)
		@echo "Binary files removed"

re:		fclean all

.PHONY:	all clean fclean re
