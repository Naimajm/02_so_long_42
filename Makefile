
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

LIBRARY := so_long.a
NAME := so_long

INCLUDES_DIR 	:= ./include

LIBFT_DIR 		:= ./libft
LIBFT_ARCHIVE 	:= libft.a
FT_PRINTF_DIR 		:= ./ft_printf
FT_PRINTF_ARCHIVE 	:= libftprintf.a

MLX42_DIR 		:= ./MLX42/lib
MLX42_ARCHIVE 	:= libmlx42.a

SRC_DIR		:= ./src 
OBJ_DIR 	:= ./obj

CC 				= cc
CFLAGS 			= -Wall -Wextra -Werror
MAKE_LIBRARY 	= ar -rcs 

IFLAGS	= -I$(MLX42_DIR)/include -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -I$(INCLUDES_DIR)
LFLAGS	= -L$(MLX42_DIR) -lmlx42 -lglfw -ldl -lm -lpthread -L$(LIBFT_DIR) -L$(FT_PRINTF_DIR) 

SRC_FILES :=	00_so_long.c \
				01_check_map.c  02_utils_map.c\
				03_init_map.c 04_init_game.c \
				05_hooks.c 06_render.c \
				07_free_functions.c  08_utils.c \

OBJ_FILES := $(SRC_FILES:%.c=%.o) 

all: $(NAME)

$(LIBRARY) : $(OBJ_FILES)
	@echo "$(ORANGE)📦Packing library $(LIBRARY)...$(DEF_COLOR)"
	@$(MAKE_LIBRARY) $(LIBRARY) $^
	@echo "$(DARK_GREEN)📦 $(LIBRARY) library created			OK$(DEF_COLOR)"

$(NAME): $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE) $(LIBRARY)
	@echo "$(ORANGE)🚀​ Compiling $(NAME)... $(DEF_COLOR)"
	@$(CC) ${CFLAGS} $(IFLAGS) -o $(NAME) $(LIBRARY) $(FT_PRINTF_DIR)/$(FT_PRINTF_ARCHIVE) $(LIBFT_DIR)/$(LIBFT_ARCHIVE) $(MLX42_DIR)/$(MLX42_ARCHIVE) $(LFLAGS)
	@echo "$(DARK_GREEN)$(NAME) has been created			OK$(DEF_COLOR)"

#$(MLX42_ARCHIVE):
#	@cd ${MLX42_DIR} && $(MAKE) -s
#	@echo "$(DARK_GREEN)📦 $(MLX42_ARCHIVE) library created			OK$(DEF_COLOR)"

$(LIBFT_ARCHIVE):
	@cd ${LIBFT_DIR} && $(MAKE) -s
	@echo "$(DARK_GREEN)📚 $(LIBFT_ARCHIVE) library created			OK$(DEF_COLOR)"

$(FT_PRINTF_ARCHIVE):
	@cd ${FT_PRINTF_DIR} && $(MAKE) -s
	@echo "$(DARK_GREEN)📦 $(FT_PRINTF_ARCHIVE) library created		OK$(DEF_COLOR)"

clean:
	@rm -f $(OBJ_FILES)	
	@cd $(LIBFT_DIR) && $(MAKE) -s clean
	@cd $(FT_PRINTF_DIR) && $(MAKE) -s clean
	@echo "${MID_GRAY}Cleaning objects ${NAME}			OK${DEF_COLOR}"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBRARY)
	@cd $(LIBFT_DIR) && $(MAKE) -s fclean
	@cd $(FT_PRINTF_DIR) && $(MAKE) -s fclean
	@echo "${MID_GRAY}Cleaning ${NAME}				OK${DEF_COLOR}"

debug: CFLAGS += -g -fsanitize=address
debug: LFLAGS += -fsanitize=address
debug: re
# Run like this to ignore external leaks: ASAN_OPTIONS=detect_leaks=0 make debug

re: fclean all
	@echo "${DARK_GREEN}🔁 Cleaning and recompiled -> $(NAME) 		OK${DEF_COLOR}"	
	@$(MAKE) -s clean

.PHONY: all clean fclean re debug
