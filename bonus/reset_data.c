/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 09:27:17 by chchin            #+#    #+#             */
/*   Updated: 2022/07/17 17:26:31 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	set_null_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->btm = NULL;
}

void	exit_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(0);
}

void	ft_free_list(t_stack *stack)
{
	t_node	*node;
	t_node	*temp;

	node = stack->top;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	free(stack);
}

void	ft_free_all(t_stack *a, t_stack *b)
{
	ft_free_list(a);
	ft_free_list(b);
}
