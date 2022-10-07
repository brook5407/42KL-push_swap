/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:22:31 by chchin            #+#    #+#             */
/*   Updated: 2022/07/27 12:07:39 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* - To check whether the linked list is sorted
 * - int i : the remaining size that didn't sort yet
 * - Return 0 if the linked list is sorted;
 * - Return i if the linked list is not sorted;*/
int	correct_order(t_stack *a)
{
	t_node	*list;
	int		i;

	list = a->top;
	i = a->size;
	while (list)
	{
		if (list->next)
		{
			if (list->data > list->next->data)
				return (i);
			list = list->next;
			i--;
		}
		else
			break ;
	}
	return (0);
}

/* - To check whether the stack b is sorted
 * - Return 0 if the stack b is sorted;
 * - Return 1 if the stack b is not sorted;*/
int	correct_order_b(t_stack *b)
{
	t_node	*list;
	int		i;

	list = b->btm;
	i = 0;
	while (list->data == i)
	{
		i++;
		if (!list->prev)
			return (1);
		list = list->prev;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc > 1)
	{
		a = init_stack();
		a->top = create_stack(argc, argv, &a);
		check_duplicate(a->top);
		b = init_stack();
		if (!correct_order(a))
		{
			ft_free_all(a, b);
			return (0);
		}
		if (a->size <= 50)
			sort_under_100(a, b);
		else
			sort_big_stack(a, b);
	}
	else
		return (0);
	ft_free_all(a, b);
}
