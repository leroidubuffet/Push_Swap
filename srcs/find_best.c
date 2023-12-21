/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago  <airyago @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:29:24 by airyago           #+#    #+#             */
/*   Updated: 2023/08/31 16:19:56 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_best(t_stacks *stacks)
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
	while (ft_listsize(stacks->head_a) != 3)
	{
		check_max_min_b(stacks);
		ft_check_moves(stacks);
		ft_run_moves(stacks);
	}
}

void	ft_run_moves(t_stacks *stacks)
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

int	ft_find_destination(t_stacks *stacks, int num)
{
	t_stack	*head_b;
	int			size;
	bool		flag;
	int			i;

	i = 0;
	flag = false;
	head_b = stacks->head_b;
	size = ft_listsize(stacks->head_b);
	while (flag == false)
	{
		i = 0;
		num--;
		head_b = stacks->head_b;
		while (i++ < size)
		{
			if (head_b->data == num)
				flag = true;
			head_b = head_b->next;
		}
	}
	return (num);
}

int	ft_find_index(t_stacks *stacks, int num)
{
	t_stack	*head_b;
	int			size;
	int			i;

	i = 0;
	head_b = stacks->head_b;
	size = ft_listsize(stacks->head_b);
	while (i < size)
	{
		if (head_b->data == num)
			break ;
		head_b = head_b->next;
		i++;
	}
	return (i);
}
