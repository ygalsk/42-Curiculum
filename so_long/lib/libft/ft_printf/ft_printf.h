/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:21:00 by dkremer           #+#    #+#             */
/*   Updated: 2024/01/15 16:38:18 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "libft/libft.h"

int	ft_printf_char(int c);
int	ft_printf_formats(char str, va_list args);
int	ft_printf(const char *str, ...);
int	ft_printf_p(unsigned long long n);
int	ft_printf_dec(long i);
int	ft_printf_s(char *str);
int	ft_printf_hex(unsigned long i);
int	ft_hex_low(unsigned long i);
int	ft_hex_up(unsigned long i);

#endif //
