/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:59:02 by airyago           #+#    #+#             */
/*   Updated: 2023/12/29 16:32:03 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_bzero(void *str, size_t len)
{
	unsigned char	*buf;

	buf = str;
	while (len--)
	{
		*buf++ = 0;
	}
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
	stacks->values = ft_calloc(1, sizeof(t_limits));
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

