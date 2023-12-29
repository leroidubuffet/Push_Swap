/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:59:54 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/29 12:33:29 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sorts the elements in stack_a of the given t_stacks.
 * The function applies different sorting algorithms based on
 * the number of elements.
 * For 2, 3, and 4 elements, specialized functions are used.
 * For more elements, a general sorting strategy is applied.
 *
 * @param stacks The container holding the stacks to be sorted.
 */
void	ft_sort(t_stacks *stacks)
{
	if (ft_check_order(stacks))
	{
		ft_clearnodes_a(&stacks->head_a);
		exit (0);
	}
	if (ft_listsize_a(stacks->head_a) == 2)
		ft_sort_two(stacks);
	else if (ft_listsize_a(stacks->head_a) == 3)
		ft_sort_three(stacks, 1);
	else if (ft_listsize_a(stacks->head_a) == 4)
		ft_sort_four(stacks);
	ft_push(stacks, 'b');
	ft_push(stacks, 'b');
	move_cheapest(stacks);
	ft_sort_three(stacks, 0);
	ft_best_b_to_a(stacks);
}
