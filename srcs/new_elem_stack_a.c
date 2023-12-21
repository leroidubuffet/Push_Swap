/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_top_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:15:50 by airyago           #+#    #+#             */
/*   Updated: 2023/12/21 20:52:00 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_move_top_a(t_stacks *stacks, t_stack *head_b)
{
	int	target_index;
	int	stack_size;
	int	target_value;

	target_value = search_stack_a(stacks, head_b->data);
	if (stacks->head_a->data != target_value)
	{
		target_index = find_index_stack_a(stacks, target_value);
		stack_size = ft_listsize(stacks->head_a);

		if ((stack_size % 2 == 0 && target_index + 1 > stack_size / 2) || (target_index > stack_size / 2))
			stacks->moves->rra = stack_size - target_index;
		else
			stacks->moves->ra = target_index;
	}
	do_moves_elem_stack_a(stacks);
}

void	do_moves_elem_stack_a(t_stacks *stacks)
{
	while (stacks->moves->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->moves->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	ft_push(stacks, 'a');
}

int	search_stack_a(t_stacks *stacks, int num)
{
	t_stack	*head_a;
	int			size;
	int			flag;
	int			i;

	i = 0;
	flag = 0;
	head_a = stacks->head_a;
	size = ft_listsize(stacks->head_a);
	while (flag == 0)
	{
		i = 0;
		num++;
		head_a = stacks->head_a;
		while (i++ < size)
		{
			if (head_a->data ==num)
				flag = 1;
			head_a = head_a->next;
		}
	}
	return (num);
}
