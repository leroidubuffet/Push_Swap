/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max_min_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:20:22 by airyago           #+#    #+#             */
/*   Updated: 2023/12/21 18:01:38 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_max_min_b(t_stacks *stacks)
{
	if (stacks->head_b != NULL)
	{
		check_max_b(stacks, stacks->head_b);
		check_min_b(stacks, stacks->head_b);
	}
}

void	check_min_b(t_stacks *stacks, t_stack *head_b)
{
	int	i;
	int	size;

	i = 0;
	size = ft_listsize(head_b);
	stacks->values->min_b = head_b->data;
	while (i < size)
	{
		if (stacks->values->min_b > head_b->data)
			stacks->values->min_b = head_b->data;
		head_b = head_b->next;
		i++;
	}
}

void	check_max_b(t_stacks *stacks, t_stack *head_b)
{
	int	i;
	int	size;

	i = 0;
	size = ft_listsize(head_b);
	stacks->values->max_b = head_b->data;
	while (i < size)
	{
		if (stacks->values->max_b < head_b->data)
			stacks->values->max_b = head_b->data;
		head_b = head_b->next;
		i++;
	}
}
