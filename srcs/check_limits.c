/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 23:04:52 by airyago           #+#    #+#             */
/*   Updated: 2023/12/27 23:34:15 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Checks and updates the maximum and minimum values for a specified
 * stack (either 'a' or 'b'). It determines which stack to operate on
 * based on the passed identifier and then updates the corresponding
 * values in the t_values structure within the t_stacks structure.
 *
 * @param stacks - A pointer to the t_stacks structure containing
 * both stack heads and values.
 * @param stack_identifier - A character indicating which stack
 * ('a' or 'b') to check.
 */
void	ft_check_limits(t_stacks *stacks, char stack_identifier)
{
	t_stack	*head;

	if (!stacks)
		return ;
	if (stack_identifier == 'a')
	{
		head = stacks->head_a;
		if (!head)
			return ;
		ft_check_max(head, &stacks->values->max_a);
		ft_check_min(head, &stacks->values->min_a);
	}
	else if (stack_identifier == 'b')
	{
		head = stacks->head_b;
		if (!head)
			return ;
		ft_check_max(head, &stacks->values->max_b);
		ft_check_min(head, &stacks->values->min_b);
	}
}

/**
 * Finds the maximum value in the given stack and updates the
 * corresponding maximum value in the provided integer pointer.
 * This function iterates through each node in the stack,
 * comparing and storing the highest value found.
 *
 * @param head - A pointer to the first node in the stack
 * whose maximum value is to be determined.
 * @param max_value - A pointer to an integer where
 * the maximum value found will be stored.
 */
void	ft_check_max(t_stack *head, int *max_value)
{
	if (!head || !max_value)
		return ;
	*max_value = head->data;
	while (head)
	{
		if (*max_value < head->data)
			*max_value = head->data;
		head = head->next;
	}
}

/**
 * Finds the minimum value in the given stack and updates
 * the corresponding minimum value in the provided integer
 * pointer. This function iterates through each node in the stack,
 * comparing and storing the lowest value found.
 *
 * @param head - A pointer to the first node in the stack
 * whose minimum value is to be determined.
 * @param min_value - A pointer to an integer where the
 * minimum value found will be stored.
 */
void	ft_check_min(t_stack *head, int *min_value)
{
	if (!head || !min_value)
		return ;
	*min_value = head->data;
	while (head)
	{
		if (*min_value > head->data)
			*min_value = head->data;
		head = head->next;
	}
}
