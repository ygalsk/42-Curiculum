NAME = libftprintf.a
CC = cc
CFLAGS = -g -Wall -Werror -Wextra -I libft

SRCS = ft_printf_char.c ft_printf.c ft_printf_dec.c ft_printf_formats.c ft_printf_hex.c ft_printf_p.c ft_printf_s.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) ft_printf.h
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)
	
%.o: %.c
	$(CC) -I $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all clean re

.PHONY: all clean fclean re
