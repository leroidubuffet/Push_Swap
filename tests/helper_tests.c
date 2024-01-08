/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:51:47 by airyago           #+#    #+#             */
/*   Updated: 2023/08/14 14:53:04 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	t_node	current;

	current = stack->head;
	while (current != NULL)
	{
		printf("%d -> ", current->num);
		current = current->next;
	}
	printf("NULL\n");
}

void	ft_initialize_stack(t_stack *stack, int num)
{
	int		n;
	t_node	new_node;
	t_node	*current;

	current = &stack->head;
	n = 0;
	while (n++ < 10)
	{
		new_node = ft_allocate_node();
		new_node->num = num;
		*current = new_node;
		current = &new_node->next;
		num++;
	}
	stack->tail = new_node;
}

void	test_swap(void)
{
	t_stack	stack_a;

	stack_a = ft_create_stack();
	ft_initialize_stack(&stack_a, 20);
	printf("Before swap:\n");
	print_stack(&stack_a);

	sb(&stack_a);

	printf("After swap:\n");
	print_stack(&stack_a);
}

void	test_double_swap(void)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a = ft_create_stack();
	stack_b = ft_create_stack();
	ft_initialize_stack(&stack_a, 9999999999);
	ft_initialize_stack(&stack_b, -9999999999);
	printf("Before double swap:\n");
	print_stack(&stack_a);
	print_stack(&stack_b);
	ss(&stack_a, &stack_b);
	printf("After double swap:\n");
	print_stack(&stack_a);
	print_stack(&stack_b);
}

void	test_rotate(void)
{
	t_stack	stack_a;

	stack_a = ft_create_stack();
	ft_initialize_stack(&stack_a, 10);
	printf("Before rotate:\n");
	print_stack(&stack_a);
	rb(&stack_a);
	printf("After rotate:\n");
	print_stack(&stack_a);
}

void	test_double_rotate(void)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a = ft_create_stack();
	stack_b = ft_create_stack();
	ft_initialize_stack(&stack_a, 10);
	ft_initialize_stack(&stack_b, 20);
	printf("Before double rotate:\n");
	print_stack(&stack_a);
	print_stack(&stack_b);
	rr(&stack_a, &stack_b);
	printf("After double rotate:\n");
	print_stack(&stack_a);
	print_stack(&stack_b);
}

void	test_double_reverse_rotate(void)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a = ft_create_stack();
	stack_b = ft_create_stack();
	ft_initialize_stack(&stack_a, 10);
	ft_initialize_stack(&stack_b, 20);
	printf("Before double reverse rotate:\n");
	print_stack(&stack_a);
	print_stack(&stack_b);
	rrr(&stack_a, &stack_b);
	printf("After double reverse rotate:\n");
	print_stack(&stack_a);
	print_stack(&stack_b);
}

void	test_reverse_rotate(void)
{
	t_stack	stack_a;

	stack_a = ft_create_stack();
	ft_initialize_stack(&stack_a, 30);
	printf("Before reverse rotate:\n");
	print_stack(&stack_a);
	rrb(&stack_a);
	printf("After reverse rotate:\n");
	print_stack(&stack_a);

}

void	test_push(void)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a = ft_create_stack();
	stack_b = ft_create_stack();
	ft_initialize_stack(&stack_a, 50);
	ft_initialize_stack(&stack_b, 60);
	printf("Before push:\n");
	print_stack(&stack_a);
	print_stack(&stack_b);
	pb(&stack_a, &stack_b);
	printf("After push:\n");
	print_stack(&stack_a);
	print_stack(&stack_b);
}
