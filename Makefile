# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zyunusov <zyunusov@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 12:52:09 by zyunusov          #+#    #+#              #
#    Updated: 2022/10/28 17:57:36 by zyunusov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = srcs/main.c
OBJS = $(SRCS:.c=.o)

CC = gcc 
MFLAGS = ./libft/libft.a ./get_next_line/get_next_line.a

CFLAGS = -Wall -Wextra -Werror -g -I./libft -I./get_next_line 
RM = rm -rf



all :$(MFLAGS) $(NAME)

$(MFLAGS):
	make -sC ./libft
	make -sC ./get_next_line
	
$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(MFLAGS) -o $(NAME)

clean:
	make clean -sC ./libft
	make clean -sC ./get_next_line
	$(RM) ./src/*.o

fclean: clean
	make fclean -sC ./libft
	make fclean -sC ./get_next_line
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re
