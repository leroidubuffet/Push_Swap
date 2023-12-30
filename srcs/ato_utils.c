/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ato_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:57:52 by airyago           #+#    #+#             */
/*   Updated: 2023/12/30 18:17:59 by airyago          ###   ########.fr       */
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
