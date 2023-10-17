/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:51:00 by dkremer           #+#    #+#             */
/*   Updated: 2023/10/16 23:07:44 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, unsigned int n)
{
	unsigned char	*p;

	p = (unsigned char *) s;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}
