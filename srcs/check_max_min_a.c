/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max_min_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:55:32 by airyago           #+#    #+#             */
/*   Updated: 2023/12/27 20:55:40 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Checks and updates the maximum and minimum values in stack 'a'.
 * @param stacks - The container holding both stacks.
 */
void	ft_check_limits_a(t_stacks *stacks)
{
	if (!stacks)
		return ;
	ft_check_max_a(stacks, stacks->head_a);
	ft_check_min_a(stacks, stacks->head_a);
}

/**
 * Finds and updates the maximum value in stack 'a'.
 * @param stacks - The container holding both stacks.
 * @param head_a - The head of stack 'a'.
 */
void	ft_check_max_a(t_stacks *stacks, t_stack *head_a)
{
	int	index;
	int	stack_size;

	if (!head_a)
		return ;
	index = 0;
	stack_size = ft_listsize(head_a);
	stacks->values->max_a = head_a->data;
	while (index < stack_size)
	{
		if (stacks->values->max_a < head_a->data)
			stacks->values->max_a = head_a->data;
		head_a = head_a->next;
		index++;
	}
}

/**
 * Finds and updates the minimum value in stack 'a'.
 * @param stacks - The container holding both stacks.
 * @param head_a - The head of stack 'a'.
 */
void	ft_check_min_a(t_stacks *stacks, t_stack *head_a)
{
	int	index;
	int	size;

	if (!head_a)
		return ;
	index = 0;
	size = ft_listsize(head_a);
	stacks->values->min_a = head_a->data;
	while (index < size)
	{
		if (stacks->values->min_a > head_a->data)
			stacks->values->min_a = head_a->data;
		head_a = head_a->next;
		index++;
	}
}
