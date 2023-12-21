/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 08:13:25 by airyago           #+#    #+#             */
/*   Updated: 2023/12/21 18:01:39 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	t_args;
	int		str_len;
	int		count;
	int		i;

	if (!str)
		return (0);
	i = -1;
	count = 0;
	str_len = ft_strlen((char *)str);
	va_start(t_args, str);
	while (++i < str_len)
	{
		if (str[i] == '%')
		{
			i += 1;
			while (str[i] == '#')
				i++;
			count += convertions(str, i, t_args);
		}
		else
			count += ft_putchar(str[i]);
	}
	va_end(t_args);
	return (count);
}
