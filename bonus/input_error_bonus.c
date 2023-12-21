/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:05:28 by airyago           #+#    #+#             */
/*   Updated: 2023/12/20 13:23:57 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_check_input(int argc, char **argv)
{
	if (argc == 1)
		exit(0);
	ft_check_integers(argc, argv);
	ft_check_int_size(argc, argv);
}

void	ft_check_integers(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			ft_error_bonus();
		while (j < (int)ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][j]))
			{
				if (j == 0 && ft_strlen(argv[i]) != 1 && \
					(argv[i][j] == '-' || argv[i][j] == '+'))
				{
					j++;
					continue ;
				}
				ft_error_bonus();
			}
			j++;
		}
		i++;
	}
}

void	ft_check_int_size(int argc, char **argv)
{
	long	num;
	int		i;

	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > INTMAX || num < INTMIN)
			ft_error_bonus();
		i++;
	}
}

void	ft_check_doubles(t_stack *head_a)
{
	t_stack	*tmp;
	t_stack	*ptr;
	int			num;

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
				ft_putstr_fd("Error\n", 2);
				ft_clearnodes(&head_a);
				exit(0);
			}
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
}
