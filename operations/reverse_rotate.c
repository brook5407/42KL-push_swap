/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:35:57 by chchin            #+#    #+#             */
/*   Updated: 2022/07/26 23:06:38 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_bottom_to_top(t_stack **stack)
{
	t_node	*temp;
	t_node	*btm_prev;

	if ((*stack)->size < 2)
		return ;
	temp = (*stack)->btm;
	btm_prev = (*stack)->btm->prev;
	(*stack)->top->prev = temp;
	temp->next = (*stack)->top;
	temp->prev = NULL;
	(*stack)->top = temp;
	btm_prev->next = NULL;
	(*stack)->btm = btm_prev;
}

/* - Shift down all elements of stack a by 1.
 * - The last element becomes the first one.
 * - print out "rra"*/
void	rev_rotate_stack_a(t_stack *stack_a)
{
	rotate_bottom_to_top(&stack_a);
	ft_putendl_fd("rra", 1);
}

/* - Shift down all elements of stack b by 1.
 * - The last element becomes the first one.
 * - print out "rrb"*/
void	rev_rotate_stack_b(t_stack *stack_b)
{
	rotate_bottom_to_top(&stack_b);
	ft_putendl_fd("rrb", 1);
}

/* - Shift down all elements of stack a & b by 1.
 * - The last element becomes the first one.
 * - print out "rrr"*/
void	rev_rotate_stack_all(t_stack *stack_a, t_stack *stack_b)
{
	rotate_bottom_to_top(&stack_a);
	rotate_bottom_to_top(&stack_b);
	ft_putendl_fd("rrr", 1);
}
