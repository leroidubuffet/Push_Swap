/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:35:04 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/28 18:57:34 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Swaps the first two elements of stack A.
 * If there are at least two elements, their values are swapped.
 * Records the operation by printing "sa" if the print flag is set.
 *
 * @param head_a - The top node of stack A.
 * @param print - Flag indicating whether to print the operation.
 */
static void ft_swap_a(t_stack_a *head_a, bool print)
{
	int tmp;

	if (head_a && head_a->next)
	{
		tmp = head_a->content;
		head_a->content = head_a->next->content;
		head_a->next->content = tmp;
		if (print)
			ft_putstr("sa\n");
	}
}

/**
 * Swaps the first two elements of stack B.
 * If there are at least two elements, their values are swapped.
 * Records the operation by printing "sb" if the print flag is set.
 *
 * @param head_b - The top node of stack B.
 * @param print - Flag indicating whether to print the operation.
 */
static void ft_swap_b(t_stack_b *head_b, bool print)
{
	int tmp;

	if (head_b && head_b->next)
	{
		tmp = head_b->content;
		head_b->content = head_b->next->content;
		head_b->next->content = tmp;
		if (print)
			ft_putstr("sb\n");
	}
}

/**
 * Determines and executes the swap operation on the specified stack or both stacks simultaneously.
 * It swaps the first two elements at the top of the stack(s) if they exist.
 *
 * @param stacks - A pointer to the struct containing both stack A and stack B.
 * @param ch - A character indicating the target stack ('a' for stack A, 'b' for stack B, 's' for both stacks).
 */
void ft_swap(t_stacks *stacks, char ch)
{
	if (ch == 'a')
		ft_swap_a(stacks->head_a, true);
	else if (ch == 'b' && stacks->head_b && stacks->head_b->next)
		ft_swap_b(stacks->head_b, true);
	else if (ch == 's' && stacks->head_a && stacks->head_a->next && stacks->head_b && stacks->head_b->next)
	{
		ft_swap_a(stacks->head_a, false);
		ft_swap_b(stacks->head_b, false);
		ft_putstr("ss\n");
	}
}
