
DEL_LINE            = \033[2K
ITALIC              = \033[3m
BOLD                = \033[1m
DEF_COLOR           = \033[0;39m
GRAY                = \033[0;90m
RED                 = \033[0;91m
GREEN               = \033[0;92m  
YELLOW              = \033[0;93m
BLUE                = \033[0;94m
MAGENTA             = \033[0;95m
CYAN                = \033[0;96m
WHITE               = \033[0;97m
BLACK               = \033[0;99m
ORANGE              = \033[38;5;209m
BROWN               = \033[38;2;184;143;29m
DARK_GRAY           = \033[38;5;234m
MID_GRAY            = \033[38;5;245m
DARK_GREEN          = \033[38;2;75;179;82m
DARK_YELLOW         = \033[38;5;143m

NAME = get_next_line.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
MAKE_LIBRARY = ar -rcs

SRC := get_next_line.c get_next_line_utils.c 

OBJ_FILES := $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(ORANGE)📌​ Compiling $(NAME)... $(DEF_COLOR)"
	$(MAKE_LIBRARY) $(NAME) $(OBJ_FILES) 
	@echo "$(DARK_GREEN) $(NAME) library created ✓ $(DEF_COLOR)"

clean:
	@echo "$(ORANGE)🗑️ Removing object files...${NAME}...$(DEF_COLOR)"
	@rm -f $(OBJ_FILES)
	@echo "${DARK_GREEN}Cleaning objects ${NAME}...is done! ${DEF_COLOR}"

fclean: clean
	@echo "${ORANGE}🗑️ Removing files...${NAME} ${DEF_COLOR}"
	@rm -f $(NAME)
	@echo "${DARK_GREEN}Cleaning ${NAME} is done! ${DEF_COLOR}"

re: fclean all
	@make clean
	@echo "${DARK_GREEN}🗑️ Cleaning $(NAME) is done and 📌 $(NAME) has been created✓! ${DEF_COLOR}"

.PHONY: all clean fclean re

