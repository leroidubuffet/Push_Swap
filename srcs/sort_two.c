/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago  <airyago @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:53:31 by airyago           #+#    #+#             */
/*   Updated: 2023/08/31 13:59:34 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stacks *stacks)
{
	ft_swap(stacks, 'a');
	ft_clearnodes(&stacks->head_a);
	exit(0);
}
