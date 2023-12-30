/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ato.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:16:36 by airyago           #+#    #+#             */
/*   Updated: 2023/12/30 18:16:50 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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

long	ft_atol(const char *nptr)
{
	long				i;
	long				sign;
	unsigned long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_is_digit(nptr[i]))
	{
		res *= 10;
		res = res + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
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
