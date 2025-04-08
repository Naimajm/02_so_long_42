CC := clang

CFLAGS := -Wall -Wextra -Werror

SRC := ft_printf.c \
ft_putaddress.c ft_puthexa.c ft_putunsigned.c ft_putnbr.c \
ft_putstr.c ft_putchar.c \

NAME = libftprintf.a

OBJ_FILES := $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	$(CC) main.c $(NAME) -o test_executable

.PHONY: all clean fclean re test

