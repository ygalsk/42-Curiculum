NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -I libft

SRCS = ft_printf_char.c ft_printf.c ft_printf_dec.c ft_printf_formats.c ft_printf_hex.c ft_printf_p.c ft_printf_perc.c ft_printf_s.c ft_printf_u.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		make -C libft
		cp libft/libft.a .
		mv libft.a $(NAME)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)
	rm -f test_printf

re: fclean all

test:	$(NAME) main.c
		@$(CC) $(CFLAGS) -L. main.c -lftprintf -o test_printf
		@./test_printf

.PHONY: all clean fclean re
