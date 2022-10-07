/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:39:16 by chchin            #+#    #+#             */
/*   Updated: 2022/07/17 17:37:13 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

///- Return the largest value inside the linked list
int	ft_find_max(const t_node *node, int size)
{
	int	max;

	max = node->data;
	while (size--)
	{
		if (max < node->data)
			max = node->data;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (max);
}

///- Return the lowest value inside the linked list
int	ft_find_min(const t_node *node, int size)
{
	int	min;

	min = node->data;
	while (size--)
	{
		if (min > node->data)
			min = node->data;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (min);
}

///- Return the second lowest value inside the linked list
int	ft_find_sec_min(const t_node *node, int size)
{
	int	min;
	int	sec_min;

	min = ft_find_min(node, size);
	if (node->data != min)
		sec_min = node->data;
	else
		sec_min = node->next->data;
	while (size--)
	{
		if (sec_min > node->data && node->data != min)
			sec_min = node->data;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (sec_min);
}

///- Return the position of the value inside the linked list
int	ft_find_pos(t_node *node, int value)
{
	int	pos;

	pos = 1;
	while (node->data != value)
	{
		pos++;
		node = node->next;
	}
	return (pos);
}

///- Return the number of steps to move to top
int	ft_steps(t_node *node, int value, int size)
{
	int	median_pos;
	int	pos;

	median_pos = size / 2 + 1;
	pos = ft_find_pos(node, value);
	if (pos <= median_pos)
		return (pos - 1);
	else
		return (size - pos + 1);
}
