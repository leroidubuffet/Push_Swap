/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:08:41 by airyago           #+#    #+#             */
/*   Updated: 2023/08/21 19:12:44 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_order_three(t_stack *stack)
{
	t_node	*temp;
	int		max_val;
	int		min_val;

	temp = stack->head;
	max_val = ft_find_max(stack);
	min_val = ft_find_min(stack);
	while (stack->tail->data != max_val)
	{
		rra(stack);
	}
	while (stack->head->data != min_val)
	{
		sa(stack);
	}
}

void	ft_order_four(t_stack *stack)
{
	t_node	*temp;
	t_stack	*stack_b;
	int		min_val;

	temp = stack->head;
	stack_b = ft_new_stack();
	min_val = ft_find_min(stack);
	while (stack->head->data != min_val)
		rra(stack);
	pb(stack, stack_b);
	ft_order_three(stack);
	pa(stack, stack_b);
}

void	ft_order_five(t_stack *stack)
{
	t_node	*temp;
	t_stack	*stack_b;
	int		min_val;

	temp = stack->head;
	stack_b = ft_new_stack();
	min_val = ft_find_min(stack);
	while (stack->head->data != min_val)
		rra(stack);
	pb(stack, stack_b);
	ft_order_four(stack);
	pa(stack, stack_b);
}

void	ft_order_small_stack(t_stack *stack, int argc)
{
	t_node	*temp_head;
	t_node	*temp_tail;

	temp_head = stack->head;
	temp_tail = stack->tail;
	if (argc == 3 && !ft_is_sorted(stack))
		sa(stack);
	if (argc == 4 && !ft_is_sorted(stack))
	{
		ft_order_three(stack);
	}
	if (argc == 5 && !ft_is_sorted(stack))
	{
		ft_order_four(stack);
	}
	if (argc == 6 && !ft_is_sorted(stack))
	{
		ft_order_five(stack);
	}
}

