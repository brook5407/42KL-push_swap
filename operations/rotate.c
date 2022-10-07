/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:28:13 by chchin            #+#    #+#             */
/*   Updated: 2022/07/26 23:07:29 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_top_to_bottom(t_stack **stack)
{
	t_node	*temp;
	t_node	*top_next;

	if ((*stack)->size < 2)
		return ;
	temp = (*stack)->top;
	top_next = (*stack)->top->next;
	(*stack)->btm->next = temp;
	temp->prev = (*stack)->btm;
	temp->next = NULL;
	(*stack)->btm = temp;
	top_next->prev = NULL;
	(*stack)->top = top_next;
}

/* - Shift up all elements of stack a by 1.
 * - The first element becomes the last one.
 * - print out "ra"*/
void	rotate_stack_a(t_stack *stack_a)
{
	rotate_top_to_bottom(&stack_a);
	ft_putendl_fd("ra", 1);
}

/* - Shift up all elements of stack b by 1.
 * - The first element becomes the last one.
 * - print out "rb"*/
void	rotate_stack_b(t_stack *stack_b)
{
	rotate_top_to_bottom(&stack_b);
	ft_putendl_fd("rb", 1);
}

/* - Shift up all elements of stack a & b by 1.
 * - The first element becomes the last one.
 * - print out "rr"*/
void	rotate_stack_all(t_stack *stack_a, t_stack *stack_b)
{
	rotate_top_to_bottom(&stack_a);
	rotate_top_to_bottom(&stack_b);
	ft_putendl_fd("rr", 1);
}
