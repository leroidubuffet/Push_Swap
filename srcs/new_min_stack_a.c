/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_min_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:44:31 by airyago           #+#    #+#             */
/*   Updated: 2023/12/26 18:45:52 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_min_a(t_stacks *stacks)
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
	do_moves_min_stack_a(stacks);
}

void	do_moves_min_stack_a(t_stacks *stacks)
{
	while (stacks->moves->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->moves->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	ft_push(stacks, 'a');
}
