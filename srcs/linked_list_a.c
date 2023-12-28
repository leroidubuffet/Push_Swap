/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:57:07 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/28 16:48:17 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_clearnodes_a(t_stack_a **lst)
{
	t_stack_a	*ptr;

	while (*lst != NULL)
	{
		ptr = *lst;
		*lst = ptr->next;
		free(ptr);
	}
}

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

t_stack_a	*ft_lstlast_a(t_stack_a *head_a)
{
	if (head_a == NULL)
		return (NULL);
	while (head_a->next != NULL)
		head_a = head_a->next;
	return (head_a);
}
