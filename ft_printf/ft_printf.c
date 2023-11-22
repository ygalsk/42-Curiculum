/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:21:32 by dkremer           #+#    #+#             */
/*   Updated: 2023/11/22 17:56:47 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int				res;
	va_list		args;

	res = 0;
	va_start(args, str);
	while (*str)
	{
		res = ft_printf_formats(args, str);
		str++;
	}
	va_end(args);
	return (res);
}
