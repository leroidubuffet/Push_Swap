/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:18:11 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/30 15:31:57 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Reduces the number of individual rotate and reverse rotate operations
 * by combining them into double moves when both stacks can be rotated or
 * reverse rotated simultaneously.
 *
 * @param stacks - The container holding both stacks and their operational data.
 */
static void ft_double_moves(t_stacks *stacks)
{
	stacks->moves->rr = 0;
	stacks->moves->rrr = 0;
	while (stacks->moves->ra > 0 && stacks->moves->rb > 0)
	{
		stacks->moves->ra--;
		stacks->moves->rb--;
		stacks->moves->rr++;
	}
	while (stacks->moves->rra > 0 && stacks->moves->rrb > 0)
	{
		stacks->moves->rra--;
		stacks->moves->rrb--;
		stacks->moves->rrr++;
	}
}

/**
 * Compares and updates the best move sequence with the least cost.
 *
 * @param stacks - The container holding both stacks and their operational data.
 * @param index - The index of the current move in the iteration.
 */
static void ft_check_cost(t_stacks *stacks, int index)
{
	stacks->moves->cost = stacks->moves->pb + stacks->moves->ra
		+ stacks->moves->rb + stacks->moves->rr + stacks->moves->rra
		+ stacks->moves->rrb + stacks->moves->rrr;
	if (index == 1 || (stacks->best->cost > stacks->moves->cost))
	{
		stacks->best->cost = stacks->moves->cost;
		stacks->best->pb = stacks->moves->pb;
		stacks->best->ra = stacks->moves->ra;
		stacks->best->rb = stacks->moves->rb;
		stacks->best->rr = stacks->moves->rr;
		stacks->best->rra = stacks->moves->rra;
		stacks->best->rrb = stacks->moves->rrb;
		stacks->best->rrr = stacks->moves->rrr;
	}
}

/**
 * Evaluates and stores all possible move sequences for moving a number from
 * stack A to stack B, then identifies and stores the most efficient sequence.
 *
 * @param stacks - The container holding both stacks and their operational data.
 */
void ft_find_best_sequence(t_stacks *stacks)
{
	int index;
	int stack_size;
	t_stack_a *current_node;

	current_node = stacks->head_a;
	stack_size = ft_listsize_a(stacks->head_a);
	index = 0;
	while (index++ < stack_size)
	{
		ft_calc_to_top(stacks, current_node, index - 1);
		if (current_node->content > stacks->values->max_b || \
			current_node->content < stacks->values->min_b)
			ft_update_stack_limits(stacks);
		else
			ft_place_element_b(stacks, current_node->content);
		ft_double_moves(stacks);
		ft_check_cost(stacks, index);
		current_node = current_node->next;
	}
}
