/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:40:17 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/28 17:57:38 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stacks *stacks, char ch)
{
	t_stack_b	*head_b;

	if (!stacks)
		return ;
	head_b = stacks->head_b;
	if (ch == 'a')
	{
		if (head_b == NULL)
			return ;
		else if (head_b->next == NULL)
			ft_last_push_a(stacks);
		else
			ft_push_a(stacks);
	}
	else if (ch == 'b')
	{
		if (head_b == NULL)
			ft_push_empty_b(stacks);
		else
			ft_push_b(stacks);
	}
}

void	ft_last_push_a(t_stacks *stacks)
{
	t_stack_a	*tmp_node;

	if (!stacks)
		return ;
	tmp_node = stacks->head_a;
	stacks->head_a = (t_stack_a *)stacks->head_b;
	stacks->head_a->next = tmp_node;
	stacks->head_b = NULL;
	ft_putstr("pa\n");
}

void ft_push_empty_b(t_stacks *stacks) {
    if (!stacks || !stacks->head_a) {
        // Handle error: either stacks is NULL or stack A is empty
        return;
    }

    // Create a new node for stack B with the content from the head of A
    t_stack_b *new_head_b = ft_newnode_b(stacks->head_a->content);
    if (!new_head_b) {
        // Handle error: failed to allocate memory for the new head of B
        return;
    }

    // Remove the head of A
    t_stack_a *old_head_a = stacks->head_a;
    stacks->head_a = old_head_a->next;

    // Set the new head of B
    new_head_b->next = stacks->head_b;
    stacks->head_b = new_head_b;

    // Free the old head of A
    free(old_head_a);

    ft_putstr("pb\n");
}


void	ft_push_b(t_stacks *stacks)
{
	t_stack_b	*tmp_node;

	if (!stacks)
		return ;
	tmp_node = stacks->head_b;
	stacks->head_b = (t_stack_b *)stacks->head_a;
	stacks->head_a = stacks->head_a->next;
	stacks->head_b->next = tmp_node;
	ft_putstr("pb\n");
}

void	ft_push_a(t_stacks *stacks)
{
	t_stack_a	*tmp_node;

	if (!stacks)
		return ;
	tmp_node = stacks->head_a;
	stacks->head_a = (t_stack_a *)stacks->head_b;
	stacks->head_b = stacks->head_b->next;
	stacks->head_a->next = tmp_node;
	ft_putstr("pa\n");
}
