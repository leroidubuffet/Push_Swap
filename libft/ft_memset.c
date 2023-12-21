/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:37:14 by airyago           #+#    #+#             */
/*   Updated: 2023/12/21 18:01:38 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// To use the elements inside the returned array s: (unsigned char *)s[i]

#include "libft.h"

void	*ft_memset(void *s, int c, size_t x)
{
	size_t	i;

	i = 0;
	while (i < x)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
