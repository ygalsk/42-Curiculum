/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:25:35 by dkremer           #+#    #+#             */
/*   Updated: 2023/10/19 17:30:32 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned char	uc;
	unsigned char	*p;

	uc = (unsigned char)c;
	p = (unsigned char *)s;
	while (n > 0)
	{
		if (*p == uc)
			return ((void *)p);
		p++;
		n--;
	}
	return (0);
}
