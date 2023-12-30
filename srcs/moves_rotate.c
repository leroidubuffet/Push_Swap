/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:34:22 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/30 18:39:54 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Returns the last node of stack A.
 *
 * @param head_a - The top node of stack A.
 * @return t_stack_a* - The last node in stack A.
 */
t_stack_a	*ft_listlast_a(t_stack_a *head_a)
{
	if (!head_a)
		return (NULL);
	while (head_a->next)
		head_a = head_a->next;
	return (head_a);
}

/**
 * Returns the last node of stack B.
 *
 * @param head_b - The top node of stack B.
 * @return t_stack_b* - The last node in stack B.
 */
static t_stack_b	*ft_listlast_b(t_stack_b *head_b)
{
	if (!head_b)
		return (NULL);
	while (head_b->next)
		head_b = head_b->next;
	return (head_b);
}

/**
 * Rotates stack A upwards. The top element becomes the last one.
 * If indicated, prints the operation to the console.
 *
 * @param stacks - Container holding both stacks.
 * @param print - Boolean indicating whether to print the operation.
 */
static void	ft_rotate_a(t_stacks *stacks, bool print)
{
	t_stack_a	*tmp_head;
	t_stack_a	*last;

	if (!stacks || !stacks->head_a || !stacks->head_a->next)
		return ;
	tmp_head = stacks->head_a;
	stacks->head_a = tmp_head->next;
	last = ft_listlast_a(stacks->head_a);
	last->next = tmp_head;
	tmp_head->next = NULL;
	if (print)
		ft_putstr("ra\n");
}

/**
 * Rotates stack B upwards. The top element becomes the last one.
 * If indicated, prints the operation to the console.
 *
 * @param stacks - Container holding both stacks.
 * @param print - Boolean indicating whether to print the operation.
 */
static void	ft_rotate_b(t_stacks *stacks, bool print)
{
	t_stack_b	*tmp_head;
	t_stack_b	*last;

	if (!stacks || !stacks->head_b || !stacks->head_b->next)
		return ;
	tmp_head = stacks->head_b;
	stacks->head_b = tmp_head->next;
	last = ft_listlast_b(stacks->head_b);
	last->next = tmp_head;
	tmp_head->next = NULL;
	if (print)
		ft_putstr("rb\n");
}

/**
 * Rotates the specified stack upwards.
 * The top element becomes the last one, and all other elements
 * move up by one position.
 *
 * @param stacks - A pointer to the struct containing both stack A and stack B.
 * @param ch - A character indicating the target stack ('a' for stack A, 'b'
 * for stack B, 'r' for both stacks).
 */
void	ft_rotate(t_stacks *stacks, char ch)
{
	if (ch == 'a' && stacks->head_a && stacks->head_a->next)
		ft_rotate_a(stacks, true);
	else if (ch == 'b' && stacks->head_b && stacks->head_b->next)
		ft_rotate_b(stacks, true);
	else if (ch == 'r' && stacks->head_a && stacks->head_a->next
		&& stacks->head_b && stacks->head_b->next)
	{
		ft_rotate_a(stacks, false);
		ft_rotate_b(stacks, false);
		ft_putstr("rr\n");
	}
}
