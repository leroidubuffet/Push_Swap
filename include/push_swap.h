/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:12:03 by airyago           #+#    #+#             */
/*   Updated: 2023/12/27 19:10:35 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INTMAX 2147483647
# define INTMIN -2147483648

# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct t_stack
{
	int					data;
	struct t_stack		*next;
}						t_stack;

typedef struct t_stacks
{
	struct t_stack		*head_a;
	struct t_stack		*head_b;
	struct t_values		*values;
	struct t_moves		*moves;
	struct t_best		*best;
}						t_stacks;

typedef struct t_values
{
	int					max_a;
	int					min_a;
	int					max_b;
	int					min_b;
	int					size_a;
	int					size_b;
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

typedef struct t_best
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
}						t_best;

// Error Checks
void		ft_check_input(int argc, char **argv);
void		ft_check_integers(int argc, char **argv);
void		ft_check_int_size(int argc, char **argv);
void		ft_check_doubles(t_stack *head_a);

// Linked lists
t_stack		*ft_create_list(int argc, char **argv);
t_stack		*ft_newnode(int data);
void		ft_clearnodes(t_stack **lst);
t_stack		*ft_lstlast(t_stack *head);
int			ft_listsize(t_stack *head);
bool		ft_check_list_order(t_stacks *stacks);

// Sort Four & Three & Two
void		ft_sort_four(t_stacks *stacks);
void		ft_sort_three(t_stacks *stacks, int flag);
void		ft_sort_two(t_stacks *stacks);
void		ft_identify_nums_three(t_stacks *stacks, int num1, int num2, int num3);

// Sort
void		ft_sort(t_stacks *stacks);
void		ft_reorder_a(t_stacks *stacks);

// Moves Push
void		ft_push(t_stacks *stacks, char ch);
void		ft_push_a(t_stacks *stacks);
void		ft_push_b(t_stacks *stacks);
void		ft_push_empty_b(t_stacks *stacks);
void		ft_last_push_a(t_stacks *stacks);

// Moves Swap
void		ft_swap(t_stacks *stacks, char ch);
void		ft_swap_a(t_stack *head_a, int print);
void		ft_swap_b(t_stack *head_b, int print);

// Moves Rotate
void		ft_rotate(t_stacks *stacks, char ch);
void		ft_rotate_a(t_stacks *stacks, t_stack *head_a, int print);
void		ft_rotate_b(t_stacks *stacks, t_stack *head_b, int print);

// Moves Rev Rotate
void		ft_rev_rotate(t_stacks *stacks, char ch);
void		ft_rev_rotate_a(t_stacks *stacks, t_stack *head_a, int print);
void		ft_rev_rotate_b(t_stacks *stacks, t_stack *head_b, int print);

// Move best
void		ft_move_best(t_stacks *stacks);
void		ft_check_moves(t_stacks *stacks);
void		ft_update_stack_limits(t_stacks *stacks);
void		ft_run_moves(t_stacks *stacks);

// Find best
void		ft_update_stack_limits(t_stacks *stacks);
int			ft_find_index_b(t_stacks *stacks, int num);
void		ft_calc_moves_to_top(t_stacks *stacks, t_stack *head_a, int i);
void		ft_calc_move_new_num(t_stacks *stacks, int num);
int			ft_find_destination(t_stacks *stacks, int num);
void		ft_double_moves(t_stacks *stacks);
void		ft_check_cost(t_stacks *stacks, int i);

// Move Back to Stack A
void		ft_reorder_a(t_stacks *stacks);
int			ft_find_index_a(t_stacks *stacks, int num);
int			search_stack_a(t_stacks *stacks, int num);
void		ft_move_min_to_top_a(t_stacks *stacks);
void		ft_rotate_min_a(t_stacks *stacks);
void		ft_rotate_max_a(t_stacks *stacks);
void		new_elem_stack_a(t_stacks *stacks, t_stack *head_b);
void		ft_place_min_a(t_stacks *stacks);
void		do_moves_max_stack_a(t_stacks *stacks);
void		do_moves_elem_stack_a(t_stacks *stacks);
void		ft_apply_rotations_a(t_stacks *stacks);

// Check Max & Min B
void		ft_check_limits_b(t_stacks *stacks);
void		ft_check_max_b(t_stacks *stacks, t_stack *head_b);
void		ft_check_min_b(t_stacks *stacks, t_stack *head_b);

// Check Max & Min A
void		ft_check_limits_a(t_stacks *stacks);
void		ft_check_max_a(t_stacks *stacks, t_stack *head_a);
void		ft_ft_check_min_b(t_stacks *stacks, t_stack *head_a);

// Print
void		ft_error(void);

// Free
void		ft_free(t_stacks *stacks);

// Libft
size_t		ft_strlen(const char *s);
bool		ft_is_digit(char c);
bool		ft_is_space(char c);
long		ft_atol(const char *str);
void		ft_putstr(const char *str);
void		*ft_calloc(size_t count, size_t size);
int			ft_atoi(const char *str);
void		ft_bzero(void *str, size_t len);

#endif
