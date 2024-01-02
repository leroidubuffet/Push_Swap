/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:57:07 by ybolivar          #+#    #+#             */
/*   Updated: 2024/01/02 11:41:44 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Creates and returns a linked list from the given arguments.
 * Converts each argument into an integer and creates a new node in the list.
 *
 * @param argc - The number of arguments.
 * @param argv - Array of strings representing the arguments.
 * @return t_stack_a* - The head of the newly created linked list.
 */
t_stack_a	*ft_create_list(int argc, char **argv)
{
	int			i;
	t_stack_a	*head_a;
	t_stack_a	*tmp;

	i = 1;
	head_a = ft_newnode_a(ft_atoi(argv[i]));
	tmp = head_a;
	while (++i < argc)
	{
		tmp->next = ft_newnode_a(ft_atoi(argv[i]));
		tmp = tmp->next;
		tmp->next = NULL;
	}
	return (head_a);
}

/**
 * Allocates and returns a new node with the given content.
 *
 * @param content - The integer content to store in the node.
 * @return t_stack_a* - The new node created with the given content.
 */
t_stack_a	*ft_newnode_a(int content)
{
	t_stack_a	*ptr;

	ptr = (t_stack_a *)malloc(sizeof(t_stack_a));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

/**
 * Clears and frees all nodes in the linked list starting from the given head.
 *
 * @param lst - A pointer to the head of the list to clear.
 */
void	ft_clearnodes_a(t_stack_a **lst)
{
	t_stack_a	*ptr;

	while (*lst != NULL)
	{
		ptr = *lst;
		*lst = ptr->next;
		free(ptr);
		ptr = NULL;
	}
}

/**
 * Returns the size of the linked list.
 *
 * @param head - The head of the linked list.
 * @return int - The number of elements in the linked list.
 */
int	ft_listsize_a(t_stack_a *head)
{
	int	count;

	count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return (count);
}
