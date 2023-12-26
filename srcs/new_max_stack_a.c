/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_max_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:43:17 by airyago           #+#    #+#             */
/*   Updated: 2023/12/26 18:59:45 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_max_a(t_stacks *stacks)
{
	int	index;
	int	stack_size;

	if (ft_lstlast(stacks->head_a)->data != stacks->values->max_a)
	{
		index = find_index_stack_a(stacks, stacks->values->max_a);
		stack_size = ft_listsize(stacks->head_a);

		if ((stack_size % 2 == 0 && index + 1 > stack_size / 2) || (index > stack_size / 2))
			stacks->moves->rra = stack_size - index - 1;
		else
			stacks->moves->ra = index + 1;
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
