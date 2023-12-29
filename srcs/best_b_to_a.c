/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:53:24 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/29 16:20:38 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Executes the moves necessary to reorder stack A as determined by put_in_order.
 *
 * @param stacks - The container holding both stacks and their operational data.
 */
static void ft_execute_moves(t_stacks *stacks)
{
	while (stacks->moves->ra > 0)
	{
		ft_rotate(stacks, 'a');
		stacks->moves->ra--;
	}
	while (stacks->moves->rra > 0)
	{
		ft_rev_rotate(stacks, 'a');
		stacks->moves->rra--;
	}
}

/**
 * Rotates stack A until the smallest element is at the top.
 *
 * @param stacks - The container holding both stacks and their operational data.
 */
static void ft_min_to_top(t_stacks *stacks)
{
	int index;
	int stack_size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->head_a->content != stacks->values->min_a)
	{
		index = ft_find_index_stack_a(stacks, stacks->values->min_a);
		stack_size = ft_listsize_a(stacks->head_a);
		if (index > stack_size / 2)
			stacks->moves->rra = stack_size - index;
		else
			stacks->moves->ra = index;
	}
	ft_execute_moves(stacks);
}

/**
 * Moves all elements from stack B to stack A in the most efficient order.
 * It calculates the best move based on the current value's position relative
 * to the max and min values in stack A.
 *
 * @param stacks - The container holding both stacks and their operational data.
 */
void ft_best_b_to_a(t_stacks *stacks)
{
	while (stacks->head_b != NULL)
	{
		ft_check_limits_a(stacks);
		if (stacks->head_b->content < stacks->values->min_a)
			ft_calc_min_to_top(stacks);
		else if (stacks->head_b->content > stacks->values->max_a)
			ft_calc_max_to_top(stacks);
		else
			ft_place_element_a(stacks, stacks->head_b);
	}
	ft_check_limits_a(stacks);
	ft_min_to_top(stacks);
}

/**
 * Finds the index of a specific number within stack A.
 *
 * @param stacks - The container holding both stacks and their operational data.
 * @param nbr - The number to find within stack A.
 * @return The index of the number within stack A, or -1 if not found.
 */
int ft_find_index_stack_a(t_stacks *stacks, int nbr)
{
	t_stack_a *current_node;
	int index;
	int stack_size;

	current_node = stacks->head_a;
	stack_size = ft_listsize_a(stacks->head_a);
	for (index = 0; index < stack_size; current_node = current_node->next, index++)
	{
		if (current_node->content == nbr)
			return index;
	}
	return -1;
}
