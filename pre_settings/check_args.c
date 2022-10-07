/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:28:41 by chchin            #+#    #+#             */
/*   Updated: 2022/07/26 23:34:47 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

/* - To check whether there are duplicate arguments*/
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

/* - Covert string to integer
 * - To check whether the arguments consist only integer*/
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
