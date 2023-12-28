/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:59:54 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/28 17:37:35 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stacks *stacks)
{
	if (check_list_order(stacks))
		return ;
	if (ft_listsize_a(stacks->head_a) == 2)
		ft_sort_two(stacks);
	else if (ft_listsize_a(stacks->head_a) == 3)
		ft_sort_three(stacks, true);
	else if (ft_listsize_a(stacks->head_a) == 4)
		ft_sort_four(stacks);
	ft_push(stacks, 'b');
	ft_push(stacks, 'b');
	move_cheapest(stacks);
	ft_sort_three(stacks, false);
	move_stack_a(stacks);
}
