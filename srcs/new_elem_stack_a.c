/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elem_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:42:56 by airyago           #+#    #+#             */
/*   Updated: 2023/12/30 18:43:39 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * Searches for the next highest number in stack A relative to a given number.
 *
 * @param stacks - The container holding stack A.
 * @param number - The number to compare against stack A's elements.
 * @return The next highest number in stack A.
 */
static int	ft_find_next_top_in_a(t_stacks *stacks, int number)
{
	t_stack_a	*current_node;
	int			stack_size;
	bool		found;
	int			i;

	current_node = stacks->head_a;
	stack_size = ft_listsize_a(stacks->head_a);
	found = false;
	while (!found)
	{
		i = 0;
		number++;
		current_node = stacks->head_a;
		while (i < stack_size)
		{
			if (current_node->content == number)
			{
				found = true;
				break ;
			}
			current_node = current_node->next;
			i++;
		}
	}
	return (number);
}

/**
 * Executes rotations to move the next element to the top of stack A.
 *
 * @param stacks - The container holding both stack A and B.
 */
static void	ft_execute_rotations(t_stacks *stacks)
{
	while (stacks->moves->ra > 0)
	{
		ft_rotate(stacks, 'a');
		stacks->moves->ra--;
	}
	while (stacks->moves->rra > 0)
	{
		ft_rev_rotate(stacks, 'a');
		stacks->moves->rra--;
	}
	ft_push(stacks, 'a');
}

/**
 * Calculates the number of rotations and reverse rotations needed to move
 * an element to the correct position in stack A.
 *
 * @param stacks - The container holding both stack A and B.
 * @param index - The current index of the element to be moved.
 * @param stack_size - The size of stack A.
 */
static void	ft_calculate_rotations(t_stacks *stacks, int index, int stack_size)
{
	if (stack_size % 2 == 0)
	{
		if (index + 1 > stack_size / 2)
			stacks->moves->rra = stack_size - index;
		else
			stacks->moves->ra = index;
	}
	else
	{
		if (index > stack_size / 2)
			stacks->moves->rra = stack_size - index;
		else
			stacks->moves->ra = index;
	}
}

/**
 * Places an element from stack B into its correct position in stack A.
 * Calculates the number of rotations needed and executes them.
 *
 * @param stacks - The container holding both stack A and B.
 * @param head_b - The top element of stack B.
 */
void	ft_place_element_a(t_stacks *stacks, t_stack_b *head_b)
{
	int	index;
	int	stack_size;
	int	target_nbr;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	target_nbr = ft_find_next_top_in_a(stacks, head_b->content);
	if (stacks->head_a->content != target_nbr)
	{
		index = ft_find_index_stack_a(stacks, target_nbr);
		stack_size = ft_listsize_a(stacks->head_a);
		ft_calculate_rotations(stacks, index, stack_size);
	}
	ft_execute_rotations(stacks);
}
