/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:52:52 by dkremer           #+#    #+#             */
/*   Updated: 2023/12/16 02:57:02 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*read_line(int fd, char *nx_line);
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int n);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_len_nl(char *str);

#endif
