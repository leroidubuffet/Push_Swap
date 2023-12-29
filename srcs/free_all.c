/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:59:02 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/29 13:00:05 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Frees all dynamically allocated memory within the t_stacks structure.
 * This includes all nodes in both stack_a and stack_b, as well as
 * the associated values, moves, and best strategy structures. It sets
 * all pointers to NULL after freeing to prevent dangling pointer issues.
 *
 * @param stacks - Pointer to the t_stacks structure containing
 * all the allocated elements.
 */
void	ft_free(t_stacks *stacks)
{	if (!stacks)
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
