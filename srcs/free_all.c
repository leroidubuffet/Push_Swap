/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:59:02 by airyago           #+#    #+#             */
/*   Updated: 2023/12/27 20:04:24 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Frees all dynamically allocated resources within the stacks.
 *
 * @param stacks - Pointer to the structure containing stack and related data.
 */
void ft_free(t_stacks *stacks)
{
	if (!stacks)
		return ;
	if (stacks->head_a)
	{
		ft_clearnodes(&stacks->head_a);
		stacks->head_a = NULL;
	}
	if (stacks->head_b)
	{
		ft_clearnodes(&stacks->head_b);
		stacks->head_b = NULL;
	}

	free(stacks->values);
	stacks->values = NULL;
	free(stacks->moves);
	stacks->moves = NULL;
	free(stacks->best);
	stacks->best = NULL;
}

/**
 * Clears nodes of the given stack and exits the program.
 *
 * @param head - Pointer to the head of the stack to be cleared.
 */
void ft_clear_and_exit(t_stack **head)
{
	if (head && *head)
		ft_clearnodes(head);
	exit (0);
}

