/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:35:04 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/28 16:48:17 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stacks *stacks, char ch)
{
	t_stack_a	*head_a;
	t_stack_b	*head_b;

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
		ft_putstr("ss\n");
	}
}

void	ft_swap_a(t_stack_a *head_a, int print)
{
	int	tmp;

	tmp = head_a->content;
	head_a->content = head_a->next->content;
	head_a->next->content = tmp;
	if (print != 0)
		ft_putstr("sa\n");
}

void	ft_swap_b(t_stack_b *head_b, int print)
{
	int	tmp;

	tmp = head_b->content;
	head_b->content = head_b->next->content;
	head_b->next->content = tmp;
	if (print != 0)
		ft_putstr("sb\n");
}
