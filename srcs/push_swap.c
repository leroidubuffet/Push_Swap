/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:25:34 by airyago           #+#    #+#             */
/*   Updated: 2023/12/27 07:47:04 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	ft_check_input(argc, argv);
	stacks.head_a = ft_create_list(argc, argv);
	stacks.head_b = NULL;
	ft_check_doubles(stacks.head_a);
	ft_sort(&stacks);
	ft_free(&stacks);
}
