/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:08:29 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/12/28 12:51:10 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exec_cmd(t_stacks *stacks, char *cmd)
{
	(void) stacks;
	if (!ft_strncmp(cmd, "ra\n", 3))
		ft_rotate(stacks, 'a');
	else if (!ft_strncmp(cmd, "rb\n", 3))
		ft_rotate(stacks, 'b');
	else if (!ft_strncmp(cmd, "rr\n", 3))
		ft_rotate(stacks, 'r');
	else if (!ft_strncmp(cmd, "rra\n", 4))
		ft_rev_rotate(stacks, 'a');
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		ft_rev_rotate(stacks, 'b');
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		ft_rev_rotate(stacks, 'r');
	else if (!ft_strncmp(cmd, "sa\n", 3))
		ft_swap(stacks, 'a');
	else if (!ft_strncmp(cmd, "sb\n", 3))
		ft_swap(stacks, 'b');
	else if (!ft_strncmp(cmd, "ss\n", 3))
		ft_swap(stacks, 's');
	else if (!ft_strncmp(cmd, "pa\n", 3))
		ft_push(stacks, 'a');
	else if (!ft_strncmp(cmd, "pb\n", 3))
		ft_push(stacks, 'b');
	else
		free_and_exit(stacks, cmd);
}

void	executing(t_stacks *stacks)
{
	char	*cmd;

	while (true)
	{
		cmd = get_next_line(0);
		if (cmd == NULL)
			break ;
		exec_cmd(stacks, cmd);
		free(cmd);
	}
	if (check_list_order(stacks) && ft_listsize_b(stacks->head_b) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	ft_check_input(argc, argv);
	stacks.head_a = ft_create_list(argc, argv);
	stacks.head_b = NULL;
	ft_check_doubles(stacks.head_a);
	executing(&stacks);
	ft_free_bonus(&stacks);
}
