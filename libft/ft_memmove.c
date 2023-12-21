/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:21:36 by airyago           #+#    #+#             */
/*   Updated: 2023/12/21 18:01:38 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*char_dest;
	unsigned char	*char_src;
	size_t			i;

	if (dest == NULL)
		return (NULL);
	char_src = (unsigned char *)src;
	char_dest = (unsigned char *)dest;
	i = 1;
	if (dest > src)
	{
		while (i <= n)
		{
			char_dest[n - i] = char_src[n - i];
			i++;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
