/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:19:43 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/12/28 14:09:17 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_stacks *stacks)
{
	t_moves		*moves;
	t_best		*best;
	t_values	*values;

	moves = ft_calloc(1, sizeof(t_moves));
	stacks->moves = moves;
	best = ft_calloc(1, sizeof(t_best));
	stacks->best = best;
	values = ft_calloc(1, sizeof(t_values));
	stacks->values = values;
	ft_push(stacks, 'b');
	sort_three(stacks, 0);
	move_stack_a(stacks);
	ft_free(stacks);
	exit(0);
}
