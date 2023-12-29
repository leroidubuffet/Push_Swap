/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:46:08 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/29 12:37:29 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Checks if the elements in stack 'a' are in ascending order.
 *
 * @param stacks - The container holding both stacks.
 * @return Returns 1 if the stack is in order, 0 otherwise.
 */
bool ft_check_order(t_stacks *stacks)
{
	t_stack_a	*current_node;
	int			last_value;

	if (!stacks || !stacks->head_a || !stacks->head_a->next)
		return (1);
	current_node = stacks->head_a;
	last_value = current_node->content;
	current_node = current_node->next;
	while (current_node)
	{
		if (last_value > current_node->content)
			return (0);
		last_value = current_node->content;
		current_node = current_node->next;
	}
	return (1);
}

