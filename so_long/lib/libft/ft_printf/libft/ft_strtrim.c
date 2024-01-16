/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:59:54 by dkremer           #+#    #+#             */
/*   Updated: 2023/10/29 20:58:20 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;
	char	*trim;
	char	*res;

	if (!s1)
		return (NULL);
	trim = (char *)s1;
	start = 0;
	end = ft_strlen(trim);
	while (trim[start] && ft_strchr(set, trim[start]))
		start++;
	while (end > start && ft_strchr(set, trim[end]))
		end--;
	len = end - start + 1;
	if (len == 0)
		return (trim);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, trim + start, len + 1);
	return (res);
}
