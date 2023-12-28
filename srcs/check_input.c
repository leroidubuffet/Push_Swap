/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:19:18 by airyago           #+#    #+#             */
/*   Updated: 2023/12/20 13:23:57 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Entry point for validating command line arguments.
 * Checks for the presence of arguments, validates integer format, and confirms within range.
 *
 * @param argc - Number of command line arguments.
 * @param argv - Array of command line arguments.
 */
void	ft_check_input(int argc, char **argv)
{
	if (argc == 1)
		exit (0);
	ft_check_integers(argc, argv);
	ft_check_int_size(argc, argv);
}

/**
 * Validates that each command line argument is a valid integer string.
 * Allows optional '+' or '-' sign at the start followed by digits.
 *
 * @param argc - Number of command line arguments.
 * @param argv - Array of command line arguments.
 */
void	ft_check_integers(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			ft_error();
		while (j < (int)ft_strlen(argv[i]))
		{
			if (!ft_is_digit(argv[i][j]))
			{
				if (j == 0 && ft_strlen(argv[i]) != 1 && \
					(argv[i][j] == '-' || argv[i][j] == '+'))
				{
					j++;
					continue ;
				}
				ft_error();
			}
			j++;
		}
		i++;
	}
}

/**
 * Validates that each argument is within the range of an int.
 * Converts the argument to a long for safe comparison.
 *
 * @param argc - Number of command line arguments.
 * @param argv - Array of command line arguments.
 */
void	ft_check_int_size(int argc, char **argv)
{
	long	num;
	int		i;

	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > INTMAX || num < INTMIN)
			ft_error();
		i++;
	}
}

/**
 * Checks for duplicate values within the stack.
 * If a duplicate is found, an error is printed, and the program exits.
 *
 * @param head - Head of the stack to be checked for duplicates.
 */
void	ft_check_doubles(t_stack *head_a)
{
	t_stack	*tmp;
	t_stack	*ptr;
	int		num;

	ptr = head_a;
	while (ptr != NULL)
	{
		tmp = ptr;
		num = tmp->data;
		tmp = tmp->next;
		while (tmp != NULL)
		{
			if (num == tmp->data)
			{
				ft_putstr("Error\n");
				ft_clearnodes(&head_a);
				exit(0);
			}
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
}
