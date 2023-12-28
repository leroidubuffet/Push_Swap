/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:53:31 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/28 16:48:17 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sorts a stack with exactly two elements by swapping them.
 *
 * @param stacks - Container holding both stacks.
 */
void	ft_sort_two(t_stacks *stacks)
{
	ft_swap(stacks, 'a');
	ft_clearnodes_a(&stacks->head_a);
	exit(0);
}
