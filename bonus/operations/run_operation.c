/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:22:04 by chchin            #+#    #+#             */
/*   Updated: 2022/07/26 09:22:06 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	run_push(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_memcmp(buf, "pa", 2))
		push_top(&b, &a);
	else if (!ft_memcmp(buf, "pb", 2))
		push_top(&a, &b);
}

void	run_swap(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_memcmp(buf, "sa", 2))
		swap_top(&a);
	else if (!ft_memcmp(buf, "sb", 2))
		swap_top(&b);
	else
	{
		swap_top(&a);
		swap_top(&b);
	}
}

void	run_rotate(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_memcmp(buf, "ra", 2))
		rotate_top_to_bottom(&a);
	else if (!ft_memcmp(buf, "rb", 2))
		rotate_top_to_bottom(&b);
	else
	{
		rotate_top_to_bottom(&a);
		rotate_top_to_bottom(&b);
	}
}

void	run_rev_rotate(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_memcmp(buf, "rra", 3))
		rotate_bottom_to_top(&a);
	else if (!ft_memcmp(buf, "rrb", 3))
		rotate_bottom_to_top(&b);
	else
	{
		rotate_bottom_to_top(&a);
		rotate_bottom_to_top(&b);
	}
}
