/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:19:43 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/28 17:17:43 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sorts a stack of exactly four elements.
 * Pushes one element to stack B, sorts the remaining three elements in stack A,
 * then calculates and executes the best sequence of moves to sort stack B
 * and merge it back to stack A.
 * Finally, frees the memory allocated for the stacks and exits the program.
 *
 * @param stacks - A pointer to the structure containing both stacks
 * and their associated metadata.
 */
void	ft_sort_four(t_stacks *stacks)
{
	stacks->moves = ft_calloc(1, sizeof(t_moves));
	stacks->best = ft_calloc(1, sizeof(t_best));
	stacks->values = ft_calloc(1, sizeof(t_limits));
	if (!stacks->moves || !stacks->best || !stacks->values)
	{
		ft_free_stacks(stacks);
		return ;
	}
	ft_push(stacks, 'b');
	ft_sort_three(stacks, 0);
	ft_best_b_to_a(stacks);
	ft_free_stacks(stacks);
	exit (0);
}

