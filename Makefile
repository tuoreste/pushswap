# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 07:25:04 by otuyishi          #+#    #+#              #
#    Updated: 2023/08/08 09:47:48 by otuyishi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Directories and libraries
# LIBFT_DIR = ./libft
# LIBFT = $(LIBFT_DIR)/libft.a

# Compiler and flags
CC = gcc
CFLAGS =  -Wall -Wextra -Werror #-fsanitize=address -g

# Source files and object files
SRC = main.c push_swap.c op_push_rotation.c op_rev_rotation.c op_swap.c push_sort.c validating.c parse.c \
ft_atoi.c ft_isdigit.c ft_lstadd_front.c ft_lstlast.c ft_lstsize.c ft_memcpy.c ft_split.c ft_strdup.c \
ft_strjoin.c ft_strlen.c ft_substr.c ft_putendl_fd.c 
OBJ = $(SRC:.c=.o)

# Targets
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
