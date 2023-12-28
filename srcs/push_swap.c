/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:25:34 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/12/28 13:38:02 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (!ft_check_input(argc, argv))
		return (1);
	stacks.head_a = ft_create_list(argc, argv);
	stacks.head_b = NULL;
	// ft_check_doubles(stacks.head_a);
	ft_sort(&stacks);
	ft_free(&stacks);
}
