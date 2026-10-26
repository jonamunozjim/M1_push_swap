# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/26 14:11:08 by jmunoz-j          #+#    #+#              #
#    Updated: 2026/10/26 14:11:18 by jmunoz-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/29 13:57:01 by jbrosio           #+#    #+#              #
#    Updated: 2026/10/26 14:15:00 by jmunoz-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Compilation variables
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

## Static library name
LIB_A = super_libft.a

## Source files
SRC = ft_bench.c \
    ft_disorder.c \
    ft_dlst_size.c \
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

## Compile push_swap linking .o files with the .a library
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_A) -o $(NAME)

## Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

## Clean rules
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re