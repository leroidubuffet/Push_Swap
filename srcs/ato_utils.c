/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ato_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:57:52 by airyago           #+#    #+#             */
/*   Updated: 2023/12/28 13:41:16 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Whitepace skipper helper function
void	ft_skip_whitespace(const char *str, int *i)
{
	while (ft_is_space(str[*i]))
		(*i)++;
}

// Int overflow helper function
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

// String to long long helper function
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


