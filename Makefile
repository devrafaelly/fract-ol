# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafaoliv <rafaoliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 17:12:54 by rafaoliv          #+#    #+#              #
#    Updated: 2025/10/16 19:17:07 by rafaoliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -O3

OBJ = $(SRC:.c=.o)
SRC = fractol.c events.c math_utils.c render.c init.c clean_up.c

NAME = fractol

INCLUDES = $(LIBFT_INCLUDES) $(MLX_INCLUDES)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES = -I$(LIBFT_DIR)
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

MLX_DIR = ./mlx
MLX = $(MLX_DIR)/minilibx.a
MLX_INCLUDES = -I$(MLX_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$@ ✔️"

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)
	@echo "$@ compilado ✔️"
	
$(LIBFT):
	@echo "Compilando libft..."
	@make -C $(LIBFT_DIR)
	@echo "libft compilada ✔️"

$(MLX):
	@echo "Compilando mlx..."
	@make -C $(MLX_DIR)
	@echo "mlx compilada ✔️"

norminette:
	norminette $(SRC) -R CheckForbiddenSourceHeader

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR) --silent
	@make clean -C $(MLX_DIR) --silent
	@echo "Arquivos .o limpos 🧴"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR) --silent
	@make clean -C $(MLX_DIR) --silent
	@echo "Tudo limpo 🧽🧼"

re: fclean all

.PHONY: all clean fclean re norminette