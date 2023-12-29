/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:25:34 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/29 12:23:52 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_initialize_stacks(t_stacks *stacks, int argc, char **argv)
{
	stacks->head_a = ft_create_list(argc, argv);
	stacks->head_b = NULL;

}
int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (!ft_check_input(argc, argv))
		return (1);
	ft_initialize_stacks(&stacks, argc, argv);
	ft_sort(&stacks);
	ft_free(&stacks);
	return (0);
}
