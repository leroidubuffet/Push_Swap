/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_in_stack_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:15:41 by airyago           #+#    #+#             */
/*   Updated: 2023/12/27 09:01:22 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update_stack_limits(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;
	if (stacks->head_b->data == stacks->values->max_b)
		return ;
	i = ft_find_index_b(stacks, stacks->values->max_b);
	size = ft_listsize(stacks->head_b);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
	else
	{
		if (i > size / 2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
}

void	ft_calc_move_new_num(t_stacks *stacks, int num)
{
	int	i;
	int	size;
	int	nbr;

	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;
	nbr = ft_find_destination(stacks, num);
	if (stacks->head_b->data ==num)
		return ;
	i = ft_find_index_b(stacks,num);
	size = ft_listsize(stacks->head_b);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
	else
	{
		if (i > size / 2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
}

void	ft_calc_moves_to_top(t_stacks *stacks, t_stack *head_a, int i)
{
	int	size;

	stacks->moves->pb = 1;
	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->head_a->data == head_a->data)
		return ;
	size = ft_listsize(stacks->head_a);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stacks->moves->rra = (size - i);
		else
			stacks->moves->ra = i;
	}
	else
	{
		if (i > size / 2)
			stacks->moves->rra = (size - i);
		else
			stacks->moves->ra = i;
	}
}
