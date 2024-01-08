/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:48:50 by airyago           #+#    #+#             */
/*   Updated: 2023/08/16 17:14:13 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack *stack_a)
{
	ft_rotate(stack_a);
	ft_putstr("ra\n");
}

void	rb(t_stack *stack_b)
{
	ft_rotate(stack_b);
	ft_putstr("rb\n");
}
