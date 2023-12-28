/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max_min_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:20:44 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/28 16:48:17 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_max_min_a(t_stacks *stacks)
{
	check_max_a(stacks, stacks->head_a);
	check_min_a(stacks, stacks->head_a);
}

void	check_max_a(t_stacks *stacks, t_stack_a *head_a)
{
	int	i;
	int	size;

	i = 0;
	size = ft_listsize_a(head_a);
	stacks->values->max_a = head_a->content;
	while (i < size)
	{
		if (stacks->values->max_a < head_a->content)
			stacks->values->max_a = head_a->content;
		head_a = head_a->next;
		i++;
	}
}

void	check_min_a(t_stacks *stacks, t_stack_a *head_a)
{
	int	i;
	int	size;

	i = 0;
	size = ft_listsize_a(head_a);
	stacks->values->min_a = head_a->content;
	while (i < size)
	{
		if (stacks->values->min_a > head_a->content)
			stacks->values->min_a = head_a->content;
		head_a = head_a->next;
		i++;
	}
}
