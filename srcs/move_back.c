/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:53:24 by airyago           #+#    #+#             */
/*   Updated: 2023/12/26 19:22:00 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reorder_a(t_stacks *stacks)
{
	while (stacks->head_b != NULL)
	{
		ft_check_limits_a(stacks);
		if (stacks->head_b->data < stacks->values->min_a)
			ft_rotate_min_a(stacks);
		else if (stacks->head_b->data > stacks->values->max_a)
			ft_rotate_max_a(stacks);
		else
			new_elem_stack_a(stacks, stacks->head_b);
	}
	ft_check_limits_a(stacks);
	ft_move_min_to_top_a(stacks);
}

void ft_move_min_to_top_a(t_stacks *stacks)
{
	int min_index;
	int stack_size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->head_a->data == stacks->values->min_a)
		return;
	min_index = find_index_stack_a(stacks, stacks->values->min_a);
	stack_size = ft_listsize(stacks->head_a);
	if ((stack_size % 2 == 0 && min_index + 1 > stack_size / 2) || (min_index > stack_size / 2))
		stacks->moves->rra = stack_size - min_index; // Closer to the end; use reverse rotate.
	else
		stacks->moves->ra = min_index; // Closer to the start; use rotate.
	ft_apply_rotations_a(stacks);
}

void	ft_apply_rotations_a(t_stacks *stacks)
{
	if (stacks == NULL)
		return;
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
