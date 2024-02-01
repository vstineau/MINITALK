# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vstineau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 16:48:17 by vstineau          #+#    #+#              #
#    Updated: 2024/02/01 13:50:27 by vstineau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
NAME2 = server
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O2 -fno-builtin
SRCS =	server.c \
				client.c

OBJS = $(SRCS:.c=.o)
INCLUDES = -I. -ILIBFT
LIBFT = LIBFT/libft.a 

all: $(NAME) 

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C LIBFT

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< 

clean:
	$(MAKE) -C LIBFT clean
	rm -rf $(OBJS) 

fclean: clean
	$(MAKE) -C LIBFT fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
