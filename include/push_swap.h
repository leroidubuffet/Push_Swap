/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:12:03 by ybolivar          #+#    #+#             */
/*   Updated: 2023/12/28 20:20:19 by airyago          ###   ########.fr       */
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

typedef struct	s_stack_a
{
	int					content;
	struct s_stack_a	*next;
} 				t_stack_a;

typedef struct	s_stack_b
{
	int					content;
	struct s_stack_b	*next;
}				t_stack_b;

typedef struct	s_limits
{
	int					max_a;
	int					min_a;
	int					max_b;
	int					min_b;
}				t_limits;

typedef struct	s_moves
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
}				t_moves;

typedef struct	s_best
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

typedef struct	s_stacks
{
	struct s_stack_a	*head_a;
	struct s_stack_b	*head_b;
	struct s_limits		*values;
	struct s_moves		*moves;
	struct s_best		*best;
}				t_stacks;

// Error Checks
bool		ft_check_input(int argc, char **argv);
void		ft_check_doubles(t_stack_a *head_a);

// Linked List A
t_stack_a	*ft_create_list(int argc, char **argv);
t_stack_a	*ft_newnode_a(int content);
void		ft_clearnodes_a(t_stack_a **lst);
int			ft_listsize_a(t_stack_a *lst);
t_stack_a	*ft_listlast_a(t_stack_a *head_a);

// Linked List B
t_stack_b	*ft_newnode_b(int content);
void		ft_clearnodes_b(t_stack_b **lst);
int			ft_listsize_b(t_stack_b *head);

// Sort
void		ft_sort(t_stacks *stacks);
void		ft_sort_two(t_stacks *stacks);
void		ft_sort_three(t_stacks *stacks, int flag);
void		ft_sort_four(t_stacks *stacks);
void		identify_nums_three(t_stacks *stacks, int num1, int num2, int num3);

void		move_stack_a(t_stacks *stacks);

// Push
void		ft_push(t_stacks *stacks, char ch);
void		ft_push_a(t_stacks *stacks);
void		ft_push_b(t_stacks *stacks);

// Swap
void		ft_swap(t_stacks *stacks, char ch);

// Rotate
void		ft_rotate(t_stacks *stacks, char ch);

// Rev Rotate
void		ft_rev_rotate(t_stacks *stacks, char ch);
void		ft_rev_rotate_a(t_stacks *stacks, t_stack_a *head_a, int print);
void		ft_rev_rotate_b(t_stacks *stacks, t_stack_b *head_b, int print);

// Move Cheapest
void		move_cheapest(t_stacks *stacks);
void		check_moves(t_stacks *stacks);
void		do_cheap_moves(t_stacks *stacks);

// Find Cheapest
void		ft_update_stack_limits(t_stacks *stacks);
int			find_index_stack_b(t_stacks *stacks, int nbr);
void		ft_calc_to_top(t_stacks *stacks, t_stack_a *head_a, int i);
void		ft_calc_move_new_num(t_stacks *stacks, int num);
int			search_num_stack_b(t_stacks *stacks, int nbr);

// Move Back to Stack A
void		move_stack_a(t_stacks *stacks);
int			find_index_stack_a(t_stacks *stacks, int nbr);
int			search_stack_a(t_stacks *stacks, int nbr);
void		put_in_order(t_stacks *stacks);
void		ft_calc_min_to_top(t_stacks *stacks);
void		ft_calc_max_to_top(t_stacks *stacks);
void		new_elem_stack_a(t_stacks *stacks, t_stack_b *head_b);
void		do_moves_elem_stack_a(t_stacks *stacks);
void		do_moves_order(t_stacks *stacks);

// Check Max & Min B
void		check_max_min_b(t_stacks *stacks);
void		check_max_b(t_stacks *stacks, t_stack_b *head_b);
void		check_min_b(t_stacks *stacks, t_stack_b *head_b);

// Check Max & Min A
void		ft_check_limits_a(t_stacks *stacks);

// Lists Checks
int			check_list_order(t_stacks *stacks);

// Free All
void		ft_free(t_stacks *stacks);

// Libft
bool	ft_is_space(char c);
bool	ft_is_digit(char c);
void	ft_putstr(const char *str);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
long long	ft_atoll(const char *str);
bool	ft_is_space(char c);
bool	ft_fits_in_int(char *str);
bool	ft_is_digit(char c);
bool	ft_is_integer(char *str);
void	ft_check_sign(const char *str, int *i, bool *is_negative);

void		ft_error(void);
void		ft_skip_whitespace(const char *str, int *i);
long long	ft_str_to_ll(const char *str, int *index, bool *is_negative);
bool		ft_check_overflow(long long result, char current_char, bool is_negative);

// Memory
void	*ft_calloc(size_t count, size_t size);
bool	ft_initialize_resources(t_stacks *stacks);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *str, size_t len);
void	ft_clearnodes(t_stack_a **lst); // change to stack


#endif
