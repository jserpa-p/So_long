# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/02 16:18:07 by jserpa-p          #+#    #+#              #
#    Updated: 2022/02/14 16:26:34 by jserpa-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRCS_FILES	= 	${shell find ./src -name "*.c"}

SRCS		= 	$(SRCS_FILES)
OBJS		=	$(patsubst %.c,%.o,$(SRCS))

LIB_DIR		=	libft
MLX_DIR		=	mlx
INC			=	-I./include -I./libft -I./mlx

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit
RM			=	rm -f

all:		$(NAME)

%.o:		%.c ./include/so_long.h
			$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME):	$(OBJS)
			@make -C $(MLX_DIR)
			@make -C $(LIB_DIR)
			@$(CC) $(CFLAGS) $(MLX_FLAGS) $(INC) $(LIB_DIR)/libft.a $(OBJS) -o $(NAME)
			@clear
			@echo "Let's play!!"

clean:
			@make clean -C $(MLX_DIR)
			@make clean -C $(LIB_DIR)
			$(RM) $(OBJS)

fclean:		clean
			@make fclean -C $(LIB_DIR)
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re