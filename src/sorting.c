/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:59:54 by airyago           #+#    #+#             */
/*   Updated: 2023/12/21 18:03:08 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stacks *stacks)
{
	if (ft_check_list_order(stacks))
		return ;
	if (ft_listsize(stacks->head_a) == 2)
		ft_sort_two(stacks);
	else if (ft_listsize(stacks->head_a) == 3)
		ft_sort_three(stacks, 1);
	else if (ft_listsize(stacks->head_a) == 4)
		ft_sort_four(stacks);
	ft_push(stacks, 'b');
	ft_push(stacks, 'b');
	ft_move_best(stacks);
	ft_sort_three(stacks, 0);
	move_stack_a(stacks);
}
