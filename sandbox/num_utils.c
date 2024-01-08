/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:03:40 by airyago           #+#    #+#             */
/*   Updated: 2023/08/20 19:56:07 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	ft_is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\f' || c == '\r' || c == '\v');
}

bool	ft_fits_in_int(char *str)
{
	long long	num;

	num = ft_atoll(str);
	if (num < INT_MIN || num > INT_MAX)
		return (false);
	return (true);
}

bool	ft_is_digit(char c)
{
	if (ft_is_space(c))
		return (false);
	return (c >= '0' && c <= '9');
}

bool	ft_is_integer(char *str)
{
	if (*str == '-' || *str == '+')
	{
		str++;
		if (*str == '\0')
			return (false);
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

void	ft_check_sign(const char *str, int *i, bool *is_negative)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*is_negative = true;
		(*i)++;
	}
}
