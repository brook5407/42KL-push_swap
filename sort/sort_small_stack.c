/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:31:50 by chchin            #+#    #+#             */
/*   Updated: 2022/07/27 12:07:39 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/// - Sort the stack if the size is under 4
static void	sort_under_four(t_stack *stack)
{
	while (correct_order(stack))
	{
		if (stack->top->data > stack->top->next->data
			&& stack->top->data > stack->btm->data)
			rotate_stack_a(stack);
		else if (stack->top->data > stack->top->next->data)
			swap_stack_a(stack);
		else if (stack->btm->data < stack->btm->prev->data)
			rev_rotate_stack_a(stack);
		else
			rotate_stack_a(stack);
	}
}

/// - Sort the smallest value to the top
static void	sort_min_to_top(t_stack *stack, int min)
{
	int	pos;
	int	median_pos;

	pos = ft_find_pos(stack->top, min);
	median_pos = stack->size / 2 + 1;
	if (pos <= median_pos)
	{
		while (stack->top->data != min)
			rotate_stack_a(stack);
	}
	else
	{
		while (stack->top->data != min)
			rev_rotate_stack_a(stack);
	}
}

/// - Sort the stack if the size is under 6
void	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	while (correct_order(stack_a))
	{
		if (stack_a->size < 4)
			sort_under_four(stack_a);
		else
		{
			min = ft_find_min(stack_a->top, stack_a->size);
			sort_min_to_top(stack_a, min);
			push_top_a_to_b(stack_a, stack_b);
		}
	}
	while (stack_b->size)
		push_top_b_to_a(stack_b, stack_a);
}

/// - Sort the stack if the number is under 50
static void	sort_two_min_to_top(t_stack *a, t_stack *b)
{
	int	step1;
	int	step2;

	while (correct_order(a) && a->size > 6)
	{
		step1 = ft_steps(a->top, ft_find_min(a->top, a->size), a->size);
		step2 = ft_steps(a->top, ft_find_sec_min(a->top, a->size), a->size);
		if (step2 < step1)
		{
			sort_min_to_top(a, ft_find_sec_min(a->top, a->size));
			push_top_a_to_b(a, b);
		}
		sort_min_to_top(a, ft_find_min(a->top, a->size));
		push_top_a_to_b(a, b);
		if (a->top->data > a->top->next->data && step2 < step1)
			swap_stack_all(a, b);
		else if (step2 < step1)
			swap_stack_b(b);
	}
}

void	sort_under_100(t_stack *stack_a, t_stack *stack_b)
{
	sort_two_min_to_top(stack_a, stack_b);
	sort_small_stack(stack_a, stack_b);
}
