NAME = push_swap

SRC = src/main.c src/check_args.c src/push.c src/rotate.c src/swap.c src/sort_small_pilesize.c src/sort1.c src/sort2.c src/utils1.c src/utils2.c
PRINTF_SRC = ft_printf/ft_printf.c ft_printf/ft_hex.c ft_printf/ft_ptr.c ft_printf/ft_putcharstr.c ft_printf/ft_itoa_ft_printf.c ft_printf/ft_unsigned_itoa.c
LIBFT_SRC = libft/ft_atoi.c libft/ft_isspace.c libft/ft_split.c libft/ft_strlen.c

OBJS := $(SRC:%.c=%.o)
PRINTF_OBJS := $(PRINTF_SRC:%.c=%.o)
LIBFT_OBJS := $(LIBFT_SRC:%.c=%.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS) $(PRINTF_OBJS) $(LIBFT_OBJS)
	$(CC) $(FLAGS) $(OBJS) $(PRINTF_OBJS) $(LIBFT_OBJS) -g3 -o $(NAME)

clean:
	rm -rf $(OBJS) $(PRINTF_OBJS) $(LIBFT_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
