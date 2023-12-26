/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_max_min_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:20:44 by airyago           #+#    #+#             */
/*   Updated: 2023/12/21 18:01:38 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_max_min_a(t_stacks *stacks)
{
	ft_check_max_a(stacks, stacks->head_a);
	ft_check_min_a(stacks, stacks->head_a);
}

void	ft_check_max_a(t_stacks *stacks, t_stack *head_a)
{
	int	i;
	int	size;

	i = 0;
	size = ft_listsize(head_a);
	stacks->values->max_a = head_a->data;
	while (i < size)
	{
		if (stacks->values->max_a < head_a->data)
			stacks->values->max_a = head_a->data;
		head_a = head_a->next;
		i++;
	}
}

void	ft_check_min_a(t_stacks *stacks, t_stack *head_a)
{
	int	i;
	int	size;

	i = 0;
	size = ft_listsize(head_a);
	stacks->values->min_a = head_a->data;
	while (i < size)
	{
		if (stacks->values->min_a > head_a->data)
			stacks->values->min_a = head_a->data;
		head_a = head_a->next;
		i++;
	}
}
