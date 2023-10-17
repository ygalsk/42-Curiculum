/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:19:26 by dkremer           #+#    #+#             */
/*   Updated: 2023/10/16 23:08:50 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	i;
	unsigned int	ts;
	unsigned char	*bptr;
	void			*ptr;

	i = 0;
	ts = count * size;
	ptr = malloc(ts);
	if (ptr != '\0')
	{
		bptr = (unsigned char *)ptr;
		while (i < ts)
		{
			bptr[i] = 0;
			i++;
		}
	}
	return (ptr);
}
