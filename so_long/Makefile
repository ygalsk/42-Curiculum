# Name of the binary
NAME 			= so_long

#Existential crisis
USER 			= $(shell whoami)

# Compiler and flags
CC 				= cc
CFLAGS 		= -g -Wall -Werror -Wextra

#MLX42 Flags
MLXFLAGS 	= -framework Cocoa -framework OpenGL -framework IOKit -I include -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

# Source files
SRCS 			= $(wildcard lib/libft/*.c lib/libft/ft_printf/*.c ./*.c)

# Header files
HEADERS 	= lib/libft/libft.h lib/libft/ft_printf/ft_printf.h 

# Object files
OBJS 			= $(SRCS:.c=.o)

# Default target
all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./lib/MLX42/build/libmlx42.a $(MLXFLAGS)
	@echo $(GREEN)"Building $(NAME)"$(DEFAULT);

#MLX42
MLX42:
	@if [ ! -d "MLX42" ];then git clone https://github.com/codam-coding-college/MLX42.git; fi
	@cd MLX42 && cmake -B build && cmake --build build -j4
	@echo $(GREEN)"Building MLX42"$(DEFAULT);

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Remove all object files
clean:
	@rm -f $(OBJS)
	@echo $(RED)"Removing object files"$(DEFAULT);

# Remove all files
fclean: clean
	@rm -f $(NAME)
	@echo $(RED)"Removing $(NAME)"$(DEFAULT);

# Rebuild everything
re: fclean all
	@echo $(GREEN)"Rebuilding everything"$(DEFAULT);

.PHONY: all clean fclean re

# Colours
DEFAULT = "\033[39m"
GREEN		= "\033[32m"
RED			= "\033[31m"
