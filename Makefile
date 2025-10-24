# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafaoliv <rafaoliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 17:12:54 by rafaoliv          #+#    #+#              #
#    Updated: 2025/10/24 19:08:25 by rafaoliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

# COMPILER AND FLAGS
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -O3

# MANDATORY FILES
NAME = fractol
SRC = 	src/fractol.c \
		src/events.c \
		src/math_utils.c \
		src/render.c \
		src/init.c \
		src/clean_up.c
OBJ = $(SRC:.c=.o)

# BONUS FILES
SRC_BONUS = src/bonus/fractol_bonus.c \
			src/bonus/events_bonus.c \
			src/bonus/math_utils_bonus.c \
			src/bonus/render_bonus.c \
			src/bonus/init_bonus.c \
			src/bonus/clean_up_bonus.c \
			src/bonus/fractal_colors_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

# LIBRARIES
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES = -I$(LIBFT_DIR)
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

MLX_DIR = ./mlx
MLX = $(MLX_DIR)/minilibx.a
MLX_INCLUDES = -I$(MLX_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES = -I. $(LIBFT_INCLUDES) $(MLX_INCLUDES)

# RULES
all: $(NAME)

bonus: .bonus

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)Compilado: $@$(RESET)"

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(CYAN)╔═════════════════════════════════════╗$(RESET)"
	@echo "$(CYAN)║ $(GREEN)✨ $(NAME) compilado com sucesso ✨$(CYAN) ║$(RESET)"
	@echo "$(CYAN)╚═════════════════════════════════════╝$(RESET)"

.bonus: $(OBJ_BONUS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)
	@touch .bonus
	@echo "$(CYAN)╔═════════════════════════════════════════════╗$(RESET)"
	@echo "$(CYAN)║ $(GREEN)✨ $(NAME) (bonus) compilado com sucesso ✨$(CYAN) ║$(RESET)"
	@echo "$(CYAN)╚═════════════════════════════════════════════╝$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)⏳ Compilando libft...$(RESET)"
	@make -C $(LIBFT_DIR) --silent
	@echo "$(GREEN)✔️ libft compilada$(RESET)"

$(MLX):
	@echo "$(YELLOW)⏳ Compilando mlx...$(RESET)"
	@make -C $(MLX_DIR) --silent
	@echo "$(GREEN)✔️ mlx compilada$(RESET)"

norminette:
	@echo "$(BLUE)🔍 Verificando norminette do fractol...$(RESET)"
	@norminette $(SRC) $(SRC_BONUS) fractol.h
	@echo "$(BLUE)🔍 Verificando norminette da libft...$(RESET)"
	@make norminette -C $(LIBFT_DIR) --silent

clean:
	@rm -f $(OBJ) $(OBJ_BONUS) .bonus
	@make clean -C $(LIBFT_DIR) --silent
	@make clean -C $(MLX_DIR) --silent
	@echo "$(MAGENTA)🧹 Arquivos .o limpos$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR) --silent
	@make clean -C $(MLX_DIR) --silent
	@echo "$(RED)🗑️ Tudo limpo$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re norminette