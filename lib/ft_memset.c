/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:13:23 by dkremer           #+#    #+#             */
/*   Updated: 2023/10/14 19:42:15 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*memset(void *ptr, int value, unsigned int num)
{
	unsigned char = *p;
	*p = (unsigned char *) ptr;
	while (num > 0)
	{
		*p = (unsigned char)value;
		p++;
		num--;
	}
	return (ptr);
}
