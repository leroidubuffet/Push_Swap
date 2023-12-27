/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:59:54 by airyago           #+#    #+#             */
/*   Updated: 2023/12/27 19:18:28 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sorts the elements in stack_a of the given t_stacks.
 * The function applies different sorting algorithms based on the number of elements.
 * For 2, 3, and 4 elements, specialized functions are used. For more elements, a general
 * sorting strategy is applied.
 *
 * @param stacks The container holding the stacks to be sorted.
 */
void ft_sort(t_stacks *stacks)
{
	int	size_a;

	if (!stacks || !stacks->head_a)
		return ;
	size_a = ft_listsize(stacks->head_a);
	if (ft_check_list_order(stacks))
		return ;
	if (size_a == 2)
		ft_sort_two(stacks);
	else if (size_a == 3)
		ft_sort_three(stacks, 1);
	else if (size_a == 4)
		ft_sort_four(stacks);
	else
	{
		ft_push(stacks, 'b');
		ft_push(stacks, 'b');
		ft_move_best(stacks);
		ft_sort_three(stacks, 0);
		ft_reorder_a(stacks);
	}
}

void	ft_sort_four(t_stacks *stacks)
{
	struct t_moves	*moves;
	struct t_best	*best;
	t_values		*values;

	moves = ft_calloc(1, sizeof(t_moves));
	stacks->moves = moves;
	best = ft_calloc(1, sizeof(t_best));
	stacks->best = best;
	values = ft_calloc(1, sizeof(t_values));
	stacks->values = values;
	ft_push(stacks, 'b');
	ft_sort_three(stacks, 0);
	ft_reorder_a(stacks);
	ft_free(stacks);
	exit(0);
}
