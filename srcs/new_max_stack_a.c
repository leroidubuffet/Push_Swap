/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_max_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:43:17 by airyago           #+#    #+#             */
/*   Updated: 2023/12/21 18:01:38 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_max_stack_a(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (ft_lstlast(stacks->head_a)->data != stacks->values->max_a)
	{
		i = find_index_stack_a(stacks, stacks->values->max_a);
		size = ft_listsize(stacks->head_a);
		if (size % 2 == 0)
		{
			if (i + 1 > size / 2)
				stacks->moves->rra = (size - i) - 1;
			else
				stacks->moves->ra = i + 1;
		}
		else
		{
			if (i > size / 2)
				stacks->moves->rra = (size - i) - 1;
			else
				stacks->moves->ra = i + 1;
		}
	}
	do_moves_max_stack_a(stacks);
}

void	do_moves_max_stack_a(t_stacks *stacks)
{
	while (stacks->moves->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->moves->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	ft_push(stacks, 'a');
	ft_rotate(stacks, 'a');
}
