/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:19:24 by dkremer           #+#    #+#             */
/*   Updated: 2023/10/16 23:22:38 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	unsigned int	h;
	unsigned int	n;

	h = 0;
	n = 0;
	if (nee[n] == '\0')
		return ((char *)hay);
	while (hay[h] != '\0')
	{
		while (hay[h + n] == nee[n] && (h + n) < len)
		{
			if (hay[h + n] == '\0' && nee[n] == '\0')
				return ((char *)&hay[h]);
			n++;
		}
		if (nee[n] == '\0')
			return ((char *)hay + h);
		h++;
	}
	return (0);
}
