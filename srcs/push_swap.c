/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:25:34 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/29 14:11:30 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (!ft_check_input(argc, argv))
		return (1);
	ft_initialize_stacks(&stacks, argc, argv);
	ft_sort(&stacks);
	ft_free_stacks(&stacks);
	return (0);
}
