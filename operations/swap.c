/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:23:19 by chchin            #+#    #+#             */
/*   Updated: 2022/07/26 22:58:31 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_top(t_stack **stack)
{
	t_node	*temp;
	t_node	*top_next;

	if ((*stack)->size < 2)
		return ;
	temp = (*stack)->top;
	top_next = (*stack)->top->next;
	if ((*stack)->size > 2)
		top_next->next->prev = (*stack)->top;
	temp->next = top_next->next;
	(*stack)->top = top_next;
	(*stack)->top->prev = NULL;
	temp->prev = (*stack)->top;
	(*stack)->top->next = temp;
	if ((*stack)->size == 2)
		(*stack)->btm = (*stack)->top->next;
}

/* - Swap the first 2 elements at the top of stack a.
 * - Do nothing if there is only one or no elements.
 * - print out "sa"*/
void	swap_stack_a(t_stack *stack_a)
{
	swap_top(&stack_a);
	ft_putendl_fd("sa", 1);
}

/* - Swap the first 2 elements at the top of stack b.
 * - Do nothing if there is only one or no elements.
 * - print out "sb"*/
void	swap_stack_b(t_stack *stack_b)
{
	swap_top(&stack_b);
	ft_putendl_fd("sb", 1);
}

/* - Swap the first 2 elements at the top of stack a & b.
 * - Do nothing if there is only one or no elements.
 * - print out "ss"*/
void	swap_stack_all(t_stack *stack_a, t_stack *stack_b)
{
	swap_top(&stack_a);
	swap_top(&stack_b);
	ft_putendl_fd("ss", 1);
}
