# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 12:52:09 by zyunusov          #+#    #+#              #
#    Updated: 2022/11/02 15:36:40 by zyunusov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = srcs/main.c
OBJS = $(SRCS:.c=.o)

CC = gcc 
MFLAGS = ./mlx/libmlx.a ./libft/libft.a ./get_next_line/get_next_line.a ./ft_printf/libftprintf.a

CFLAGS = -Wall -Wextra -Werror -g -I./mlx -I./libft -I./get_next_line 
RM = rm -rf



all :$(MFLAGS) $(NAME)

$(MFLAGS):
	make -sC ./mlx
	make -sC ./libft
	make -sC ./get_next_line
	make -C ./ft_printf

	
$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(MFLAGS) -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make clean -sC ./libft
	make clean -sC ./get_next_line
	make clean -C ./mlx
	make clean -C ./ft_printf
	$(RM) ./src/*.o

fclean: clean
	make fclean -sC ./libft
	make fclean -sC ./get_next_line
	make fclean -C ./ft_printf
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re
