/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_best.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:26:29 by airyago           #+#    #+#             */
/*   Updated: 2023/12/21 17:35:34 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_moves(t_stacks *stacks)
{
	int			i;
	int			size;
	t_stack	*head_a;

	head_a = stacks->head_a;
	size = ft_listsize(stacks->head_a);
	i = 0;
	while (i++ < size)
	{
		ft_calc_moves_to_top(stacks, head_a, i - 1);
		if (head_a->data > stacks->values->max_b || \
			head_a->data < stacks->values->min_b)
			ft_update_stack_limits(stacks);
		else
			ft_calc_move_new_num(stacks, head_a->data);
		ft_double_moves(stacks);
		ft_check_cost(stacks, i);
		head_a = head_a->next;
	}
}

void	ft_check_cost(t_stacks *stacks, int i)
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

void	ft_double_moves(t_stacks *stacks)
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
