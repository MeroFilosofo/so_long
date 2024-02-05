# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivromero <ivromero@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 01:17:29 by ivromero          #+#    #+#              #
#    Updated: 2024/02/05 18:35:45 by ivromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus

SRC =	src/main.c \
		src/move.c \
		src/map.c \
		src/map_fill.c \
		src/map_paint.c

SRCBONUS =	src_bonus/main_bonus.c \
			src_bonus/move_bonus.c \
			src_bonus/map_bonus.c \
			src_bonus/map_fill_bonus.c \
			src_bonus/map_paint_bonus.c \
			src_bonus/map_textures_bonus.c

OBJS = $(SRC:.c=.o)
OBJSBONUS = $(SRCBONUS:.c=.o)

MLX_LIB = mlx/
MLX_FLAGS = -L mlx/ -lmlx -framework OpenGL -framework AppKit
LIBFT_LIB = libft/
LIBFT_FLAGS = -L libft/ -lft
DEBUG_FLAGS = #-g3 -fsanitize=address

CC		= cc
RM		= rm -f
AR		= ar rcs

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

.c.o:
		$(CC) $(DEBUG_FLAGS) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		@make -C $(MLX_LIB) > /dev/null
		@make -C $(LIBFT_LIB) > /dev/null
		$(CC) $(DEBUG_FLAGS) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)
		@echo "Compilación terminada: $@"
		@make info

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJSBONUS)
		@make -C $(MLX_LIB) > /dev/null
		@make -C $(LIBFT_LIB) > /dev/null
		$(CC) $(DEBUG_FLAGS) $(CFLAGS) $(OBJSBONUS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(BONUS_NAME)
		@echo "Compilación terminada: $@"
		@make info


clean:
		$(RM) */*.o
		$(RM) $(OBJS) $(OBJSBONUS)
		@make -C $(MLX_LIB) clean > /dev/null
		@make -C $(LIBFT_LIB) clean > /dev/null

fclean:	clean
		$(RM) $(NAME) $(BONUS_NAME) $(MLX_LIB)/libmlx.a
		@make -C $(LIBFT_LIB) fclean > /dev/null

re:		fclean all

normi:
		@norminette src/*.c src_bonus/*.c libft/*.c libft/*.h headers/*.h | grep -E '(Error|Warning)' ; true

.PHONY : bonus all clean fclean re info normi

info:
		@read -n 1 -s -r -p "Presiona una tecla para continuar"
		@make cabecera
		@make keny
		@make cabecera
		@make come
		@make cabecera
		@make cocos
		@make cabecera
		@make come
		@make cabecera
		@make cocos
		@make cabecera
		@make come
		@make cabecera
		@make cocos

keny:
		@echo "          ⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛⬜⬜⬜⬜⬜"
		@echo "          ⬜⬜⬜⬛⬛🟧🟧🟧🟧🟧⬛⬛⬜⬜⬜"
		@echo "          ⬜⬜⬛🟧🟧🟧🟧🟧🟧🟧🟧🟧⬛⬜⬜"
		@echo "          ⬜⬛🟧🟧🟧🟧⬛⬛⬛🟧🟧🟧🟧⬛⬜"
		@echo "          ⬜⬛🟧🟧⬛⬛🟫🟫🟫⬛⬛🟧🟧⬛⬜"
		@echo "          ⬛🟧🟧⬛🟫⬜⬜🏼⬜⬜🟫⬛🟧🟧⬛"
		@echo "          ⬛🟧⬛🟫⬜⬜⬜⬜⬜⬜⬜🟫⬛🟧⬛"
		@echo "          ⬛🟧⬛🟫⬜⬜⬛⬜⬛⬜⬜🟫⬛🟧⬛"
		@echo "          ⬛🟧⬛🟫⬜⬜⬜⬜⬜⬜⬜🟫⬛🟧⬛"
		@echo "          ⬛🟧⬛🟫🟫⬜⬜🏼⬜⬜🟫🟫⬛🟧⬛"
		@echo "          ⬜⬛🟧⬛🟫🟫🏼🏼🏼🟫🟫⬛🟧⬛⬜"
		@echo "          ⬜⬛🟧🟧⬛⬛⬛⬛⬛⬛⬛🟧🟧⬛⬜"
		@echo "          ⬜⬜⬛🟧🟧🟧🟧⬛🟧🟧🟧🟧⬛⬜⬜"
		@echo "          ⬜⬜⬛⬛⬛🟧⬛🟧⬛🟧⬛⬛⬛⬜⬜"
		@echo "          ⬜⬛🟧🟧🟧⬛⬛⬛⬛⬛🟧🟧🟧⬛⬜"
		@echo "          ⬛🟧🟧⬛🟧🟧🟧⬛🟧🟧🟧⬛🟧🟧⬛"
		@echo "          ⬛⬛⬛⬛🟧🟧🟧⬛🟧🟧🟧⬛⬛⬛⬛"
		@echo "          ⬛🟫🟫⬛🟧🟧🟧⬛🟧🟧🟧⬛🟫🟫⬛"
		@echo "          ⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜"
		@echo "          ⬜⬜⬜⬛🟧🟧🟧⬛🟧🟧🟧⬛⬜⬜⬜"
		@echo "          ⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜"
		@sleep 1
		clear

cabecera:
		@sleep 0.5
		clear
		@echo "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜"
		@echo "⬜                                                            ⬜"
		@echo "⬜               🕹📀🎮👾  so_long  👾🎮📀🕹                    ⬜"
		@echo "⬜                                                            ⬜"
		@echo "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜"
		@echo  
		@echo ""
		@echo ""
		 



come:
		@echo "            ⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛"
		@echo "            ⬛⬛⬛⬛🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛"
		@echo "            ⬛⬛🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛⬛"
		@echo "            ⬛🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛"
		@echo "            ⬛🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛"
		@echo "            🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛"
		@echo "            🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬜⬜⬛⬛⬛⬜⬜"
		@echo "            🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜⬛⬛⬛⬜⬜"
		@echo "            🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛"
		@echo "            🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛"
		@echo "            ⬛🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛"
		@echo "            ⬛🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛"
		@echo "            ⬛⬛🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛⬛"
		@echo "            ⬛⬛⬛⬛🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛"
		@echo "            ⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛"


cocos:
		@echo "            ⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛"
		@echo "            ⬛⬛⬛⬛🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛"
		@echo "            ⬛⬛🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛⬛"
		@echo "            ⬛🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛"
		@echo "            ⬛🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛"
		@echo "            🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛"
		@echo "            🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬜⬜⬛⬛⬛"
		@echo "            🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬜⬜⬛⬛⬛"
		@echo "            🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛"
		@echo "            🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛"
		@echo "            ⬛🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛"
		@echo "            ⬛🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛"
		@echo "            ⬛⬛🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛⬛"
		@echo "            ⬛⬛⬛⬛🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛"
		@echo "            ⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛"
