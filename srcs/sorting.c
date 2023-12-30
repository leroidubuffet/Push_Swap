/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:59:54 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/30 13:54:57 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Checks if the elements in stack 'a' are in ascending order.
 *
 * @param stacks - The container holding both stacks.
 * @return Returns 1 if the stack is in order, 0 otherwise.
 */
static bool ft_check_order(t_stacks *stacks)
{
	t_stack_a	*current_node;
	int			last_value;

	if (!stacks || !stacks->head_a || !stacks->head_a->next)
		return (1);
	current_node = stacks->head_a;
	last_value = current_node->content;
	current_node = current_node->next;
	while (current_node)
	{
		if (last_value > current_node->content)
			return (0);
		last_value = current_node->content;
		current_node = current_node->next;
	}
	return (1);
}

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
		ft_sort_three(stacks, true);
	else if (ft_listsize_a(stacks->head_a) == 4)
		ft_sort_four(stacks);
	ft_push(stacks, 'b');
	ft_push(stacks, 'b');
	ft_move_a_to_b(stacks);
	ft_sort_three(stacks, false);
	ft_best_b_to_a(stacks);
}
