/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_min_to_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:44:31 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/28 19:32:34 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Executes the moves calculated by ft_calc_min_to_top to reposition the minimum
 * element to the top of stack A and then push it to stack B.
 *
 * @param stacks - The container holding both stacks and their operational data.
 */
static void ft_move_min_to_top(t_stacks *stacks)
{
    // Perform the rotations or reverse rotations as calculated.
    while (stacks->moves->ra > 0)
    {
        ft_rotate(stacks, 'a');
        stacks->moves->ra--;
    }
    while (stacks->moves->rra > 0)
    {
        ft_rev_rotate(stacks, 'a');
        stacks->moves->rra--;
    }

    // Push the now-top minimum element from stack A to stack B.
    ft_push(stacks, 'a');
}

/**
 * Calculates and sets up the optimal moves to bring the minimum value to the top
 * of stack A. It determines the best rotation direction based on the position.
 *
 * @param stacks - The container holding both stacks and their operational data.
 */
void ft_calc_min_to_top(t_stacks *stacks)
{
    int index;
    int stack_size;

    // Reset the count for rotations and reverse rotations.
    stacks->moves->ra = 0;
    stacks->moves->rra = 0;

    // Only proceed if the minimum element isn't already at the top of stack A.
    if (stacks->head_a->content != stacks->values->min_a)
    {
        index = find_index_stack_a(stacks, stacks->values->min_a);
        stack_size = ft_listsize_a(stacks->head_a);

        // Determine rotation direction based on the element's position.
        if ((stack_size % 2 == 0 && index + 1 > stack_size / 2) ||
            (index > stack_size / 2))
        {
            stacks->moves->rra = stack_size - index;
        }
        else
        {
            stacks->moves->ra = index;
        }
    }

    // Execute the moves to position the minimum element at the top.
    ft_move_min_to_top(stacks);
}


