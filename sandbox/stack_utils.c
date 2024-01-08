/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:16:28 by ybolivar          #+#    #+#             */
/*   Updated: 2023/08/29 15:57:39 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_node	*ft_allocate_node(void)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	return (new_node);
}

t_stack	ft_create_stack(void)
{
	t_stack	stack;

	stack.head = NULL;
	stack.tail = NULL;
	return (stack);
}

void	ft_free_stack(t_stack **stack)
{
	t_node	*current;
	t_node	*next_node;

	if (!stack || !*stack)
		return ;

	current = (*stack)->head;

	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}

	free(*stack);
	*stack = NULL;
}

t_node	*ft_create_node(int data)
{
	t_node	*new_node;

	new_node = ft_allocate_node();
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

bool	ft_is_sorted(t_stack *stack)
{
	t_node	*temp;

	temp = stack->head;
	while (temp && temp->next)
	{
		if (temp->data > temp->next->data)
			return (false);
		temp = temp->next;
	}
	return (true);
}
