
# "FT_PRINTF" -----------------------

DEF_COLOR           = \033[0;39m
GRAY                = \033[0;90m
RED                 = \033[0;91m
GREEN               = \033[0;92m  
YELLOW              = \033[0;93m
BLUE                = \033[0;94m
MAGENTA             = \033[0;95m
CYAN                = \033[0;96m
ORANGE              = \033[38;5;209m
DARK_GRAY           = \033[38;5;234m
MID_GRAY            = \033[38;5;245m
DARK_GREEN          = \033[38;2;75;179;82m
DARK_YELLOW         = \033[38;5;143m

NAME = libftprintf.a

CC := cc
CFLAGS := -Wall -Wextra -Werror
MAKE_LIBRARY := ar -rcs

SRC := ft_printf.c \
	ft_putaddress.c ft_puthexa.c ft_putunsigned.c ft_putnbr.c \
	ft_putstr.c ft_putchar.c \

OBJ_FILES := $(SRC:%.c= %.o)  

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(ORANGE)🚀​ Compiling $(NAME)... $(DEF_COLOR)"
	@$(MAKE_LIBRARY) $(NAME) $(OBJ_FILES)
	@echo "$(DARK_GREEN)📦 $(NAME) library created		OK$(DEF_COLOR)"

clean:
	@rm -f $(OBJ_FILES)
	echo "${MID_GRAY}Cleaning objects ${NAME}			OK${DEF_COLOR}"

fclean: clean 
	@rm -f $(NAME)
	@echo "${MID_GRAY}Cleaning ${NAME}				OK${DEF_COLOR}"

re: fclean all
	@echo "${DARK_GREEN}🔁 Cleaning ${NAME} is done and $(NAME) has been created✓! ${DEF_COLOR}"

.PHONY: all bonus clean fclean re

