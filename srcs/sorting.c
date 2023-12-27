/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:59:54 by airyago           #+#    #+#             */
/*   Updated: 2023/12/27 20:25:33 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sorts the elements in stack_a of the given t_stacks.
 * The function applies different sorting algorithms based on
 * the number of elements.
 * For 2, 3, and 4 elements, specialized functions are used.
 * For more elements, a general sorting strategy is applied.
 *
 * @param stacks The container holding the stacks to be sorted.
 */
void	ft_sort(t_stacks *stacks)
{
	int	size_a;

	if (!stacks || !stacks->head_a)
		return ;
	size_a = ft_listsize(stacks->head_a);
	if (ft_check_list_order(stacks))
		return ;
	if (size_a == 2)
		ft_sort_two(stacks);
	else if (size_a == 3)
		ft_sort_three(stacks, 1);
	else if (size_a == 4)
		ft_sort_four(stacks);
	else
	{
		ft_push(stacks, 'b');
		ft_push(stacks, 'b');
		ft_move_best(stacks);
		ft_sort_three(stacks, 0);
		ft_reorder_a(stacks);
	}
}

/**
 * Sorts a stack with exactly two elements by swapping them.
 *
 * @param stacks - Container holding both stacks.
 */
void	ft_sort_two(t_stacks *stacks)
{
	ft_swap(stacks, 'a');
	ft_clearnodes(&stacks->head_a);
	exit(0);
}

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
	t_stack	*head_a;
	int		num1;
	int		num2;
	int		num3;

	if (!stacks || !stacks->head_a || !stacks->head_a->next
		|| !stacks->head_a->next->next)
		return ;
	head_a = stacks->head_a;
	num1 = head_a->data;
	num2 = head_a->next->data;
	num3 = head_a->next->next->data;
	ft_sort_three_elements(stacks, num1, num2, num3);
	if (clear)
		ft_clear_and_exit(&stacks->head_a);
}

/**
 * Sorts a stack with exactly four elements by pushing
 * one element to another stack,
 * sorting the remaining three, and then reordering the stacks
 * to achieve the sorted order.
 *
 * @param stacks - Container holding both stacks and related resources.
 */
void	ft_sort_four(t_stacks *stacks)
{
	if (!stacks || ft_listsize(stacks->head_a) != 4)
		return ;
	if (!ft_initialize_resources(stacks))
	{
		ft_free(stacks);
		return ;
	}
	ft_push(stacks, 'b');
	ft_sort_three(stacks, false);
	ft_reorder_a(stacks);
	ft_free(stacks);
}
