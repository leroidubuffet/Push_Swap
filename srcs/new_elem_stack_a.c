/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elem_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:15:50 by airyago           #+#    #+#             */
/*   Updated: 2023/12/27 19:09:55 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_elem_stack_a(t_stacks *stacks, t_stack *head_b)
{
	int	i;
	int	size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->head_a->data != search_stack_a(stacks, head_b->data))
	{
		i = ft_find_index_a(stacks, search_stack_a(stacks, head_b->data));
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
