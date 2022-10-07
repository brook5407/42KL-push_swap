/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:40:27 by brook             #+#    #+#             */
/*   Updated: 2022/07/25 21:56:59 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

static void	check_operations(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_memcmp("rra", buf, 3) || !ft_memcmp("rrb", buf, 3)
		|| !ft_memcmp("rrr", buf, 3))
		run_rev_rotate(buf, a, b);
	else if (!ft_memcmp("pa", buf, 2) || !ft_memcmp("pb", buf, 2))
		run_push(buf, a, b);
	else if (!ft_memcmp("sa", buf, 2) || !ft_memcmp("sb", buf, 2)
		|| !ft_memcmp("sb", buf, 2))
		run_swap(buf, a, b);
	else if (!ft_memcmp("ra", buf, 2) || !ft_memcmp("rb", buf, 2)
		|| !ft_memcmp("rr", buf, 2))
		run_rotate(buf, a, b);
	else
		exit_error();
}

void	checker(t_stack *a, t_stack *b)
{
	char	*buf;

	while (1)
	{
		buf = get_next_line(STDIN_FILENO);
		if (buf == NULL)
			break ;
		check_operations(buf, a, b);
		if (!correct_order(a) && !b->size)
			break ;
		free(buf);
	}
	free(buf);
	if (!correct_order(a) && !b->size)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
}
