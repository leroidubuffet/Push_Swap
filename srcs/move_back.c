/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:53:24 by airyago           #+#    #+#             */
/*   Updated: 2023/12/21 18:01:38 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_stack_a(t_stacks *stacks)
{
	while (stacks->head_b != NULL)
	{
		check_max_min_a(stacks);
		if (stacks->head_b->data < stacks->values->min_a)
			new_min_stack_a(stacks);
		else if (stacks->head_b->data > stacks->values->max_a)
			new_max_stack_a(stacks);
		else
			new_elem_stack_a(stacks, stacks->head_b);
	}
	check_max_min_a(stacks);
	put_in_order(stacks);
}

void	put_in_order(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->head_a->data != stacks->values->min_a)
	{
		i = find_index_stack_a(stacks, stacks->values->min_a);
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
	do_moves_order(stacks);
}

void	do_moves_order(t_stacks *stacks)
{
	while (stacks->moves->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->moves->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
}

int	find_index_stack_a(t_stacks *stacks, int num)
{
	t_stack	*head_a;
	int			size;
	int			i;

	i = 0;
	head_a = stacks->head_a;
	size = ft_listsize(stacks->head_a);
	while (i < size)
	{
		if (head_a->data ==num)
			break ;
		head_a = head_a->next;
		i++;
	}
	return (i);
}
