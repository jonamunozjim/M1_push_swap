# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/29 13:57:01 by jbrosio           #+#    #+#              #
#    Updated: 2026/10/27 13:32:39 by fejimene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Compilation variables
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -I./Super_libft
RM = rm -rf

## Library configuration
LIB_DIR = Super_libft
LIB_A = $(LIB_DIR)/super_libft.a

## Source files
SRC = ft_bench.c \
    ft_disorder.c \
    ft_init_free.c \
    ft_push.c \
    ft_reverse_rotate.c \
    ft_simple_sort.c \
    ft_swap.c \
    ft_complex_sort.c \
    ft_dlstclear.c \
    ft_fill_nodes.c \
    ft_medium_sort.c \
    ft_push_input_check.c \
    ft_rotate.c \
    ft_sort_small.c \
    main.c

OBJ = $(SRC:%.c=%.o)

## Main rules
all: $(NAME)

## Compile the library first by calling the Makefile in its directory
$(LIB_A):
	$(MAKE) -C $(LIB_DIR)

## Compile push_swap linking .o files with the .a library
$(NAME): $(OBJ) $(LIB_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_A) $(INCLUDES) -o $(NAME)

## Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

## Clean rules
clean:
	$(MAKE) -C $(LIB_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re