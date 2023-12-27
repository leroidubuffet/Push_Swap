/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:59:02 by airyago           #+#    #+#             */
/*   Updated: 2023/12/27 19:51:03 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stacks *stacks)
{
	ft_clearnodes(&stacks->head_a);
	ft_clearnodes(&stacks->head_b);
	free(stacks->values);
	free(stacks->moves);
	free(stacks->best);
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

