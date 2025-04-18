
## MAKEFILE "LIBFT" -----------------------------------------------------------

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

NAME := libft.a

CC 				:= cc
CFLAGS 			:= -Wall -Wextra -Werror
MAKE_LIBRARY 	:= ar -rcs

SRC := ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_bzero.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_strlen.c ft_toupper.c ft_tolower.c ft_strlcat.c ft_strlcpy.c \
	ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
	ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_itoa.c ft_split.c \

OBJ_FILES := $(SRC:%.c= %.o)	

BONUS := ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

OBJ_FILES_BONUS := $(BONUS:%.c= %.o)	

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(ORANGE)🚀​ Compiling $(NAME)... $(DEF_COLOR)"
	@$(MAKE_LIBRARY) $(NAME) $(OBJ_FILES)
	@echo "$(DARK_GREEN)📚 $(NAME) library created			OK$(DEF_COLOR)"

bonus: ${NAME} ${OBJ_FILES_BONUS}
	@echo "$(ORANGE)🚀​ Compiling bonus... $(DEF_COLOR)"
	@$(MAKE_LIBRARY) ${NAME} ${OBJ_FILES_BONUS}
	@echo "$(DARK_GREEN)📚 $(NAME) library created			OK$(DEF_COLOR)"

clean:
	@rm -f $(OBJ_FILES) $(OBJ_FILES_BONUS)
	@echo "${MID_GRAY}Cleaning objects ${NAME}			OK${DEF_COLOR}"

fclean: clean
	@rm -f $(NAME)
	@echo "${MID_GRAY}Cleaning ${NAME}				OK${DEF_COLOR}"

re: fclean all
	@echo "${DARK_GREEN}🔁 Cleaning ${NAME} is done and $(NAME) has been created✓! ${DEF_COLOR}"

.PHONY: all bonus clean fclean re