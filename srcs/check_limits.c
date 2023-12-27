/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 23:04:52 by airyago           #+#    #+#             */
/*   Updated: 2023/12/27 23:20:26 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// General function to check limits of a given stack.
void ft_check_limits(t_stacks *stacks, char stack_identifier) {
    if (!stacks) return;

    t_stack *head;
    if (stack_identifier == 'a') {
        head = stacks->head_a;
        if (!head) return;  // Ensure the stack is not empty.

        ft_check_max(head, &stacks->values->max_a);
        ft_check_min(head, &stacks->values->min_a);
    } else if (stack_identifier == 'b') {
        head = stacks->head_b;
        if (!head) return;  // Ensure the stack is not empty.

        ft_check_max(head, &stacks->values->max_b);
        ft_check_min(head, &stacks->values->min_b);
    }
}

// General function to find and update the maximum value in a given stack.
void ft_check_max(t_stack *head, int *max_value) {
    if (!head || !max_value) return;

    *max_value = head->data;
    while (head) {
        if (*max_value < head->data) {
            *max_value = head->data;
        }
        head = head->next;
    }
}

// General function to find and update the minimum value in a given stack.
void ft_check_min(t_stack *head, int *min_value) {
    if (!head || !min_value) return;

    *min_value = head->data;
    while (head) {
        if (*min_value > head->data) {
            *min_value = head->data;
        }
        head = head->next;
    }
}

