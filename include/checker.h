/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:12:03 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/28 16:48:17 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"

# define INTMAX 2147483647
# define INTMIN -2147483648

typedef struct t_stack_a
{
	int					content;
	struct t_stack_a	*next;
}						t_stack_a;

typedef struct t_stack_b
{
	int					content;
	struct t_stack_b	*next;
}						t_stack_b;

typedef struct t_stacks
{
	struct t_stack_a	*head_a;
	struct t_stack_b	*head_b;
	struct t_values		*values;
	struct t_moves		*moves;
	struct t_cheap		*cheap;
}						t_stacks;

typedef struct t_values
{
	int					max_a;
	int					min_a;
	int					max_b;
	int					min_b;
}						t_values;

typedef struct t_moves
{
	int					cost;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}						t_moves;

typedef struct t_cheap
{
	int					cost;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}						t_cheap;

void					ft_check_input(int argc, char **argv);
void					check_integers(int argc, char **argv);
void					check_int_size(int argc, char **argv);
void					ft_check_doubles(t_stack_a *head_a);
void					ft_clearnodes_a(t_stack_a **lst);
int						ft_listsize_b(t_stack_b *head);
void					print_error_and_exit_bonus(void);
t_stack_a				*ft_create_list(int argc, char **argv);
void					ft_free_bonus(t_stacks *stacks);
int						check_list_order(t_stacks *stacks);
void					free_and_exit(t_stacks *stacks, char *cmd);

//push
void					ft_push(t_stacks *stacks, char ch);
void					ft_last_push_a(t_stacks *stacks);
void					ft_push_empty_b(t_stacks *stacks);
void					ft_push_b(t_stacks *stacks);
void					ft_push_a(t_stacks *stacks);

//swap
void					ft_swap(t_stacks *stacks, char ch);
void					ft_swap_a_bonus(t_stack_a *head_a);
void					ft_swap_b_bonus(t_stack_b *head_b);

//rotate
void					ft_rotate(t_stacks *stacks, char ch);
void					ft_rotate_a_bonus(t_stacks *stacks, t_stack_a *head_a);
void					ft_rotate_b_bonus(t_stacks *stacks, t_stack_b *head_b);
t_stack_a				*ft_listlast_a(t_stack_a *head_a);
t_stack_b				*ft_listlast_b(t_stack_b *head_b);

//rev_rotate
void					ft_rev_rotate(t_stacks *stacks, char ch);
void					ft_rev_rotate_a_bonus(t_stacks *stacks,
							t_stack_a *head_a);
void					ft_rev_rotate_b_bonus(t_stacks *stacks,
							t_stack_b *head_b);

#endif
