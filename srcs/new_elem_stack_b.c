/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_in_stack_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:15:41 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/30 15:31:57 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/**
 * Updates the rotation counts needed to move the max value
 * in stack B to the top.
 * @param stacks - The container holding both stack A and stack B.
 */
void	ft_update_stack_limits(t_stacks *stacks)
{
	int	i;
	int	size;
	int	half_size;

	if (stacks == NULL || stacks->head_b == NULL || stacks->moves == NULL
		|| stacks->values == NULL)
		return;
	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;
	if (stacks->head_b->content == stacks->values->max_b)
		return;
	i = ft_find_index_b(stacks, stacks->values->max_b);
	size = ft_listsize_b(stacks->head_b);
	half_size = size / 2;
	if (i + 1 > half_size)
		stacks->moves->rrb = size - i;
	else
		stacks->moves->rb = i;
}

/**
 * Calculates the rotations required to place a new number in its
 * correct position in stack B.
 * @param stacks - The container holding both stack A and stack B.
 * @param num - The number to be placed in stack B.
 */
void	ft_place_element_b(t_stacks *stacks, int num)
{
	int	i;
	int	size;
	int	nbr;
	int	half_size;

	if (stacks == NULL || stacks->head_b == NULL || stacks->moves == NULL)
		return;
	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;
	nbr = ft_search_num_b(stacks, num);
	if (stacks->head_b->content == nbr)
		return;
	i = ft_find_index_b(stacks, nbr);
	size = ft_listsize_b(stacks->head_b);
	half_size = size / 2;
	if (i + 1 > half_size)
		stacks->moves->rrb = size - i;
	else
		stacks->moves->rb = i;
}

/**
 * Calculates the rotations required to move a given element
 * in stack A to the top.
 * @param stacks - The container holding both stack A and stack B.
 * @param head_a - The head of stack A.
 * @param i - The index of the element in stack A.
 */
void	ft_calc_to_top(t_stacks *stacks, t_stack_a *head_a, int i)
{
	int size;
	int half_size;

	if (stacks == NULL || stacks->head_a == NULL || stacks->moves == NULL)
		return;
	stacks->moves->pb = 1;
	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->head_a->content == head_a->content)
		return;
	size = ft_listsize_a(stacks->head_a);
	half_size = size / 2;
	if (i + 1 > half_size)
		stacks->moves->rra = size - i;
	else
		stacks->moves->ra = i;
}

