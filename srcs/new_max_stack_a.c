/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_max_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:43:17 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/28 19:29:39 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Executes the calculated moves to bring the maximum value to the top of stack A.
 * Rotates or reverse rotates based on the previously calculated most efficient method.
 *
 * @param stacks - The container holding both stacks and their operational data.
 */
static void ft_move_max_to_top(t_stacks *stacks)
{
    // Rotate stack A until the maximum element is at the top.
    while (stacks->moves->ra > 0)
    {
        ft_rotate(stacks, 'a');
        stacks->moves->ra--;
    }

    // Reverse rotate stack A until the maximum element is at the top.
    while (stacks->moves->rra > 0)
    {
        ft_rev_rotate(stacks, 'a');
        stacks->moves->rra--;
    }

    // Push the maximum element to stack B and then rotate to position it properly.
    ft_push(stacks, 'a');
    ft_rotate(stacks, 'a');
}

/**
 * Determines the optimal moves to bring the maximum value to the top of
 * stack A. It calculates the moves required for rotation or reverse
 * rotation based on the position of the maximum value.
 *
 * @param stacks - The container holding both stacks and their operational data.
 */
void ft_calc_moves_max-top(t_stacks *stacks)
{
    int i;
    int size;

    stacks->moves->ra = 0;
    stacks->moves->rra = 0;
    if (ft_listlast_a(stacks->head_a)->content != stacks->values->max_a)
    {
        i = find_index_stack_a(stacks, stacks->values->max_a);
        size = ft_listsize_a(stacks->head_a);

        // Determine the most efficient direction to rotate.
        if (size % 2 == 0)
        {
            if (i + 1 > size / 2)
                stacks->moves->rra = size - i - 1;
            else
                stacks->moves->ra = i + 1;
        }
        else
        {
            if (i > size / 2)
                stacks->moves->rra = size - i - 1;
            else
                stacks->moves->ra = i + 1;
        }
    }
    ft_move_max_to_top(stacks);
}
