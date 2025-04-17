
# ARCHIVO MAKEFILE BASICO "SO_LONG" -----------------------

# INTERFAZ GRAFICA -----------------------------------------
# ---------------------------------------------------
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

# NOMBRES -----------------------------------------
# ---------------------------------------------------

LIBRARY := so_long.a
NAME := so_long

# DIRECTORIOS -----------------------------------------
# ---------------------------------------------------

INCLUDES_DIR 	:= ./include

LIBFT_DIR 		:= ./libft
LIBFT_ARCHIVE 	:= libft.a
FT_PRINTF_DIR 		:= ./ft_printf
FT_PRINTF_ARCHIVE 	:= libftprintf.a

# LIBRERIA MLX42
MLX42_DIR 		:= ./MLX42
MLX42_ARCHIVE 	:= libmlx42.a

SRC_DIR		:= ./src 
OBJ_DIR 	:= ./obj

# FLAGS -----------------------------------------
# ---------------------------------------------------

CC 				= cc
CFLAGS 			= -Wall -Wextra -Werror
MAKE_LIBRARY 	= ar -rcs 	# COMPRESION A 1 ARCHIVO -> LIBRERIAS .a  -> $(MAKE_LIBRARY) $(NAME) $(OBJ_FILES) 

# FLAGS MLX42
IFLAGS	= -I$(MLX42_DIR)/include -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -I$(INCLUDES_DIR)
LFLAGS	= -L$(MLX42_DIR)/lib -lmlx42 -lglfw -ldl -lm -lpthread -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf

# RECURSOS -----------------------------------------
# ---------------------------------------------------
# LISTADO FUNCIONES A INCLUIR EN BIBLIOTECA

#SRC_FILES := $(wildcard *.c)
SRC_FILES :=	00_so_long.c \
				01_check_map.c  02_utils_map.c\
				03_init_map.c 04_init_game.c \
				05_hooks.c 06_render.c \
				07_free_functions.c  08_utils.c \

OBJ_FILES := $(SRC_FILES:%.c=%.o) 

# RECETAS -----------------------------------------
# ---------------------------------------------------

all: $(NAME)

# LIBRERIA ESTÁTICA 'so_long.a'
$(LIBRARY) : $(OBJ_FILES)
	@echo "$(ORANGE)📦​ Packing library $(LIBRARY)...$(DEF_COLOR)"
	@$(MAKE_LIBRARY) $(LIBRARY) $^
	@echo "$(DARK_GREEN)$(LIBRARY) library created ✓$(DEF_COLOR)"

# EJECUTABLE FINAL
$(NAME): $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE) $(LIBRARY)
	@echo "$(ORANGE)🚀​ Compiling $(NAME)... $(DEF_COLOR)"
	@$(CC) ${CFLAGS} $(IFLAGS) -o $(NAME) $(LIBRARY) $(FT_PRINTF_DIR)/$(FT_PRINTF_ARCHIVE) $(LIBFT_DIR)/$(LIBFT_ARCHIVE) $(MLX42_DIR)/lib/$(MLX42_ARCHIVE) $(LFLAGS)
	@echo "$(DARK_GREEN)$(NAME) has been created ✓$(DEF_COLOR)"

#COMPILACION MANUAL SI NO FUNCIONA MAKEFILE -> cc -Wall -Wextra -Werror -I./include -I./libft -I./ft_printf -o so_long ./src/so_long.c ./ft_printf/libftprintf.a ./libft/libft.a ./MLX42/build/libmlx42.a

## DEPENDENCIAS EXTERNAS ------------------------------------------------

# FUNCION LIBRERIA LIBFT -> CREACION ARCHIVO LIBRERIA
$(LIBFT_ARCHIVE):
	@echo "$(ORANGE)📚​ Compiling $(LIBFT_ARCHIVE) library... $(DEF_COLOR)"
	@cd ${LIBFT_DIR} && make
	@echo "$(DARK_GREEN)$(LIBFT_ARCHIVE) library created ✓$(DEF_COLOR)"

# FUNCION LIBRERIA PRINTF -> CREACION ARCHIVO LIBRERIA
$(FT_PRINTF_ARCHIVE):
	@echo "$(ORANGE)🖨️​ Compiling $(FT_PRINTF_ARCHIVE) library... $(DEF_COLOR)"
	@cd ${FT_PRINTF_DIR} && make
	@echo "$(DARK_GREEN)$(FT_PRINTF_ARCHIVE) library created ✓$(DEF_COLOR)"

# RECETA BORRAR ARCHIVOS
clean:
	@echo "${ORANGE}🗑️​ Removing object files...${NAME}...${DEF_COLOR}"	
	@rm -f $(OBJ_FILES)	
	@echo "${ORANGE}🗑️​ Removing object files...${LIBFT_ARCHIVE}, ${FT_PRINTF_ARCHIVE}..${DEF_COLOR}"
	@cd $(LIBFT_DIR) && $(MAKE) clean
	@cd $(FT_PRINTF_DIR) && $(MAKE) clean
	@echo "${DARK_GREEN}Cleaning objects ${NAME}...is done! ${DEF_COLOR}"

fclean: clean
	@echo "${ORANGE}🗑️ Removing files...${NAME} and $(LIBRARY)... ${DEF_COLOR}"
	@rm -f $(NAME)
	@rm -f $(LIBRARY)
	@echo "${ORANGE}🗑️ Removing files...${LIBFT_ARCHIVE}, ${FT_PRINTF_ARCHIVE}.. ${DEF_COLOR}"
	@cd $(LIBFT_DIR) && $(MAKE) fclean
	@cd $(FT_PRINTF_DIR) && $(MAKE) fclean
	@echo "${DARK_GREEN}Cleaning ${NAME} is done! ${DEF_COLOR}"

## DEBUG flags para sanitize o debugger 'gdb' -> -fsanitize=address
debug: CFLAGS += -g -fsanitize=address
debug: LFLAGS += -fsanitize=address
debug: re

# RECOMPILACION -----------------------------------------
# FUNCION RECONSTRUCCION -> ELIMINACION ARCHIVOS '.o' + NUEVA COMPILACION CON RECETA $(NAME)
re: fclean all
	@echo "${DARK_GREEN}🔁 Cleaning $(NAME) is done and $(NAME) has been recompiled✓! ${DEF_COLOR}"	
	@make clean

.PHONY: all clean fclean re debug
