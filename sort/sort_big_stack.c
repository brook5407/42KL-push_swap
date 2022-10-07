/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:20:24 by chchin            #+#    #+#             */
/*   Updated: 2022/07/27 12:07:39 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/// - sort the array by using bubble sort method
void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

/// - return the maximum bits of the biggest number
int	find_max_bits(const t_stack *stack)
{
	int	max_bits;
	int	max;

	max_bits = 0;
	max = ft_find_max(stack->top, stack->size);
	while (max >> max_bits)
		max_bits++;
	return (max_bits);
}

/// - simplify the value in the linked list
void	simplify_stack(t_stack *stack)
{
	int		i;
	int		*arr;
	t_node	*data;

	i = 0;
	arr = malloc(sizeof(int) * stack->size + 1);
	data = stack->top;
	while (i < stack->size)
	{
		arr[i++] = data->data;
		if (data->next)
			data = data->next;
	}
	bubble_sort(arr, stack->size);
	i = 0;
	data = stack->top;
	while (data)
	{
		i = 0;
		while (data->data != arr[i])
			i++;
		data->data = i;
		data = data->next;
	}
	free(arr);
}

/// - Sort the linked list by using the radix sort method
void	radix_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	max_bits;

	i = -1;
	max_bits = find_max_bits(*a);
	while (i++, i < max_bits && correct_order(*a))
	{
		j = (*a)->size;
		while (j && correct_order(*a))
		{
			if (((*a)->top->data >> i) & 1)
				rotate_stack_a(*a);
			else if (j > 1)
				push_top_a_to_b(*a, *b);
			j--;
		}
		while ((*b)->size && !correct_order_b(*b))
			push_top_b_to_a(*b, *a);
	}
}

/// - Perform the function if the stack is over size 50
void	sort_big_stack(t_stack *stack_a, t_stack *stack_b)
{
	simplify_stack(stack_a);
	radix_sort(&stack_a, &stack_b);
	while (stack_b->size)
		push_top_b_to_a(stack_b, stack_a);
}
