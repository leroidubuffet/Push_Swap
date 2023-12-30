/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_limits_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:20:22 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/28 16:48:17 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Finds and updates the minimum value in stack B.
 *
 * @param stacks - The container holding both stacks and their operational data.
 * @param head_b - The head node of stack B.
 */
static void	check_min_b(t_stacks *stacks, t_stack_b *head_b)
{
	int	i;
	int	size;

	i = 0;
	size = ft_listsize_b(head_b);
	stacks->values->min_b = head_b->content;
	while (i < size)
	{
		if (stacks->values->min_b > head_b->content)
			stacks->values->min_b = head_b->content;
		head_b = head_b->next;
		i++;
	}
}

/**
 * Finds and updates the maximum value in stack B.
 *
 * @param stacks - The container holding both stacks and their operational data.
 * @param head_b - The head node of stack B.
 */
static void	check_max_b(t_stacks *stacks, t_stack_b *head_b)
{
	int	i;
	int	size;

	i = 0;
	size = ft_listsize_b(head_b);
	stacks->values->max_b = head_b->content;
	while (i < size)
	{
		if (stacks->values->max_b < head_b->content)
			stacks->values->max_b = head_b->content;
		head_b = head_b->next;
		i++;
	}
}
/**
 * Finds and updates the maximum and minimum values in stack A.
 *
 * @param stacks - The container holding both stacks.
 */
void	ft_check_limits_b(t_stacks *stacks)
{
	if (stacks->head_b != NULL)
	{
		check_max_b(stacks, stacks->head_b);
		check_min_b(stacks, stacks->head_b);
	}
}
