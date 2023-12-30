/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:29:24 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/30 14:07:29 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Executes the series of moves determined to be the cheapest
 * to move an element from stack A to B.
 *
 * @param stacks - The container holding both stack A and
 * stack B along with their associated data.
 */
static void	ft_execute_sequence(t_stacks *stacks)
{
	while (stacks->best->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->best->rb-- != 0)
		ft_rotate(stacks, 'b');
	while (stacks->best->rr-- != 0)
		ft_rotate(stacks, 'r');
	while (stacks->best->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	while (stacks->best->rrb-- != 0)
		ft_rev_rotate(stacks, 'b');
	while (stacks->best->rrr-- != 0)
		ft_rev_rotate(stacks, 'r');
	while (stacks->best->pb-- != 0)
		ft_push(stacks, 'b');
}

/**
 * Moves elements from stack A to B with the minimum amount of operations
 * until only three elements are left in stack A. It initializes the move,
 * best, and value structures, then continuously finds and executes
 * the cheapest move.
 *
 * @param stacks - The container holding both stack A and stack B
 * along with their associated data.
 */
void	ft_move_a_to_b(t_stacks *stacks)
{
	if (!stacks)
		return ;
	stacks->moves = ft_calloc(1, sizeof(t_moves));
	stacks->best = ft_calloc(1, sizeof(t_best));
	stacks->values = ft_calloc(1, sizeof(t_limits));
	if (!stacks->moves || !stacks->best || !stacks->values)
		return ;
	while (ft_listsize_a(stacks->head_a) != 3)
	{
		ft_check_limits_b(stacks);
		ft_find_best_sequence(stacks);
		ft_execute_sequence(stacks);
	}
}

/**
 * Searches for the next lower number in stack B compared
 * to the provided number.
 *
 * @param stacks - The container holding both stack A
 * and stack B along with their associated data.
 * @param nbr - The number to compare against
 * the contents of stack B.
 * @return - The next lower number found in stack B.
 */
int	ft_search_num_b(t_stacks *stacks, int nbr)
{
	bool		flag;
	t_stack_b	*head_b;
	int			i;
	int			size;

	if (!stacks || !stacks->head_b)
		return (nbr);
	flag = false;
	head_b = stacks->head_b;
	i = 0;
	size = ft_listsize_b(stacks->head_b);
	while (!flag)
	{
		nbr--;
		while (i < size && !flag)
		{
			if (head_b->content == nbr)
				flag = true;
			i++;
			head_b = head_b->next;
		}
		head_b = stacks->head_b;
	}
	return (nbr);
}

/**
 * Finds the index of a given number in stack B.
 *
 * @param stacks - The container holding both stack A and stack B along with
 * their associated data.
 * @param nbr - The number to find within stack B.
 * @return - The index of the number in stack B, or -1 if not found.
 */
int	ft_find_index_b(t_stacks *stacks, int nbr)
{
	int			index;
	t_stack_b	*head_b;

	index = 0;
	head_b = stacks->head_b;
	if (!stacks || !stacks->head_b)
		return (-1);
	while (head_b != NULL)
	{
		if (head_b->content == nbr)
			return (index);
		head_b = head_b->next;
		index++;
	}
	return (-1);
}