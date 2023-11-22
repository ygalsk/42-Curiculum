/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:22:07 by dkremer           #+#    #+#             */
/*   Updated: 2023/11/22 23:53:24 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_formats(va_list args, const char *str)
{
	int	len;

	len = 0;
	if (*str == '%')
		len = ft_printf_perc();
	else if (*str == 'c')
		len = ft_printf_char(va_arg(args, int));
	else if (*str == 's')
		len = ft_printf_s(va_arg(args, char *));
	else if (*str == 'p')
		len = ft_printf_p(va_arg(args, unsigned long long));
	else if (*str == 'd' || *str == 'i')
		len = ft_printf_dec(va_arg(args, int));
	else if (*str == 'u')
		len = ft_printf_u(va_arg(args, unsigned int));
	else if (*str == 'x' || *str == 'X')
		len = ft_printf_hex((unsigned int) va_arg(args, int), *str);
	if (len < 0)
		return (-1);
	return (len);
}
