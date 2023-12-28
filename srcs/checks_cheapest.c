/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_cheapest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:18:11 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/12/28 12:36:56 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_moves(t_stacks *stacks)
{
	int			i;
	int			size;
	t_stack_a	*head_a;

	head_a = stacks->head_a;
	size = ft_listsize_a(stacks->head_a);
	i = 0;
	while (i++ < size)
	{
		get_top_stack_a(stacks, head_a, i - 1);
		if (head_a->content > stacks->values->max_b || \
			head_a->content < stacks->values->min_b)
			new_max_or_min_stack_b(stacks);
		else
			new_num_in_stack_b(stacks, head_a->content);
		check_double_moves(stacks);
		check_cost(stacks, i);
		head_a = head_a->next;
	}
}

void	check_cost(t_stacks *stacks, int i)
{
	stacks->moves->cost = stacks->moves->pb + stacks->moves->ra
		+ stacks->moves->rb + stacks->moves->rr + stacks->moves->rra
		+ stacks->moves->rrb + stacks->moves->rrr;
	if (i == 1 || (stacks->best->cost > stacks->moves->cost))
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

void	check_double_moves(t_stacks *stacks)
{
	stacks->moves->rr = 0;
	stacks->moves->rrr = 0;
	while (stacks->moves->ra != 0 && stacks->moves->rb != 0)
	{
		stacks->moves->ra--;
		stacks->moves->rb--;
		stacks->moves->rr++;
	}
	while (stacks->moves->rra != 0 && stacks->moves->rrb != 0)
	{
		stacks->moves->rra--;
		stacks->moves->rrb--;
		stacks->moves->rrr++;
	}
}
