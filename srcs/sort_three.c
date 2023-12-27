/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:12:37 by airyago           #+#    #+#             */
/*   Updated: 2023/12/20 13:23:57 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sorts a stack with exactly three elements.
 *
 * @param stacks - Container holding both stacks.
 * @param flag - Indicates whether additional action (currently unspecified) should be taken.
 */
void	ft_sort_three(t_stacks *stacks, bool clear)
{
	t_stack	*head_a;
	int			num1;
	int			num2;
	int			num3;

	if (!stacks || !stacks->head_a || !stacks->head_a->next || !stacks->head_a->next->next)
		return ;
	head_a = stacks->head_a;
	num1 = head_a->data;
	num2 = head_a->next->data;
	num3 = head_a->next->next->data;
	ft_identify_nums_three(stacks, num1, num2, num3);
	if (clear)
	{
		ft_clearnodes(&stacks->head_a);
		exit(0);
	}
}

void	ft_identify_nums_three(t_stacks *stacks, int num1, int num2, int num3)
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
