/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:22:50 by dkremer           #+#    #+#             */
/*   Updated: 2023/11/22 19:00:59 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int i)
{
	int	len;

	len = 0;
	while (i != 0)
	{
		len++;
		i = i / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_put_hex(n / 16, format);
		ft_put_hex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_printf_char(n + '0');
		else
		{
			if (format == 'x')
				ft_printf_char(n - 10 + 'a');
			if (format == 'X')
				ft_printf_char(n - 10 + 'A');
		}
	}
}

int	ft_printf_hex(unsigned int n, const char str)
{
	if (n == 0)
		return (write(1, "0", 1));
	ft_put_hex(n, str);
	return (ft_hex_len(n));
}
