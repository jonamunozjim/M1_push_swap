# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/27 13:31:37 by jmunoz-j          #+#    #+#              #
#    Updated: 2026/10/27 16:25:20 by jmunoz-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Compilation variables
NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -I./Super_libft
RM = rm -rf

## Library configuration
LIB_DIR = Super_libft
LIB_A = $(LIB_DIR)/super_libft.a

## Shared files (Parsing, utilities, operations)
SHARED_SRC = ft_init_free.c \
    ft_push.c \
    ft_reverse_rotate.c \
    ft_swap.c \
    ft_dlstclear.c \
    ft_fill_nodes.c \
    ft_push_input_check.c \
    ft_rotate.c \
    ft_bench.c \
    ft_disorder.c

SHARED_OBJ = $(SHARED_SRC:%.c=%.o)

## Push_swap specific files (Algorithms and main)
PS_SRC = main.c \
	ft_simple_sort.c \
	ft_complex_sort.c \
	ft_medium_sort.c \
	ft_sort_small.c

PS_OBJ = $(PS_SRC:%.c=%.o)

## Bonus specific files
BONUS_SRC = checker.c \
	ft_checker_input_check.c

BONUS_OBJ = $(BONUS_SRC:%.c=%.o)

## Main rules
all: $(NAME)

## Compile the library first by calling the Makefile in its directory
$(LIB_A):
	$(MAKE) -C $(LIB_DIR)

## Compile push_swap linking .o files with the .a library
$(NAME): $(SHARED_OBJ) $(PS_OBJ) $(LIB_A)
	$(CC) $(CFLAGS) $(SHARED_OBJ) $(PS_OBJ) $(LIB_A) $(INCLUDES) -o $(NAME)

## Compile bonus
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(SHARED_OBJ) $(BONUS_OBJ) $(LIB_A)
	$(CC) $(CFLAGS) $(SHARED_OBJ) $(BONUS_OBJ) $(LIB_A) $(INCLUDES) -o $(BONUS_NAME)

## Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

## Clean rules
clean:
	$(MAKE) -C $(LIB_DIR) clean
	$(RM) $(SHARED_OBJ) $(PS_OBJ) $(BONUS_OBJ)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus