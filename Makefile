# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zamgar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 14:24:43 by zamgar            #+#    #+#              #
#    Updated: 2024/06/04 18:03:23 by zamgar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_PATH = ./libft/

LIBFT_NAME = libft.a

LIBFT_LIB = $(addprefix $(LIBFT_PATH), $(LIBFT_NAME))

SRC = src/main.c src/check_args.c src/push.c src/rotate.c src/swap.c src/sort_small_pilesize.c src/sort1.c src/sort2.c src/utils1.c src/utils2.c
PRINTF_SRC = ft_printf/ft_printf.c ft_printf/ft_hex.c ft_printf/ft_ptr.c ft_printf/ft_putcharstr.c ft_printf/ft_itoa_ft_printf.c ft_printf/ft_unsigned_itoa.c ft_printf/ft_strlen.c

OBJS := $(SRC:%.c=%.o)
PRINTF_OBJS := $(PRINTF_SRC:%.c=%.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror -I ./includes

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT_LIB):
	make -sC $(LIBFT_PATH)

$(NAME): $(LIBFT_LIB) $(OBJS) $(PRINTF_OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT_LIB) $(PRINTF_OBJS) -o $(NAME)

clean:
	make clean -sC $(LIBFT_PATH)
	rm -rf $(OBJS) $(PRINTF_OBJS)

fclean: clean
	make fclean -sC $(LIBFT_PATH)
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re