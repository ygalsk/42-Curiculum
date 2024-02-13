/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:06:38 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/12 18:49:10 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// Exit the program as failure.
void	error(void)
{
	ft_printf("%s\n", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
