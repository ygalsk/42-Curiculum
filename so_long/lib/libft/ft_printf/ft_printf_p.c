/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:23:17 by dkremer           #+#    #+#             */
/*   Updated: 2023/11/22 19:26:58 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_len(uintptr_t n)
{
	int	l;

	l = 0;
	while (n)
	{
		l++;
		n = n / 16;
	}
	return (l);
}

int	ft_put_p(uintptr_t n)
{
	int	p_len;

	p_len = 0;
	if (n >= 16)
	{
		p_len = ft_put_p(n / 16);
		p_len = ft_put_p(n % 16);
	}
	else
	{
		if (n <= 9)
		{
			p_len = ft_printf_char(n + '0');
			if (p_len < 0)
				return (-1);
		}
		else
		{
			p_len = ft_printf_char(n - 10 + 'a');
			if (p_len < 0)
				return (-1);
		}
	}
	return (p_len);
}

int	ft_printf_p(unsigned long long n)
{
	int	p_len;
	int	res;

	res = 0;
	p_len = write(1, "0x", 1);
	if (p_len < 0)
		return (-1);
	res += p_len;
	if (n == 0)
	{
		p_len = write(1, "0", 1);
		if (p_len < 0)
			return (-1);
		res += p_len;
	}
	else
	{
		ft_put_p(n);
		p_len = ft_p_len(n);
		if (p_len < 0)
			return (-1);
		res += p_len;
	}
	return (res);
}
