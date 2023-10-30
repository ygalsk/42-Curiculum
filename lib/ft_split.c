/* ************************************************************************** */
/*            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:59:10 by prossi            #+#    #+#             */
/*   Updated: 2023/10/30 00:46:30 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count(char *s, char c)
{
	size_t	i;
	int		x;

	while (*s)
	{
		if (*s != c && x == 0)
		{
			x = 1;
			i++;
		}
		else if (*s == c)
			x = 0;
		s++;
	}
	return (i);
}

void	ft_free(char **substrs, size_t count)
{
	while (count > 0)
	{
		count--;
		free(substrs[count]);
	}
	free(substrs);
}

char	**ft_split(char const *s, char c)
{
	char	**substrs;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_count((char *)s, c);
	substrs = (char **)malloc(sizeof(char *) * (count + 1));
	if (!substrs)
	{
		ft_free(substrs, count);
		return (NULL);
	}
	return (substrs);
}
