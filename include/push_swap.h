/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolivar <ybolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:21:48 by airyago           #+#    #+#             */
/*   Updated: 2024/01/02 18:53:28 by ybolivar         ###   ########.fr       */
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
# include <stdio.h> 

// ---------------------------
// Type Definitions
// ---------------------------
typedef struct s_stack_a
{
	int					content;
	struct s_stack_a	*next;
}	t_stack_a;

typedef struct s_stack_b
{
	int					content;
	struct s_stack_b	*next;
}	t_stack_b;

typedef struct s_limits
{
	int					max_a;
	int					min_a;
	int					max_b;
	int					min_b;
}	t_limits;

typedef struct s_moves
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
}	t_moves;

typedef struct s_best
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
}	t_best;

typedef struct s_stacks
{
	struct s_stack_a	*head_a;
	struct s_stack_b	*head_b;
	struct s_limits		*values;
	struct s_moves		*moves;
	struct s_best		*best;
}	t_stacks;

// ---------------------------
// Error Handling
// ---------------------------
void		ft_error(void);
bool		ft_check_input(int argc, char **argv);
void		ft_check_doubles(t_stack_a *head_a);

// ---------------------------
// Libft Functions
// ---------------------------
void		ft_putstr(const char *str);
int			ft_atoi(const char *str);
long		ft_atol(const char *str);
long long	ft_atoll(const char *str);
bool		ft_is_space(char c);
bool		ft_is_digit(char c);
bool		ft_is_integer(char *str);
bool		ft_fits_in_int(char *str);
void		ft_check_sign(const char *str, int *i, bool *is_negative);
void		ft_skip_whitespace(const char *str, int *i);
long long	ft_str_to_ll(const char *str, int *index, bool *is_negative);
bool		ft_check_overflow(long long result, char current_char,
				bool is_negative);

// ---------------------------
// Memory Management
// ---------------------------
void		*ft_calloc(size_t count, size_t size);
void		ft_clearnodes(t_stack_a **lst);
void		ft_free_stacks(t_stacks *stacks);

// ---------------------------
// Stack Initialization
// ---------------------------
void		ft_initialize_stacks(t_stacks *stacks, int argc, char **argv);
bool		ft_initialize_resources(t_stacks *stacks);

// ---------------------------
// Linked List A Operations
// ---------------------------
t_stack_a	*ft_create_list(int argc, char **argv);
t_stack_a	*ft_newnode_a(int content);
void		ft_clearnodes_a(t_stack_a **lst);
int			ft_listsize_a(t_stack_a *lst);
t_stack_a	*ft_listlast_a(t_stack_a *head_a);

// ---------------------------
// Linked List B Operations
// ---------------------------
t_stack_b	*ft_newnode_b(int content);
void		ft_clearnodes_b(t_stack_b **lst);
int			ft_listsize_b(t_stack_b *head);

// ---------------------------
// Sorting Algorithms
// ---------------------------
void		ft_sort(t_stacks *stacks);
void		ft_sort_two(t_stacks *stacks);
void		ft_sort_three(t_stacks *stacks, bool clear);
void		ft_sort_four(t_stacks *stacks);
void		ft_execute_moves_three(t_stacks *stacks, int num1,
				int num2, int num3);

// ---------------------------
// Stack Operations - Push
// ---------------------------
void		ft_push(t_stacks *stacks, char ch);
void		ft_push_a(t_stacks *stacks);
void		ft_push_b(t_stacks *stacks);

// ---------------------------
// Stack Operations - Swap
// ---------------------------
void		ft_swap(t_stacks *stacks, char ch);

// ---------------------------
// Stack Operations - Rotate
// ---------------------------
void		ft_rotate(t_stacks *stacks, char ch);

// ---------------------------
// Stack Operations - Reverse Rotate
// ---------------------------
void		ft_rev_rotate(t_stacks *stacks, char ch);
void		ft_rev_rotate_a(t_stacks *stacks, int print);
void		ft_rev_rotate_b(t_stacks *stacks, int print);

// ---------------------------
// Finding Best Moves
// ---------------------------
void		ft_move_a_to_b(t_stacks *stacks);
void		ft_find_best_sequence(t_stacks *stacks);
void		ft_update_stack_limits(t_stacks *stacks);
int			ft_find_index_b(t_stacks *stacks, int nbr);
void		ft_calc_to_top(t_stacks *stacks, t_stack_a *head_a, int i);
void		ft_place_element_b(t_stacks *stacks, int num);
int			ft_search_num_b(t_stacks *stacks, int nbr);

// ---------------------------
// Moving Back to Stack A
// ---------------------------
void		ft_best_b_to_a(t_stacks *stacks);
int			ft_find_index_stack_a(t_stacks *stacks, int nbr);
void		ft_calc_min_to_top(t_stacks *stacks);
void		ft_calc_max_to_top(t_stacks *stacks);
void		ft_place_element_a(t_stacks *stacks, t_stack_b *head_b);

// ---------------------------
// Check Limits
// ---------------------------
void		ft_check_limits_b(t_stacks *stacks);
void		ft_check_limits_a(t_stacks *stacks);


char		**ft_split(char const *s, char c);
// char static	*ft_instr(char const *s, char c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
// void static	ft_freelst(char **lst, int n);
// int static	ft_cntwrd(char const *s, char c);

#endif
