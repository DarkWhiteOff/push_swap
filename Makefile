NAME = push_swap

SRC = main2.c
GNL_SRC = get_next_line/get_next_line.c  get_next_line/get_next_line_utils.c
PRINTF_SRC = ft_printf/ft_printf.c ft_printf/ft_hex.c ft_printf/ft_ptr.c ft_printf/ft_putcharstr.c ft_printf/ft_itoa_ft_printf.c ft_printf/ft_unsigned_itoa.c
LIBFT_SRC = libft/ft_atoi.c libft/ft_isdigit.c libft/ft_lstadd_back_bonus.c libft/ft_lstmap_bonus.c libft/ft_memmove.c libft/ft_split.c libft/ft_strlcpy.c libft/ft_strtrim.c libft/ft_bzero.c libft/ft_islower.c libft/ft_lstadd_front_bonus.c libft/ft_lstnew_bonus.c libft/ft_memset.c libft/ft_strlen.c libft/ft_calloc.c libft/ft_isprint.c libft/ft_lstclear_bonus.c libft/ft_lstsize_bonus.c  libft/ft_putchar_fd.c libft/ft_strmapi.c libft/ft_tolower.c libft/ft_isalnum.c libft/ft_isspace.c libft/ft_lstdelone_bonus.c libft/ft_memchr.c libft/ft_putendl_fd.c libft/ft_striteri.c libft/ft_strncmp.c libft/ft_toupper.c libft/ft_isalpha.c libft/ft_isupper.c libft/ft_lstiter_bonus.c libft/ft_memcmp.c libft/ft_putnbr_fd.c libft/ft_strnstr.c libft/ft_isascii.c libft/ft_itoa.c libft/ft_lstlast_bonus.c libft/ft_memcpy.c libft/ft_putstr_fd.c libft/ft_strlcat.c libft/ft_strrchr.c

OBJS := $(SRC:%.c=%.o)
GNL_OBJS := $(GNL_SRC:%.c=%.o)
PRINTF_OBJS := $(PRINTF_SRC:%.c=%.o)
LIBFT_OBJS := $(LIBFT_SRC:%.c=%.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJS) $(GNL_OBJS) $(PRINTF_OBJS) $(LIBFT_OBJS)
	$(CC) $(FLAGS) $(OBJS) $(GNL_OBJS) $(PRINTF_OBJS) $(LIBFT_OBJS) -g3 -o $(NAME)

clean:
	rm -rf $(OBJS) $(GNL_OBJS) $(PRINTF_OBJS) $(LIBFT_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
