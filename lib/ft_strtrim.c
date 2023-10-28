/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:59:54 by dkremer           #+#    #+#             */
/*   Updated: 2023/10/28 20:26:42 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

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
	end = ft_strlen(trim) - 1;
	while (trim[start] && ft_strchr(set, trim[start]))
		start++;
	while (end > start && ft_strchr(set, trim[end]))
		end--;
	len = end - start + 1;
	if (len == 0)
		return ((ft_strdup("")));
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, trim + start, len + 1);
	return (res);
}
