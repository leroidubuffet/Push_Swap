/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:29:09 by airyago           #+#    #+#             */
/*   Updated: 2023/12/28 18:17:14 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check argument validity
static bool	ft_is_valid_arg(char *argv)
{
	if (argv[0] == '\0')
        return (false);
	if (!ft_is_integer(argv) \
	|| !ft_fits_in_int(argv) || ft_is_space(*argv))
	{
		return (false);
	}
	return (true);
}

// Look for duplicates in input data
static bool	ft_is_duplicate(char **argv, int size, int index)
{
	int	j;

	j = index + 1;
	while (j < size)
	{
		if (ft_atoi(argv[index]) == ft_atoi(argv[j]))
			return (true);
		j++;
	}
	return (false);
}

/**
 * Entry point for validating command line arguments.
 * Checks for the presence of arguments, validates integer format,
 * and confirms within range.
 *
 * @param argc - Number of command line arguments.
 * @param argv - Array of command line arguments.
 */bool	ft_check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		return (false);
	while (i < argc)
	{
		if (!ft_is_valid_arg(argv[i]) || ft_is_duplicate(argv, argc, i))
		{
			ft_error();
			return (false);
		}
		i++;
	}
	return (true);
}
