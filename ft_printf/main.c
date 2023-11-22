/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:51:46 by dkremer           #+#    #+#             */
/*   Updated: 2023/11/22 22:28:10 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	// Testing system printf
	printf("System printf:\n");
	printf("%s\n", "Hello");
	printf("Hexadecimal: %x\n", 100);
		// Testing your ft_printf
	printf("\nYour ft_printf:\n");
	ft_printf("X", "Hello");
	ft_printf("c", '\n');
	ft_printf("u",1);
	ft_printf("c", '\n');
	ft_printf("s", "Hello \n");
	ft_printf("x", 100);
	ft_printf("c", '\n');
	return (0);
}
