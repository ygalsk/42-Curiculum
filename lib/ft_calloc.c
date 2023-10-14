/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:19:26 by dkremer           #+#    #+#             */
/*   Updated: 2023/10/15 00:34:25 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(unsigned int count, unsigned int size)
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
