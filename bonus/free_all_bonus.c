/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:33:16 by airyago           #+#    #+#             */
/*   Updated: 2023/12/21 18:05:27 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_bonus(t_stacks *stacks)
{
	ft_clearnodes(&stacks->head_a);
	if (stacks->head_b != NULL)
		ft_clearnodes(&stacks->head_b);
}

void	ft_error_bonus(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	free_and_exit(t_stacks *stacks, char *cmd)
{
	ft_free_bonus(stacks);
	free(cmd);
	ft_error_bonus();
}

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
			return (false);
		num = head_a->data;
	}
	return (true);
}
