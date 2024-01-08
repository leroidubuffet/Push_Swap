/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ato_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:03:40 by airyago           #+#    #+#             */
/*   Updated: 2023/08/16 18:59:48 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_skip_whitespace(const char *str, int *i)
{
	while (ft_is_space(str[*i]))
		(*i)++;
}

bool	ft_check_overflow(long long result, char current_char, bool is_negative)
{
	long long	max_threshold;

	max_threshold = LLONG_MAX / 10;
	if (result > max_threshold)
		return (true);

	if (result == max_threshold)
	{
		if (is_negative && current_char - '0' == 8)
			return (false);
		if (current_char - '0' > 7)
			return (true);
	}
	return (false);
}

long long	ft_str_to_ll(const char *str, int *index, bool *is_negative)
{
	long long	result;

	result = 0;
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		if (ft_check_overflow(result, str[*index], *is_negative))
		{
			if (*is_negative)
				return (LLONG_MIN);
			else
				return (LLONG_MAX);
		}
		result = result * 10 + (str[*index] - '0');
		(*index)++;
	}

	if (*is_negative)
		result = -result;
	return (result);
}

long long	ft_atoll(const char *str)
{
	int			i;
	bool		is_negative;

	i = 0;
	is_negative = false;
	ft_skip_whitespace(str, &i);
	ft_check_sign(str, &i, &is_negative);
	return (ft_str_to_ll(str, &i, &is_negative));
}

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
		if (sign > 0 && num > (INT_MAX - (str[i] - '0')) / 10)
			return (INT_MAX);
		else if (sign < 0 && num > (INT_MIN + (str[i] - '0')) / -10)
			return (INT_MIN);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * num);
}
