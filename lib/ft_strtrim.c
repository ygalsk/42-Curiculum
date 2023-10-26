/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:59:54 by dkremer           #+#    #+#             */
/*   Updated: 2023/10/25 20:40:11 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start;
	size_t	end;
	int	len;
	size_t	res_len;

	len = (const char *)set;
	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(s1, len))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strrchr(s1, len))
		end--;
	res_len = end - start;
	res = (char *)malloc(sizeof(*s1) * (res_len + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, s1 + start, res_len);
	res[res_len] = '\0';
	return (res);
}
