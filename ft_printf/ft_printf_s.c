/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:23:40 by dkremer           #+#    #+#             */
/*   Updated: 2023/11/22 19:47:38 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		i = write(1, "(null)", 6);
		if (i < 0)
			return (-1);
		return (i);
	}
	else
		i = (write(1, str, ft_strlen(str)));
	if (i < 0)
		return (-1);
	return (i);
}
