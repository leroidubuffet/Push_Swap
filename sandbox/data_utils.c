/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:11:47 by airyago           #+#    #+#             */
/*   Updated: 2023/08/21 19:12:23 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_find_min(t_stack *stack)
{
	t_node	*temp;
	int		min;

	temp = stack->head;
	min = temp->data;
	while (temp)
	{
		if (temp->data < min)
			min = temp->data;
		temp = temp->next;
	}
	return (min);
}

int	ft_find_max(t_stack *stack)
{
	t_node	*temp;
	int		max;

	temp = stack->head;
	max = temp->data;
	while (temp)
	{
		if (temp->data > max)
			max = temp->data;
		temp = temp->next;
	}
	return (max);
}
