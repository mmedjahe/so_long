# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmedjahe <mmedjahe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 18:33:19 by mmedjahe          #+#    #+#              #
#    Updated: 2024/07/07 21:53:28 by mmedjahe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	cc

FLAG		=	-Wall -Wextra -Werror -g3

LIBFT_PATH	=	libft

LIBFT_FILE	=	libft.a

LIBFT_LIB	=	$(LIBFT_PATH)/$(LIBFT_FILE)

MLX_PATH	=	 minilibx-linux

MLX_FILE	=	libmlx.a

MLX_FLAGS	=	-lX11 -lXext

MLX_LIB		=	$(MLX_PATH)/$(MLX_FILE)

MLX_EX		=	$(MLX_LIB) $(MLX_FLAGS)

C_FILE		=	so_long.c 

OBJS		=	$(C_FILE:.c=.o)


.c.o:
	$(CC) $(FLAG) -c $< -o $@

all:	$(NAME)


$(LIBFT_LIB):
	make -C $(LIBFT_PATH)

$(MLX_LIB):
	make -C $(MLX_PATH)

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS)
	$(CC) $(OBJS) $(LIBFT_LIB) $(MLX_EX) -o $(NAME) -lm

clean:
	make clean -sC $(MLX_PATH)
	make clean -sC $(LIBFT_PATH)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all
 
.PHONY: all clean fclean re bonus

