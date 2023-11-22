/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:22:32 by dkremer           #+#    #+#             */
/*   Updated: 2023/11/22 19:04:23 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_dec(int i)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(i);
	len = ft_printf_s(num);
	free(num);
	return (len);
}
