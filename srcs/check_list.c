/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:46:08 by airyago           #+#    #+#             */
/*   Updated: 2023/12/27 08:04:57 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Checks if the elements in stack_a of t_stacks are in ascending order.
 *
 * @param stacks The container holding the stack to be checked.
 * @return True if the elements are in ascending order, false otherwise.
 */
bool ft_check_list_order(t_stacks *stacks)
{
	t_stack	*current_node;
	int		last_value;
	int		stack_size;
	int		i;

	if (!stacks || !stacks->head_a)
		return (false);
	current_node = stacks->head_a;
	last_value = current_node->data;
	stack_size = ft_listsize(stacks->head_a);
	i = 1;
	while (i < stack_size)
	{
		current_node = current_node->next;
		if (!current_node)
			return (false);
		if (last_value > current_node->data)
			return (false);
		last_value = current_node->data;
		i++;
	}
	return (true);
}

