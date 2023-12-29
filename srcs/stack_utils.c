/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:59:02 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/29 13:06:50 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Initializes the stacks for the push_swap algorithm.
 * It sets up the stack 'a' with the input arguments and ensures stack 'b'
 * is empty.
 *
 * @param stacks - A pointer to the structure containing both stack
 * 'a' and 'b'.
 * @param argc - The count of command-line arguments, representing
 * the numbers to sort.
 * @param argv - The array of command-line arguments, representing
 * the numbers to sort.
 */
void	ft_initialize_stacks(t_stacks *stacks, int argc, char **argv)
{
	if (!stacks)
		return ;
	stacks->head_a = ft_create_list(argc, argv);
	stacks->head_b = NULL;
}

/**
 * Frees all dynamically allocated memory within the t_stacks structure.
 * This includes all nodes in both stack_a and stack_b, as well as
 * the associated values, moves, and best strategy structures. It sets
 * all pointers to NULL after freeing to prevent dangling pointer issues.
 *
 * @param stacks - Pointer to the t_stacks structure containing
 * all the allocated elements.
 */
void	ft_free_stacks(t_stacks *stacks)
{
	if (!stacks)
		return ;
	ft_clearnodes_a(&stacks->head_a);
	ft_clearnodes_b(&stacks->head_b);
	free(stacks->values);
	stacks->values = NULL;
	free(stacks->moves);
	stacks->moves = NULL;
	free(stacks->best);
	stacks->best = NULL;
}
