/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_min_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:44:31 by airyago           #+#    #+#             */
/*   Updated: 2023/12/26 19:27:28 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_min_a(t_stacks *stacks)
{
	int	index;
	int	stack_size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->head_a->data != stacks->values->min_a)
	{
		index = find_index(stacks, stacks->values->min_a);
		stack_size = ft_listsize(stacks->head_a);

		if ((stack_size % 2 == 0 && index + 1 > stack_size / 2) || (index > stack_size / 2))
			stacks->moves->rra = stack_size - index;
		else
			stacks->moves->ra = index;
	}
	ft_place_min_a(stacks);
}

void	ft_place_min_a(t_stacks *stacks)
{
	while (stacks->moves->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->moves->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	ft_push(stacks, 'a');
}
