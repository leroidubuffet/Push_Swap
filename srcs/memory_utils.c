/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:59:02 by airyago           #+#    #+#             */
/*   Updated: 2023/12/27 20:39:01 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Frees all dynamically allocated resources within the stacks.
 *
 * @param stacks - Pointer to the structure containing stack and related data.
 */
void	ft_free(t_stacks *stacks)
{
	if (!stacks)
		return ;
	if (stacks->head_a)
	{
		ft_clearnodes(&stacks->head_a);
		stacks->head_a = NULL;
	}
	if (stacks->head_b)
	{
		ft_clearnodes(&stacks->head_b);
		stacks->head_b = NULL;
	}
	free(stacks->values);
	stacks->values = NULL;
	free(stacks->moves);
	stacks->moves = NULL;
	free(stacks->best);
	stacks->best = NULL;
}

/**
 * Clears nodes of the given stack and exits the program.
 *
 * @param head - Pointer to the head of the stack to be cleared.
 */
void	ft_clear_and_exit(t_stack **head)
{
	if (head && *head)
		ft_clearnodes(head);
	exit (0);
}

/**
 * Initializes the resources necessary for sorting operations.
 *
 * @param stacks - Container holding both stacks and related resources.
 * @return true if initialization is successful, false otherwise.
 */
bool	ft_initialize_resources(t_stacks *stacks)
{
	stacks->moves = ft_calloc(1, sizeof(t_moves));
	stacks->best = ft_calloc(1, sizeof(t_best));
	stacks->values = ft_calloc(1, sizeof(t_values));
	if (!stacks->moves || !stacks->best || !stacks->values)
	{
		if (stacks->moves)
			free(stacks->moves);
		if (stacks->best)
			free(stacks->best);
		if (stacks->values)
			free(stacks->values);
		return (false);
	}
	return (true);
}

/**
 * Allocates memory for an array of `count` elements of `size`
 * bytes each and initializes all bytes to zero.
 *
 * @param count - Number of elements.
 * @param size - Size of each element.
 * @return A pointer to the allocated memory,
 * or NULL if an error occurs.
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if ((size != 0 && count > SIZE_MAX / size))
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	ft_bzero(void *str, size_t len)
{
	unsigned char	*buf;

	buf = str;
	while (len--)
	{
		*buf++ = 0;
	}
}
