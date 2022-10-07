/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:51:06 by chchin            #+#    #+#             */
/*   Updated: 2022/07/19 10:12:46 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../checker.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->size = 0;
	stack->top = NULL;
	stack->btm = NULL;
	return (stack);
}

static	t_node	*init_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

static void	connect_node(t_node **temp, t_node **node, t_stack **stack)
{
	if (!*node)
	{
		*node = *temp;
		(*stack)->top = *node;
	}
	else
	{
		(*node)->next = *temp;
		(*temp)->prev = *node;
		*node = (*node)->next;
	}
}

static int	set_node(char *argv, t_node **node, t_stack **stack)
{
	int		i;
	char	**args;
	t_node	*temp;

	args = ft_split(argv, ' ');
	if (!args || !*args)
		return (0);
	i = 0;
	while (args[i])
	{
		temp = init_node();
		temp->data = ft_atoi_check(args[i]);
		connect_node(&temp, node, stack);
		(*stack)->size++;
		free(args[i++]);
	}
	free(args);
	return (1);
}

t_node	*create_stack(int argc, char **argv, t_stack **stack)
{
	int		i;
	int		rtn;
	t_node	*node;

	i = 0;
	node = NULL;
	while (++i < argc)
	{
		rtn = set_node(argv[i], &node, stack);
		if (!rtn)
			exit_error();
	}
	if (!node->next)
		(*stack)->btm = node;
	while (node->prev)
		node = node->prev;
	return (node);
}
