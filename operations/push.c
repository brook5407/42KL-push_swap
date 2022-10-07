/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:40:54 by chchin            #+#    #+#             */
/*   Updated: 2022/07/19 10:27:54 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static void	push_top(t_stack **from, t_stack **to)
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

/* - Take the first element at the top of b and put it at the top of a.
 * - Do nothing if b is empty.
 * - print out "pb"*/
void	push_top_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	push_top(&stack_a, &stack_b);
	ft_putendl_fd("pb", 1);
}

/* - Take the first element at the top of b and put it at the top of a.
 * - Do nothing if b is empty.
 * - print out "pb"*/
void	push_top_b_to_a(t_stack *stack_b, t_stack *stack_a)
{
	push_top(&stack_b, &stack_a);
	ft_putendl_fd("pa", 1);
}
