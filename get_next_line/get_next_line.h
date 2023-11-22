/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:06:34 by dkremer           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/11/21 16:33:30 by dkremer          ###   ########.fr       */
=======
/*   Updated: 2023/11/15 13:52:48 by dkremer          ###   ########.fr       */
>>>>>>> 287ca61bf01fe4596b1c03cc1e765e13ac240fd6
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
<<<<<<< HEAD
#  define BUFFER_SIZE 10
=======
#  define BUFFER_SIZE 5
>>>>>>> 287ca61bf01fe4596b1c03cc1e765e13ac240fd6
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int n);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif
