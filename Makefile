# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vstineau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 16:48:17 by vstineau          #+#    #+#              #
#    Updated: 2024/02/21 14:46:19 by vstineau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
NAME2 = server
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O2 -fno-builtin
SRCS =	client.c
SRCS2 =	server.c

OBJS = $(SRCS:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
INCLUDES = -I. -ILIBFT
LIBFT = LIBFT/libft.a 

all: $(NAME) $(NAME2) 

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(NAME2): $(OBJS2) $(LIBFT)
	$$(CC) $(CFLAGS) -o $(NAME) $(OBJS2) $(LIBFT)

$(LIBFT):
	$(MAKE) -C LIBFT

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< 

clean:
	$(MAKE) -C LIBFT clean
	rm -rf $(OBJS) && rm -rf $(OBJS2)

fclean: clean
	$(MAKE) -C LIBFT fclean
	rm -rf $(NAME) && rm -rf $(NAME2)

re: fclean all

.PHONY: all clean fclean re
