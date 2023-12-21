/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:18:01 by airyago           #+#    #+#             */
/*   Updated: 2023/12/21 18:01:38 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = ft_strlen((char *)s);
	ch = (unsigned char)c;
	if (s[i] == '\0' && ch == '\0')
		return ((char *)&s[i]);
	else
	{
		i--;
		while (i >= 0)
		{
			if (s[i] == ch)
				return ((char *)&s[i]);
			i--;
		}
	}
	return (NULL);
}
