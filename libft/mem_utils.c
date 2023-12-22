/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:05:02 by airyago           #+#    #+#             */
/*   Updated: 2023/12/21 21:06:41 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;
	size_t	total_size;

	// Improved overflow check
	if (size && count > SIZE_MAX / size)
		return (NULL);

	total_size = count * size;
	memory = malloc(total_size);
	if (memory == NULL)
		return (NULL);

	// Using standard memset to set allocated memory to 0
	ft_memset(memory, 0, total_size);
	return (memory);
}

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*buf;

	buf = str;
	while (len--)
	{
		*buf++ = (unsigned char)c;
	}
	return (str);
}

