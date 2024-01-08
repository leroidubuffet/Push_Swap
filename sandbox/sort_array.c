/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:32:18 by airyago           #+#    #+#             */
/*   Updated: 2023/09/06 10:05:12 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*ft_allocate_array(int argc)
{
	int	*array;

	array = (int *)malloc(sizeof(int) * argc);
	if (!array)
		exit(1);
	return (array);
}

static int	*ft_indexate_array(char **argv, int argc)
{
	int	i;
	int	j;
	int	key;
	int	*array;
	int	index;

	i = 1;
	index = 0;
	array = ft_allocate_array(argc);
	while (i < argc)
	{
		array[index] = ft_atoi(argv[i]);
		key = array[index];
		j = index - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
		i++;
		index++;
	}
	return (array);
}

t_stack	*ft_assign_position(t_stack *stack, int *array, int argc)
{
	t_node	*temp;
	int		i;

	temp = stack->head;
	while (temp != NULL)
	{
		i = 0;
		while (i < argc)
		{
			if (temp->data == array[i])
			{
				temp->position = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
	return (stack);
}

void	ft_setup_array(int argc, char **argv, t_stack *stack_a)
{
	int	*array;

	array = ft_indexate_array(argv, argc);
	stack_a = ft_assign_position(stack_a, array, argc);
	free(array);
}
