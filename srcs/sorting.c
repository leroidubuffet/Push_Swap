/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:59:54 by airyago           #+#    #+#             */
/*   Updated: 2023/12/27 20:15:37 by airyago          ###   ########.fr       */
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
static void	ft_sort_three_elements(t_stacks *stacks, int num1, int num2, int num3)
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
void ft_sort_three(t_stacks *stacks, bool clear)
{
	t_stack *head_a;
	int num1, num2, num3;

	if (!stacks || !stacks->head_a || !stacks->head_a->next || !stacks->head_a->next->next)
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
 * Initializes the resources necessary for sorting operations.
 *
 * @param stacks - Container holding both stacks and related resources.
 * @return true if initialization is successful, false otherwise.
 */
static bool initialize_resources(t_stacks *stacks)
{
    stacks->moves = ft_calloc(1, sizeof(t_moves));
    stacks->best = ft_calloc(1, sizeof(t_best));
    stacks->values = ft_calloc(1, sizeof(t_values));

    // Check if all allocations were successful.
    if (!stacks->moves || !stacks->best || !stacks->values) {
        // Handle failed allocation by freeing any successful allocations.
        if (stacks->moves) free(stacks->moves);
        if (stacks->best) free(stacks->best);
        if (stacks->values) free(stacks->values);
        return false;
    }
    return true;
}

/**
 * Sorts a stack with exactly four elements by pushing one element to another stack,
 * sorting the remaining three, and then reordering the stacks to achieve the sorted order.
 *
 * @param stacks - Container holding both stacks and related resources.
 */
void ft_sort_four(t_stacks *stacks)
{
    if (!stacks || ft_listsize(stacks->head_a) != 4) {
        // Handle the error or unexpected situation when the stack doesn't have exactly four elements.
        return;  // Early return if stacks is NULL or doesn't contain exactly four elements.
    }

    // Allocate and check memory for moves, best, and values.
    if (!initialize_resources(stacks)) {
        // Handle failed allocation.
        ft_free(stacks);  // Clean up any allocated resources.
        return;
    }

    // Move one element to another stack (presumably the smallest or largest, depending on your strategy).
    ft_push(stacks, 'b');       // Move one element to stack_b.

    // Sort the remaining three elements in stack_a.
    ft_sort_three(stacks, false);   // false indicates nodes should not be cleared after sorting.

    // Reorder elements to achieve overall sorted order.
    ft_reorder_a(stacks);

    // Clean up allocated resources after sorting is done.
    ft_free(stacks);
}


