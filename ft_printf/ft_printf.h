/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:21:00 by dkremer           #+#    #+#             */
/*   Updated: 2023/11/22 19:45:25 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf_char(int c);
int	ft_printf_formats(va_list args, const char *str);
int	ft_printf(const char *str, ...);
int	ft_printf_p(unsigned long long n);
int	ft_printf_dec(int n);
int	ft_printf_perc(void);
int	ft_printf_s(char *str);
int	ft_printf_u(unsigned int n);
int	ft_printf_hex(unsigned int n, const char str);

#endif //
