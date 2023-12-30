/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:03:26 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/30 16:45:24 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Checks if the stack can be rotated.
 *
 * @param head The start of the stack.
 * @return true if the stack can be rotated, false otherwise.
 */
static bool can_rotate(void *head)
{
	t_stack_a *stack_head = (t_stack_a*)head;
	return (stack_head && stack_head->next);
}
/**
 * Reverses the order of elements in the stack.
 * If 'a' is passed, it rotates stack A, if 'b', then stack B, if 'r', then both.
 *
 * @param stacks The container holding both stacks.
 * @param ch The character indicating which stack to rotate ('a', 'b', or 'r').
 */
void ft_rev_rotate(t_stacks *stacks, char ch)
{
	if (!stacks)
		return ;
	if (ch == 'a' && can_rotate(stacks->head_a))
		ft_rev_rotate_a(stacks, 1);
	else if (ch == 'b' && can_rotate((t_stack_b *)stacks->head_b))
		ft_rev_rotate_b(stacks, 1);
	else if (ch == 'r') {
		if (can_rotate(stacks->head_a) && can_rotate((t_stack_b *)stacks->head_b)) {
			ft_rev_rotate_a(stacks, 0);
			ft_rev_rotate_b(stacks, 0);
			ft_putstr("rrr\n");
		}
	}
}

/**
 * Performs a reverse rotation on stack A.
 *
 * @param stacks The container holding both stacks.
 * @param print Indicates whether to output the operation to the standard output.
 */
void ft_rev_rotate_a(t_stacks *stacks, int print)
{
	t_stack_a *last;
	t_stack_a *before_last;

	if (!stacks || !stacks->head_a || !stacks->head_a->next)
		return ;
	last = stacks->head_a;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	if (before_last) before_last->next = NULL;
	last->next = stacks->head_a;
	stacks->head_a = last;
	if (print)
		ft_putstr("rra\n");
}

/**
 * Performs a reverse rotation on stack B.
 *
 * @param stacks The container holding both stacks.
 * @param print Indicates whether to output the operation to the standard output.
 */
void ft_rev_rotate_b(t_stacks *stacks, int print)
{
	t_stack_b *last;
	t_stack_b *before_last;

	if (!stacks || !stacks->head_b || !stacks->head_b->next)
		return ;
	last = stacks->head_b;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	if (before_last) before_last->next = NULL;
	last->next = stacks->head_b;
	stacks->head_b = last;
	if (print)
		ft_putstr("rrb\n");
}

