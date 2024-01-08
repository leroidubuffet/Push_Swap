/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:08:50 by airyago           #+#    #+#             */
/*   Updated: 2023/09/01 10:57:11 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_node	*ft_find_second_last(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current->next != stack->tail && current->next != NULL) 
	{
		current = current->next;
	}
	return (current);
}

bool	ft_check_sa(t_stack *stack)
{
	if (!stack || !stack->head || !stack->head->next)
		return (false);
	return (stack->head->position > stack->head->next->position);
}

bool	ft_check_sb(t_stack *stack)
{
	if (!stack || !stack->head || !stack->head->next)
		return (false);
	return (stack->head->position < stack->head->next->position);
}

bool	ft_check_ss(t_stack *stack_a, t_stack *stack_b)
{
	return (ft_check_sa(stack_a) && ft_check_sb(stack_b));
}

bool	ft_check_ra(t_stack *stack)
{
	if (!stack || !stack->head || !stack->head->next)
		return (false);
	return (stack->head->position < stack->head->next->position);
}

bool	ft_check_rb(t_stack *stack)
{
	if (!stack || !stack->head || !stack->head->next)
		return (false);
	return (stack->head->position > stack->head->next->position);
}

bool	ft_check_rr(t_stack *stack_a, t_stack *stack_b)
{
	return (ft_check_ra(stack_a) && ft_check_rb(stack_b));
}

bool ft_check_rra(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || !stack->tail)
	{
		return (false);
	}

	last = stack->tail;
	second_last = ft_find_second_last(stack);
	if (!second_last)
	{
		return (false);
	}
	return (last->position > second_last->position);
}

bool ft_check_rrb(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || !stack->tail)
		return (false);
	last = stack->tail;
	second_last = ft_find_second_last(stack);
	if (!second_last)
		return (false);
	return (last->position < second_last->position);
}

bool	ft_check_rrr(t_stack *stack_a, t_stack *stack_b)
{
	return (ft_check_rra(stack_a) && ft_check_rrb(stack_b));
}
