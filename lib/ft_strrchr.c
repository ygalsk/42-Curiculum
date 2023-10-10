/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:37:02 by dkremer           #+#    #+#             */
/*   Updated: 2023/10/10 18:21:49 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurrence;

	last_occurence = 0;
	while (*s != '\0')
	{
		if (*s == c)
			last_occurrence = (char *)s;
		s++;
	}
	return (last_occurrence);
}
