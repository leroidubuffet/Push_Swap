/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:34:22 by airyago           #+#    #+#             */
/*   Updated: 2023/12/27 08:33:52 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Rotates the specified stack(s) within the given t_stacks container.
 * 'a' rotates stack_a, 'b' rotates stack_b, and 'r' rotates both stacks simultaneously.
 *
 * @param stacks The container holding the stacks.
 * @param ch The character indicating which stack(s) to rotate: 'a', 'b', or 'r' for both.
 */
void ft_rotate(t_stacks *stacks, char ch)
{
	if (!stacks)
		return;
	if (ch == 'a')
		ft_rotate_a(stacks, 1);
	else if (ch == 'b')
		ft_rotate_b(stacks, 1);
	else if (ch == 'r')
	{
		if (stacks->head_a && stacks->head_a->next && stacks->head_b && stacks->head_b->next)
		{
			ft_rotate_a(stacks, 0);
			ft_rotate_b(stacks, 0);
			ft_putstr("rr\n");
		}
	}
}

/**
 * Rotates elements in the specified stack(s) within the given t_stacks container.
 * It can rotate stack_a ('a'), stack_b ('b'), or both stacks simultaneously ('r').
 *
 * @param stacks - The container holding the stacks.
 * @param ch - The character indicating which stack(s) to rotate:
 *             'a' for stack_a, 'b' for stack_b, or 'r' for both stacks.
 */
void ft_rotate_stack(t_stack **head, int print, char *rotation_message)
{
	t_stack	*first_element;
	t_stack	*current;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	first_element = *head;
	*head = first_element->next;
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = first_element;
	first_element->next = NULL;
	if (print != 0)
		ft_putstr(rotation_message);
}

void ft_rotate_a(t_stacks *stacks, int print)
{
	ft_rotate_stack(&stacks->head_a, print, "ra\n");
}

void ft_rotate_b(t_stacks *stacks, int print)
{
	ft_rotate_stack(&stacks->head_b, print, "rb\n");
}
