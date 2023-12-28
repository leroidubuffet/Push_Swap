/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:59:02 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/28 17:05:18 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stacks *stacks)
{
	ft_clearnodes_a(&stacks->head_a);
	stacks->head_a = NULL;
	ft_clearnodes_b(&stacks->head_b);
	stacks->head_b = NULL;
	free(stacks->values);
	stacks->values = NULL;
	free(stacks->moves);
	stacks->moves = NULL;
	free(stacks->best);
	stacks->best = NULL;
}
