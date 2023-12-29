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

void	ft_sort_four(t_stacks *stacks)
{
	t_moves		*moves;
	t_best		*best;
	t_limits	*values;

	moves = ft_calloc(1, sizeof(t_moves));
	stacks->moves = moves;
	best = ft_calloc(1, sizeof(t_best));
	stacks->best = best;
	values = ft_calloc(1, sizeof(t_limits));
	stacks->values = values;
	ft_push(stacks, 'b');
	ft_sort_three(stacks, 0);
	ft_best_b_to_a(stacks);
	ft_free_stacks(stacks);
	exit(0);
}
