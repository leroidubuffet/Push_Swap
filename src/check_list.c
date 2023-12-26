/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:46:08 by airyago           #+#    #+#             */
/*   Updated: 2023/12/21 18:03:08 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_check_list_order(t_stacks *stacks)
{
	t_stack	*head_a;
	int			num;
	int			i;

	i = 1;
	head_a = stacks->head_a;
	num = head_a->data;
	while (i++ < ft_listsize(stacks->head_a))
	{
		head_a = head_a->next;
		if (num > head_a->data)
			return (0);
		num = head_a->data;
	}
	ft_clearnodes(&stacks->head_a);
	exit(0);
}
