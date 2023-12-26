/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ato_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:57:52 by airyago           #+#    #+#             */
/*   Updated: 2023/12/26 18:35:54 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	long long		num;
	int				sign;
	int				i;

	num = 0;
	sign = 1;
	i = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (ft_is_digit(str[i]))
	{
		if (sign > 0 && num > (INTMAX - (str[i] - '0')) / 10)
			return (INTMAX);
		else if (sign < 0 && - num < (INTMIN + (str[i] - '0')) / 10)
			return (INTMIN);
		num = num * 10 + sign * (str[i] - '0');
		i++;
	}
	return (num);
}

long	ft_atol(const char *str)
{
	long				index;
	long				sign;
	unsigned long		result;
	unsigned long		max;

	index = 0;
	sign = 1;
	result = 0;
	max = LONG_MAX / 10; // Pre-calculate to avoid repeated computation.
	while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '-' || str[index] == '+')
		sign = (str[index++] == '-') ? -1 : 1;
	while (ft_is_digit(str[index]))
	{
		if ((result > max || (result == max && str[index] > '7')) && sign == 1)
			return (LONG_MAX);
		if ((result > max || (result == max && str[index] > '8')) && sign == -1)
			return (LONG_MIN);
		result = result * 10 + (str[index++] - '0');
	}
	return (result * sign);
}

bool	ft_is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\f' || c == '\r' || c == '\v');
}

bool	ft_is_digit(char c)
{
	if (ft_is_space(c))
		return (false);
	return (c >= '0' && c <= '9');
}
