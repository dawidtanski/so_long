NAME		=	so_long

MLX			=	./lib/minilibx/Makefile.gen
MLX_DIR		=	./lib/minilibx
LIBFT		=	./lib/libft/libft.a
LIBFT_DIR	=	./lib/libft
OBJ_DIR		=   ./objs

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

INC			=	-I ./include -I $(LIBFT_DIR) -I $(MLX_DIR)
LIB			=	-L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx -lX11 -lXext -lm -lz -lbsd


SRC			=	srcs/die.c \
				srcs/draw.c \
				srcs/event.c \
				srcs/game_destroy.c \
				srcs/game_init.c \
				srcs/map_height.c \
				srcs/map_init.c \
				srcs/map_isvalid.c \
				srcs/map_parsing.c \
				srcs/map_read.c \
				srcs/map_width.c \
				srcs/mlx_utils.c \
				srcs/move_player.c \
				srcs/root_destroy.c \
				srcs/root_init.c \
				srcs/so_long.c \
				srcs/update.c


OBJS		=	$(patsubst srcs/%.c, $(OBJ_DIR)/%.o, $(SRC))
# OBJS			=	$(SRC:.c=.o)

GREEN		=	\033[0;32m
RED 		=	\033[0;31m
YELLOW		=	\033[0;33m
RESET		=	\033[0m

all:		$(MLX) $(LIBFT) $(NAME)

$(NAME):	$(OBJS)
			@echo "$(RED)[ .. ] Compiling Mandatory..$(RESET)"
			@$(CC) $(FLAGS) -fsanitize=address -o $@ $^ $(LIB)
			@echo "$(GREEN)[ OK ]$(RESET) $(YELLOW)Mandatory Ready!$(RESET)"


$(OBJ_DIR)/%.o: srcs/%.c
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(FLAGS) $(INC) -o $@ -c $<


$(MLX):
			@echo "$(RED)[ .. ] | Compiling minilibx..$(RESET)"
			@make -C mlx
			@echo "$(GREEN)[ OK ]$(RESET)|$(YELLOW)Minilibx ready!$(RESET)"

$(LIBFT):
			@echo "$(RED)[ .. ] Compiling Libft..$(RESET)"
			@make -C libft
			@echo "$(GREEN)[ OK ]$(RESET) $(YELLOW)Libft ready!$(RESET)"

			$(OBJ_DIR)/%.o: srcs/%.c
			@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make clean -C $(LIBFT_DIR)
			@rm -rf $(OBJ_DIR)
			@echo "Object files removed."

# clean:		@make -s $@ -C libft
# 			@rm -rf $(OBJ_DIR) src/*.o
# 			@echo "Object files removed."

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "Binary file removed."

re:			fclean all

.PHONY:		all clean fclean re