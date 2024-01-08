/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:03:28 by airyago           #+#    #+#             */
/*   Updated: 2023/08/15 18:24:27 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_putstr(char *str)
{
	while (*str)
		write (1, &(*str++), 1);
}

void	ft_print_bye(void)
{
	ft_putstr("\nCome back later for more push swap fun.\nSee you soon!\n");
}

void	ft_print_instructions(void)
{
	ft_putstr("Welcome to Push swap! \
		Please provide a set of integers to be put in order.");
}

void	ft_print_error(void)
{
	ft_putstr("Error\n");
}
