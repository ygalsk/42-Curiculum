/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:39:46 by dkremer           #+#    #+#             */
/*   Updated: 2023/10/19 23:06:26 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sgn;
	int	res;

	i = 0;
	sgn = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sgn = -1;
		i++;
	}
	else if (str[i]== '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sgn);
}

#include <stdio.h>

int ft_atoi(const char *str);

int main() {
    // Test with positive numbers
    printf("Test 1: %d\n", ft_atoi("42")); // Expected: 42
    printf("Test 2: %d\n", ft_atoi("12345")); // Expected: 12345

    // Test with random numbers
    printf("Test 3: %d\n", ft_atoi("   789  ")); // Expected: 789
    printf("Test 4: %d\n", ft_atoi("   -567  ")); // Expected: -567

    // Test with spaces and non-space invisible characters
    printf("Test 5: %d\n", ft_atoi("   \t\r\n-123  ")); // Expected: -123

    // Test with INT_MAX
    printf("Test 6: %d\n", ft_atoi("2147483647")); // Expected: 2147483647

    return 0;
}

