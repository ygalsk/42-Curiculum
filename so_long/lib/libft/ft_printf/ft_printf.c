/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:21:32 by dkremer           #+#    #+#             */
/*   Updated: 2023/12/16 22:16:41 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		res;
	va_list	args;

	res = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (*str != '\0')
	{
		if (*str == '%')
			res += ft_printf_formats(*(++str), args);
		else
			res += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (res);
}
