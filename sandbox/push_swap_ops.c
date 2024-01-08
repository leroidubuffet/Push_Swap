/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:47:04 by airyago           #+#    #+#             */
/*   Updated: 2023/08/31 11:10:53 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack *stack_a)
{
	ft_swap(stack_a);
	ft_putstr("sa\n");
}

void	sb(t_stack *stack_b)
{
	ft_swap(stack_b);
	ft_putstr("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putstr("ss\n");
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_a, stack_b);
	ft_putstr("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_b, stack_a);
	ft_putstr("pb\n");
}
