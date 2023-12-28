/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:38:22 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/28 20:20:20 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Allocates and returns a new node with the given content.
 *
 * @param content - The integer content to store in the node.
 * @return t_stack_a* - The new node created with the given content.
 */
t_stack_b	*ft_newnode_b(int content)
{
	t_stack_b	*ptr;

	ptr = (t_stack_b *)malloc(sizeof(t_stack_b));
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
void	ft_clearnodes_b(t_stack_b **lst)
{
	t_stack_b	*ptr;

	while (*lst != NULL)
	{
		ptr = *lst;
		*lst = ptr->next;
		free(ptr);
	}
}

/**
 * Returns the size of the linked list.
 *
 * @param head - The head of the linked list.
 * @return int - The number of elements in the linked list.
 */
int	ft_listsize_b(t_stack_b *head)
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
