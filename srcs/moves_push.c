/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:40:17 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/30 18:34:07 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Determines the appropriate push operation based on the specified
 * stack ('a' or 'b'). Directs the push operation from stack B
 * to A or from A to B accordingly. Ensures that the operation
 * is only performed if the source stack is not empty.
 *
 * @param stacks - A pointer to the struct containing both
 * stack A and stack B.
 * @param ch - A character indicating the target stack ('a' for stack A,
 * 'b' for stack B).
 */
void	ft_push(t_stacks *stacks, char ch)
{
	if (ch == 'a')
		ft_push_a(stacks);
	else if (ch == 'b')
		ft_push_b(stacks);
}

/**
 * Performs the push operation from stack B to stack A.
 * Moves the top element of stack B to the top of stack A.
 * Updates the head pointers of both stacks and ensures
 * proper memory management by freeing the old head of stack B.
 * Records the operation by printing "pa".
 *
 * @param stacks - A pointer to the struct containing both
 * stack A and stack B.
 */
void	ft_push_a(t_stacks *stacks)
{
	t_stack_a	*new_head_a;
	t_stack_b	*old_head_b;

	if (stacks->head_b == NULL)
		return ;
	new_head_a = ft_newnode_a(stacks->head_b->content);
	new_head_a->next = stacks->head_a;
	stacks->head_a = new_head_a;
	old_head_b = stacks->head_b;
	stacks->head_b = stacks->head_b->next;
	free (old_head_b);
	ft_putstr("pa\n");
}

/**
 * Performs the push operation from stack A to stack B.
 * Moves the top element of stack A to the top of stack B.
 * Updates the head pointers of both stacks and ensures
 * proper memory management by freeing the old head of stack A.
 * Records the operation by printing "pb".
 *
 * @param stacks - A pointer to the struct containing both stack A and stack B.
 */
void	ft_push_b(t_stacks *stacks)
{
	t_stack_b	*new_head_b;
	t_stack_a	*old_head_a;

	if (stacks->head_a == NULL)
		return ;
	new_head_b = ft_newnode_b(stacks->head_a->content);
	new_head_b->next = stacks->head_b;
	stacks->head_b = new_head_b;
	old_head_a = stacks->head_a;
	stacks->head_a = stacks->head_a->next;
	free (old_head_a);
	ft_putstr("pb\n");
}
