/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:03:28 by airyago           #+#    #+#             */
/*   Updated: 2023/12/28 13:30:50 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Putstr helper function
void	ft_putstr(const char *str)
{
	while (*str)
		write (1, &(*str++), 1);
}

// Print error and exit
void	ft_error(void)
{
	write (STDERR_FILENO, "Error\n", 6);
	exit (1);
}
