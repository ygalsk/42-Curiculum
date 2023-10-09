
#ifndef LIBFT_H
#define LIBFT_H

// ALL PRTOTTYPES FOR LIBFT.A

int ft_isalnum(int c)
int ft_isalpha(int c)
int ft_isascii(int a)
int ft_isdigit(int i)
int ft_isprint(int p)
int	ft_strlen(char *str)
int	ft_strncmp(char *s1, char *s2, unsigned int n)
char ft_tolower(char c)
char ft_toupper(char c)

char *ft_substr(char const *s, unsigned int start,
size_t len)
char *ft_strjoin(char const *s1, char const *s2)
char *ft_strtrim(char const *s1, char const *set)
char **ft_split(char const *s, char c)
char *ft_itoa(int n)
char *ft_strmapi(char const *s, char (*f)(unsigned
int, char))
void ft_striteri(char *s, void (*f)(unsigned int,
char*))
void ft_putchar_fd(char c, int fd)
void ft_putstr_fd(char *s, int fd)
void ft_putendl_fd(char *s, int fd)
void ft_putnbr_fd(int n, int fd)


#endif
