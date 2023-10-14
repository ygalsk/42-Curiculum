/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:36:04 by dkremer           #+#    #+#             */
/*   Updated: 2023/10/15 01:06:33 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	unsigned int	len;
	char			*s2;
	char			*dst;
	const char		*src;

	len = 0;
	while (s1[len] != '\0')
		len++;
	s2 = (char *)malloc(len + 1);
	if (s1 == 0 || s2 == 0)
		return (0);
	dst = s2;
	src = s1;
	while (*src != '\0')
	{
		*dst = *src;
		dst ++;
		src++;
	}
	*dst = '\0';
	return (s2);
}
