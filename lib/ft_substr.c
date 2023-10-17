/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:02:00 by dkremer           #+#    #+#             */
/*   Updated: 2023/10/17 23:33:36 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sstring;
	int		str_len;

	sstring = malloc(len + 1);
	if (sstring == '\0')
	{
		return (0);
	}
	str_len = ft_strlen(s);
	if (start >= str_len)
		ft_strcpy(sstring, " ");
	else
	{
		if (len < 0 || start + len > str_len)
			len = str_len - start;
	}
	ft_strcpy(sstring, s + start, len);
	sstring[len] = '\0';
	return (sstring);
}


int main() {
    const char *original_string = "Hello, World!";
    int start = 7;

    // Get a substring starting from index 7 to the end
    char *result = ft_substr(original_string, start, -1);
    printf("%s\n", result);  // Output: "World!"
    free(result);

    // Get a substring starting from index 0 with a length of 5
    result = ft_substr(original_string, 0, 5);
    printf("%s\n", result);  // Output: "Hello"
    free(result);

    return 0;
}
