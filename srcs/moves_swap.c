/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:35:04 by airyago           #+#    #+#             */
/*   Updated: 2023/12/21 18:01:38 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stacks *stacks, char ch)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = stacks->head_a;
	head_b = stacks->head_b;
	if (ch == 'a')
		ft_swap_a(head_a, 1);
	else if (ch == 'b')
	{
		if (head_b == NULL || head_b->next == NULL)
			return ;
		ft_swap_b(head_b, 1);
	}
	else
	{
		if (head_a == NULL || head_a->next == NULL || head_b == NULL
			|| head_b->next == NULL)
			return ;
		ft_swap_a(head_a, 0);
		ft_swap_b(head_b, 0);
		ft_printf("ss\n");
	}
}

void	ft_swap_a(t_stack *head_a, int print)
{
	int	tmp;

	tmp = head_a->data;
	head_a->data = head_a->next->data;
	head_a->next->data = tmp;
	if (print != 0)
		ft_printf("sa\n");
}

void	ft_swap_b(t_stack *head_b, int print)
{
	int	tmp;

	tmp = head_b->data;
	head_b->data = head_b->next->data;
	head_b->next->data = tmp;
	if (print != 0)
		ft_printf("sb\n");
}
