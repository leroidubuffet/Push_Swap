/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:12:37 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/28 16:48:17 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sorts three elements of the stack by applying appropriate operations.
 *
 * @param stacks - Container holding both stacks.
 * @param num1, num2, num3 - The three elements to sort.
 */
static void	ft_sort_three_elements(t_stacks *stacks, int num1,
	int num2, int num3)
{
	if (num1 > num2 && num1 < num3 && num2 < num3)
		ft_swap(stacks, 'a');
	else if (num1 > num2 && num1 > num3 && num2 < num3)
		ft_rotate(stacks, 'a');
	else if (num1 < num2 && num1 > num3 && num2 > num3)
		ft_rev_rotate(stacks, 'a');
	else if (num1 > num2 && num1 > num3 && num2 > num3)
	{
		ft_swap(stacks, 'a');
		ft_rev_rotate(stacks, 'a');
	}
	else if (num1 < num2 && num1 < num3 && num2 > num3)
	{
		ft_swap(stacks, 'a');
		ft_rotate(stacks, 'a');
	}
}

/**
 * Sorts a stack with exactly three elements.
 *
 * @param stacks - Container holding both stacks.
 * @param clear - Indicates whether nodes should be cleared.
 */
void	ft_sort_three(t_stacks *stacks, bool clear)
{
	t_stack_a	*head_a;
	int			num1;
	int			num2;
	int			num3;

	if (!stacks || !stacks->head_a || !stacks->head_a->next
		|| !stacks->head_a->next->next)
		return ;
	head_a = stacks->head_a;
	num1 = head_a->content;
	num2 = head_a->next->content;
	num3 = head_a->next->next->content;
	ft_sort_three_elements(stacks, num1, num2, num3);
	if (clear)
		ft_clearnodes_a(&stacks->head_a);
}
