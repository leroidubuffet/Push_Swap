/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:26:47 by airyago           #+#    #+#             */
/*   Updated: 2023/08/31 11:32:55 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	temp;

	temp = 0;
	if (stack->head != NULL && stack->head->next != NULL)
	{
		temp = stack->head->position;
		stack->head->position = stack->head->next->position;
		stack->head->next->position = temp;
	}
}

void	ft_rotate(t_stack *stack)
{
	t_node	*last;

	if (stack->head != NULL && stack->head->next != NULL)
	{
		last = stack->head;
		stack->head = stack->head->next;
		stack->tail->next = last;
		last->next = NULL;
		stack->tail = last;
	}
}

void	ft_reverse_rotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	prev = NULL;
	last = stack->head;
	if (stack->head != NULL && stack->head->next != NULL)
	{
		while (last->next != NULL)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = stack->head;
		stack->head = last;
		stack->tail = prev;
	}
}

void	ft_push(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (stack_b->head != NULL)
	{
		temp = stack_b->head;
		stack_b->head = stack_b->head->next;
		if (stack_b->head == NULL)
			stack_b->tail = NULL;
		temp->next = stack_a->head;
		stack_a->head = temp;
		if (stack_a->tail == NULL)
			stack_a->tail = temp;
	}
}

