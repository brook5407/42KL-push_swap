/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:28:41 by chchin            #+#    #+#             */
/*   Updated: 2022/07/19 12:28:46 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"
#include <limits.h>

void	check_duplicate(t_node *a)
{
	int		data;
	t_node	*temp;

	while (a->next)
	{
		temp = a->next;
		data = a->data;
		while (temp)
		{
			if (temp->data == data)
				exit_error();
			temp = temp->next;
		}
		a = a->next;
	}
	while (a->prev)
		a = a->prev;
}

int	ft_atoi_check(const char *str)
{
	long	nbr;
	long	sign;

	nbr = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	if (!*str && (*(str - 1) == '-' || *(str - 1) == '+'))
		exit_error();
	while (*str)
	{
		if (!ft_isdigit(*str))
			exit_error();
		nbr = nbr * 10 + sign * (*str++ - '0');
		if (nbr > INT_MAX || nbr < INT_MIN)
			exit_error();
	}
	return ((int)nbr);
}
