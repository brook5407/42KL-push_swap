/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:29:27 by brook             #+#    #+#             */
/*   Updated: 2022/07/25 21:29:27 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		checker(a, b);
		ft_free_all(a, b);
	}
	return (0);
}
