/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:20:09 by dkremer           #+#    #+#             */
/*   Updated: 2023/10/16 22:48:06 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, unsigned int n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *) dst;
	s = (unsigned const char *) src;
	if (!dst || !src)
		return (0);
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (d);
}
