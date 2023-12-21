/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:18:59 by airyago           #+#    #+#             */
/*   Updated: 2023/12/21 18:01:38 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RETURN VALUE: The values returned are nonzero if the character c falls into
// the tested class, and a zero value if not.

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
