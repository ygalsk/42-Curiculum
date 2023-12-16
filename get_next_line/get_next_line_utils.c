/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:04:17 by dkremer           #+#    #+#             */
/*   Updated: 2023/12/16 02:59:11 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_len_nl(char *save)
{
	int	len;

	len = 0;
	while (save[len] && save[len] != '\n')
		len++;
	return (len);
}
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&(str[i]));
		i++;
	}
	return (0);
}
char	*ft_strjoin(char *save, char *buf)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (save == NULL)
	{
		save = (char *)malloc(sizeof(char) * (1));
		save[0] = '\0';
	}
	if (!buf)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(save) + ft_strlen(buf)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (save)
		while (save[++i] != '\0')
			str[i] = save[i];
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	str[ft_strlen(save) + ft_strlen(buf)] = '\0';
	free(save);
	return (str);
}

// char	*ft_strchr(char *s, int c)
// {
// 	if (!s)
// 		return (NULL);
// 	while (*s)
// 	{
// 		if (*s == (char)c)
// 			return ((char *)s);
// 		s++;
// 	}
// 	if (*s == (char)c)
// 		return ((char *)s);
// 	return (NULL);
// }
//
// size_t	ft_strlen(const char *s)
// {
// 	size_t	count;
//
// 	count = 0;
// 	if (!s)
// 		return (0);
// 	while (s[count])
// 		count++;
// 	return (count);
// }
//
// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*s3;
// 	size_t	i;
// 	size_t	j;
//
// 	if (!s1 || !s2)
// 		return (NULL);
// 	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!s3)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s1[i])
// 		s3[j++] = s1[i++];
// 	i = 0;
// 	while (s2[i])
// 	{
// 		s3[j++] = s2[i++];
// 	}
// 	s3[i] = '\0';
// 	free(s1);
// 	return (s3);
// }
//
// int	ft_len_nl(char *str)
// {
// 	int	i;
//
// 	i = 0;
// 	while (str[i] && str[i] != '\0')
// 		i++;
// 	return (i);
// }
