/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 09:27:17 by chchin            #+#    #+#             */
/*   Updated: 2022/07/26 23:29:47 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* - allocate null list in stack*/
void	set_null_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->btm = NULL;
}

/// - print out "Error" and exit the program
void	exit_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(0);
}

/// - free the memory of every linked list inside the stack
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

/// - free the memory in stack a & b
void	ft_free_all(t_stack *a, t_stack *b)
{
	ft_free_list(a);
	ft_free_list(b);
}
