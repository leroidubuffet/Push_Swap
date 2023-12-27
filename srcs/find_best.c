/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago  <airyago @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:29:24 by airyago           #+#    #+#             */
/*   Updated: 2023/08/31 16:19:56 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Iteratively moves the best candidate element from stack_a to stack_b
 * until only three elements are left in stack_a. Determines the best moves
 * based on the current state and performs them.
 *
 * @param stacks - Container holding both stacks and metadata for moves.
 */
void ft_move_best(t_stacks *stacks)
{
	if (!stacks)
		return;
	stacks->moves = ft_calloc(1, sizeof(t_moves));
	stacks->best = ft_calloc(1, sizeof(t_best));
	stacks->values = ft_calloc(1, sizeof(t_values));
	if (!stacks->moves || !stacks->best || !stacks->values)
		return ;
	while (ft_listsize(stacks->head_a) != 3)
	{
		ft_check_limits_b(stacks);
		ft_check_moves(stacks);
		ft_run_moves(stacks);
	}
}

void	ft_run_moves(t_stacks *stacks)
{
	while (stacks->best->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->best->rb-- != 0)
		ft_rotate(stacks, 'b');
	while (stacks->best->rr-- != 0)
		ft_rotate(stacks, 'r');
	while (stacks->best->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	while (stacks->best->rrb-- != 0)
		ft_rev_rotate(stacks, 'b');
	while (stacks->best->rrr-- != 0)
		ft_rev_rotate(stacks, 'r');
	while (stacks->best->pb-- != 0)
		ft_push(stacks, 'b');
}

int	ft_find_destination(t_stacks *stacks, int num)
{
	t_stack	*head_b;
	int			size;
	bool		flag;
	int			i;

	i = 0;
	flag = false;
	head_b = stacks->head_b;
	size = ft_listsize(stacks->head_b);
	while (flag == false)
	{
		i = 0;
		num--;
		head_b = stacks->head_b;
		while (i++ < size)
		{
			if (head_b->data == num)
				flag = true;
			head_b = head_b->next;
		}
	}
	return (num);
}

int	ft_find_index_b(t_stacks *stacks, int target_num)
{
	t_stack	*current_node;
	int		size;
	int		index;

	if (stacks == NULL || stacks->head_b == NULL)
		return (-1);
	current_node = stacks->head_b;
	size = ft_listsize(stacks->head_b);
	index = 0;
	while (index < size)
	{
		if (current_node->data == target_num)
			break ;
		current_node = current_node->next;
		index++;
	}
	return (index);
}
