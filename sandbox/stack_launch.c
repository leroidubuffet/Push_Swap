/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_launch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:29:33 by airyago           #+#    #+#             */
/*   Updated: 2023/09/06 10:00:42 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_initialize_stack_b(void)
{
	return (ft_new_stack());
}

t_stack	*ft_new_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	return (stack);
}

static t_stack	*ft_populate_stack(t_stack *stack, int argc, char **argv)
{
	int		i;
	t_node	*temp;
	t_node	*new_node;

	temp = NULL;
	i = 1;
	while (i < argc)
	{
		new_node = ft_create_node(ft_atoi(argv[i]));
		if (temp == NULL)
		{
			stack->head = new_node;
			stack->tail = new_node;
		}
		else
			temp->next = new_node;
		temp = new_node;
		i++;
	}
	stack->tail = temp;
	return (stack);
}

t_stack	*ft_initialize_stack_a(int argc, char **argv)
{
	t_stack	*stack;

	stack = ft_new_stack();
	if (!stack)
		return (NULL);
	if (!ft_populate_stack(stack, argc, argv))
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}