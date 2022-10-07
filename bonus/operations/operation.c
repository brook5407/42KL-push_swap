/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:44:56 by brook             #+#    #+#             */
/*   Updated: 2022/07/25 21:44:56 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static void	from_size_one(t_stack **from, t_stack **to)
{
	if ((*to)->size == 0)
	{
		(*to)->top = (*from)->top;
		(*to)->btm = (*to)->top;
	}
	else
	{
		(*to)->top->prev = (*from)->top;
		(*from)->top->next = (*to)->top;
		(*to)->top = (*to)->top->prev;
	}
	(*from)->top = NULL;
	(*from)->btm = NULL;
}

void	push_top(t_stack **from, t_stack **to)
{
	if ((*from)->size == 1)
		from_size_one(from, to);
	else
	{
		if ((*to)->size == 0)
		{
			(*to)->top = (*from)->top;
			(*to)->btm = (*to)->top;
			(*from)->top = (*from)->top->next;
			(*from)->top->prev = NULL;
			(*to)->top->next = NULL;
		}
		else
		{
			(*to)->top->prev = (*from)->top;
			(*from)->top = (*from)->top->next;
			(*from)->top->prev = NULL;
			(*to)->top->prev->next = (*to)->top;
			(*to)->top = (*to)->top->prev;
		}
	}
	(*to)->size++;
	(*from)->size--;
}

void	rotate_bottom_to_top(t_stack **stack)
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

void	rotate_top_to_bottom(t_stack **stack)
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

void	swap_top(t_stack **stack)
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
