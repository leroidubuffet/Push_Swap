/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:53:24 by airyago           #+#    #+#             */
/*   Updated: 2023/12/27 09:00:46 by airyago          ###   ########.fr       */
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

void	ft_move_min_to_top_a(t_stacks *stacks)
{
	int min_index;
	int stack_size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->head_a->data == stacks->values->min_a)
		return;
	min_index = ft_find_index_a(stacks, stacks->values->min_a);
	stack_size = ft_listsize(stacks->head_a);
	if ((stack_size % 2 == 0 && min_index + 1 > stack_size / 2) || (min_index > stack_size / 2))
		stacks->moves->rra = stack_size - min_index;
	else
		stacks->moves->ra = min_index;
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

int	ft_find_index_a(t_stacks *stacks, int target_num)
{
	t_stack	*current_node;
	int 	index;
	int 	stack_size;

	if (stacks == NULL || stacks->head_a == NULL)
		return (-1);
	current_node = stacks->head_a;
	index = 0;
	stack_size = ft_listsize(stacks->head_a);
	while (index < stack_size)
	{
		if (current_node->data == target_num)
			return (index);
		current_node = current_node->next;
		index++;
	}
	return (-1);
}

