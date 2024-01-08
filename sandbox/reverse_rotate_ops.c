/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:50:44 by airyago           #+#    #+#             */
/*   Updated: 2023/08/31 11:27:13 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putstr("rr\n");
}

void	rra(t_stack *stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_putstr("rra\n");
}

void	rrb(t_stack *stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_putstr("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_putstr("rrr\n");
}
