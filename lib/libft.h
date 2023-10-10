/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:28:54 by dkremer           #+#    #+#             */
/*   Updated: 2023/10/10 18:41:40 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

// ALL PRTOTTYPES FOR LIBFT.A

int ft_isalnum(int c)
int ft_isalpha(int c)
int ft_isascii(int a)
int ft_isdigit(int i)
int ft_isprint(int p)
int ft_strlen(char *str)
int ft_strncmp(char *s1, char *s2, unsigned int n)
char ft_tolower(char c)
char ft_toupper(char c)
char *ft_strchr(const char *s, int c)
char *ft_strrchr(const char *s, int c)
void *ft_memset(void *b, int c, unsigned int len)
void ft_bzero(void *s, unsigned int n)
void *ft_memcpy(void *restrict dst, const void *restrict src, usigned int n)
void *ft_memmove(void *dst, const void *src, unsigned int len)
unsigned int ft_strlcpy(char *restrict dst, const char *restrict src, unsigned int dstsize)
unsigned int ft_strlcat(char *resrict dst, const char *restrict src, unsigned int dstsize)
void *ft_memchr(const void *s, int c, unsigned int n)
int ft_memcmp(const void *s1, const void *s2, unsigned int n)
char *ft_strnstr(const char *haystack, const char *needle, unsigned int len)
int ft_atoi(const char *str)
void *ft_calloc(unsigned int count, unsigned int size)
char *ft_strdup(const char *s1)
char *ft_substr(char const *s, unsigned int start,
unsigned int len)
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
