/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:35:04 by airyago           #+#    #+#             */
/*   Updated: 2023/12/21 18:01:39 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a_bonus(t_stack *head_a)
{
	int	tmp;

	tmp = head_a->data;
	head_a->data = head_a->next->data;
	head_a->next->data = tmp;
}

void	ft_swap_b_bonus(t_stack *head_b)
{
	int	tmp;

	tmp = head_b->data;
	head_b->data = head_b->next->data;
	head_b->next->data = tmp;
}

void	ft_swap(t_stacks *stacks, char ch)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = stacks->head_a;
	head_b = stacks->head_b;
	if (ch == 'a')
		ft_swap_a_bonus(head_a);
	else if (ch == 'b')
	{
		if (head_b == NULL || head_b->next == NULL)
			return ;
		ft_swap_b_bonus(head_b);
	}
	else
	{
		if (head_a == NULL || head_a->next == NULL || head_b == NULL
			|| head_b->next == NULL)
			return ;
		ft_swap_a_bonus(head_a);
		ft_swap_b_bonus(head_b);
	}
}
