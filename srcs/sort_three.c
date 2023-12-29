/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:12:37 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/29 13:16:56 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sorts a stack of exactly three elements using the fewest
 * possible operations.
 *
 * @param stacks - A pointer to the structure containing both stacks.
 * @param clear - A flag indicating whether to clear the stack and
 * exit after sorting.
 */
void	ft_sort_three(t_stacks *stacks, bool clear)
{
	int	num1;
	int	num2;
	int	num3;

	if (!stacks || !stacks->head_a || !stacks->head_a->next
		|| !stacks->head_a->next->next)
		return ;
	num1 = stacks->head_a->content;
	num2 = stacks->head_a->next->content;
	num3 = stacks->head_a->next->next->content;
	ft_execute_moves_three(stacks, num1, num2, num3);
	if (clear)
	{
		ft_clearnodes_a(&stacks->head_a);
		exit(0);
	}
}

/**
 * Executes the necessary moves to sort exactly three elements in a stack.
 *
 * @param stacks - A pointer to the structure containing both stacks.
 * @param num1 - The top element of the stack.
 * @param num2 - The middle element of the stack.
 * @param num3 - The bottom element of the stack.
 */
void	ft_execute_moves_three(t_stacks *stacks, int num1, int num2, int num3)
{
	if (num1 > num2 && num2 < num3 && num1 < num3)
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

