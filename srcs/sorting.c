/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:59:54 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/28 16:48:17 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stacks *stacks)
{
	if (check_list_order(stacks))
		return ;
	if (ft_listsize_a(stacks->head_a) == 2)
		sort_two(stacks);
	else if (ft_listsize_a(stacks->head_a) == 3)
		sort_three(stacks, 1);
	else if (ft_listsize_a(stacks->head_a) == 4)
		sort_four(stacks);
	ft_push(stacks, 'b');
	ft_push(stacks, 'b');
	move_cheapest(stacks);
	sort_three(stacks, 0);
	move_stack_a(stacks);
}
