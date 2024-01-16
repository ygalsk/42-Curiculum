# Name of the binary
NAME 		= libft.a

# Compiler and flags
CC 			= cc
CFLAGS 	= -g -Wall -Werror -Wextra

# Source files
SRCS 		= ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			 		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			 		ft_toupper.c ft_tolower.c ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			 		ft_atoi.c ft_substr.c ft_strjoin.c ft_split.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			 		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_calloc.c ft_strrchr.c ft_strdup.c \
			 		ft_printf/ft_printf_char.c ft_printf/ft_printf.c ft_printf/ft_printf_dec.c ft_printf/ft_printf_formats.c ft_printf/ft_printf_hex.c \
					ft_printf/ft_printf_p.c ft_printf/ft_printf_s.c \
					get_next_line.c ft_len_nl.c
				
# Header files
HEADERS = libft.h get_next_line/get_next_line.h ft_printf/ft_printf.h

# Object files
OBJS 		= $(SRCS:.c=.o)

# Default target
all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo $(GREEN)"Linking $(NAME)"$(DEFAULT);

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Remove all object files
clean:
	@rm -f $(OBJS)
	@echo $(RED)"Removing object files"$(DEFAULT);

# Remove all files
fclean: clean
	@rm -f $(NAME)
	@echo $(RED)"Removing all files"$(DEFAULT);

# Rebuild everything
re: fclean all
	@echo $(GREEN)"Rebuilding everything"$(DEFAULT);

.PHONY: all clean fclean re

# Colours
DEFAULT = "\033[39m"
GREEN		= "\033[32m"
RED			= "\033[31m"
