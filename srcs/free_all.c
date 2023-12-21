/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:59:02 by airyago           #+#    #+#             */
/*   Updated: 2023/12/21 18:02:43 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stacks *stacks)
{
	ft_clearnodes(&stacks->head_a);
	ft_clearnodes(&stacks->head_b);
	free(stacks->values);
	free(stacks->moves);
	free(stacks->best);
}
