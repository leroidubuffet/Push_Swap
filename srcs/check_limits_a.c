/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limits_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:20:44 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/30 18:25:44 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Finds and updates the maximum value in stack A.
 *
 * @param stacks - The container holding both stacks and their operational data.
 * @param head_a - The head node of stack A.
 */
static void	check_max_a(t_stacks *stacks, t_stack_a *head_a)
{
	int	index;
	int	stack_size;

	index = 0;
	stack_size = ft_listsize_a(head_a);
	stacks->values->max_a = head_a->content;
	while (index < stack_size)
	{
		if (stacks->values->max_a < head_a->content)
			stacks->values->max_a = head_a->content;
		head_a = head_a->next;
		index++;
	}
}

/**
 * Finds and updates the minimum value in stack A.
 *
 * @param stacks - The container holding both stacks and their operational data.
 * @param head_a - The head node of stack A.
 */
static void	check_min_a(t_stacks *stacks, t_stack_a *head_a)
{
	int	index;
	int	stack_size;

	index = 0;
	stack_size = ft_listsize_a(head_a);
	stacks->values->min_a = head_a->content;
	while (index < stack_size)
	{
		if (stacks->values->min_a > head_a->content)
			stacks->values->min_a = head_a->content;
		head_a = head_a->next;
		index++;
	}
}

/**
 * Finds and updates the maximum and minimum values in stack A.
 *
 * @param stacks - The container holding both stacks.
 */
void	ft_check_limits_a(t_stacks *stacks)
{
	check_max_a(stacks, stacks->head_a);
	check_min_a(stacks, stacks->head_a);
}
